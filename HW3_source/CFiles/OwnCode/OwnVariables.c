// Controller variables
const double h = 1;
double R_true = 0.1001405119340;
double L_true = 0.5052864456892;
// Max Kpsi values from task 5 and task 7 calculations divided by error to minimize oscillation
double Kpsi_min_error = 2;
double Kpsi_task6 = 5; //(2*L_true)/(R_true*h*Kpsi_min_error);
double Kpsi_task8_9 = 2/(R_true*h*Kpsi_min_error);
float w = 0;
float v = 0;
float thetaR = 0;
float pi = 3.14159265359;
// Controller error
float error_theta = 0;
float error_v0 = 0;
float error_x0 = 0;
float error_y0 = 0;
float error_xk = 0;
float error_yk = 0;
// Task variable
int task = 0;
