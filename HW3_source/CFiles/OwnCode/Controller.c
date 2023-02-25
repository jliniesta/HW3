// Initialize which task to complete: 
// task = 1: Task 6
// task = 2: Task 8 or Task 9
task = 1;

//
// TASK 6
//
if (task == 1)
{
    // Calculate error when v=0
    thetaR = atan2(error_yk,error_xk)*(180/pi);
    error_theta = thetaR - theta;
    w = Kpsi_task6 * error_theta;
    v = 0;
}

// 
// Task 8 or Task 9
//
else if (task == 2) 
{
    // Calculate error when w=0
    thetaR = atan2(error_yk,error_xk)*(180/pi);
    error_theta = thetaR - theta;
    w = 0;
    error_x0 = x0 - x;
	error_y0 = y0 - y;
	error_v0 = (cos(theta*pi/180)*error_x0) + (sin(theta*pi/180)*error_y0);
	v = Kpsi_task8_9 * error_v0;
}

// Update right and left
right = ((2*v) + w) / 2;
left = ((2*v) - w) / 2;