%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Hybrid and Embedded control systems
% Homework 3
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initialization
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear
task6_pos_log = readtable("pos_log_5-9-7_task6.csv");
task8_pos_log = readtable("task8_final.csv");
task8_pos_log_no_move = readtable("task8_w=0.csv");
task9 = readtable("task9.csv");
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Task 6
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Plot theta over timestamp during rotation
timestamp = task6_pos_log{:,"timestamp"};
theta = task6_pos_log{:,"theta"};
figure
ylabel('Theta (degrees)')       
plot(timestamp, theta, 'LineWidth', 3)
xlabel('Timestamp (ms)')
grid on
title('Rotation Control Simulation Evaluation of Theta')
% Plot theta error to goal node over timestamp during rotation
thetaR = -135.162598802417;
figure
plot(timestamp, thetaR - theta, 'LineWidth', 3)
ylim([-100 10])
xlabel('Timestamp (ms)')
ylabel('Theta Error (degrees)')
grid on
title('Rotation Control Simulation Evaluation of Theta Error')
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Task 8
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Plot x and y over timestamp during movement
timestamp = task8_pos_log{:,"timestamp"};
x = task8_pos_log{:,"x"};
y = task8_pos_log{:,"y"};
figure      
plot(timestamp, y, 'color','red', 'LineWidth', 3)
hold on
plot(timestamp, x, 'color','blue', 'LineWidth', 3)
hold off
ylabel('Position (mm)') 
xlabel('Timestamp (ms)')
legend('y[k]', 'x[k]', 'Location', 'best')
grid on
title('Rotation Control Simulation Evaluation of Position')
% Plot robot's distance from final node 3 during movement
node3_x = 2.1884;
node3_y = 2.0382;
dist_x = node3_x - x;
dist_y = node3_y - y;
figure      
plot(timestamp, dist_y, 'color', 'red', 'LineWidth', 3)
ylim([-1 4])
hold on
plot(timestamp, dist_x, 'color','blue', 'LineWidth', 3)
hold off
ylabel('Position Error (mm)') 
xlabel('Timestamp (ms)')
legend('y[k]', 'x[k]', 'Location', 'best')
grid on
title('Rotation Control Simulation Evaluation of Position Error')
% Plot d0[k]
theta8 = task8_pos_log{:,"theta"};
error_xk = dist_x;
error_yk = dist_y;
d0 = (cos(theta8*pi/180).*error_xk) + (sin(theta8*pi/180).*error_yk);
figure      
plot(timestamp, d0, 'color', 'blue', 'LineWidth', 3)
ylim([-1 4])
ylabel('d0[k] (mm)') 
xlabel('Timestamp (ms)')
legend('d0[k]', 'Location', 'best')
grid on
title('Rotation Control Simulation Evaluation of d0[k]')
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Task 9
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Plot theta error
timestamp9 = task9{:,"timestamp"};
theta9 = task9{:,"theta"};
thetaR9 = 180;
figure      
plot(timestamp9, thetaR9 - theta9, 'LineWidth', 3)
ylabel('Theta (degrees)') 
xlabel('Timestamp (ms)')
ylim([-10 190])
legend('Theta[k]', 'Location', 'best')
grid on
title('Simultaneous Control Evaluation of Theta')
% Plot d0 error
x9 = task9{:,"x"};
y9 = task9{:,"y"};
goalx = -0.7346;
goaly = 2.0382;
error_x9 = goalx - x9;
error_y9 = goaly - y9;
d09 = (cos(theta9*pi/180).*error_x9) + (sin(theta9*pi/180).*error_y9);
figure      
plot(timestamp9, d09, 'LineWidth', 3)
ylabel('d0[k] (cm)') 
xlabel('Timestamp (ms)')
legend('d0[k]', 'Location', 'best')
grid on
title('Simultaneous Control Evaluation of d0[k]')
