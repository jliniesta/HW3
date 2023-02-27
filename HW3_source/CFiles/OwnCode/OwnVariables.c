// Controller variables
const double h = 1;
double R_true = 0.1001405119340;
double L_true = 0.5052864456892;
// Max Kpsi values from task 5 and task 7 calculations divided by error to minimize oscillation
float Kpsi_error_t6 = 2;
float Kpsi_error_t8 = 2;
float Kpsi_task6 = (2*L_true)/(R_true*h*Kpsi_error_t6);
float Kpsi_task8_9 = 2/(R_true*h*Kpsi_error_t8);
float w = 0;
float v = 0;
float thetaR = 0;
float pi = 3.14159265359;
// Controller error
float error_theta = 0;
float vc = 0;
float error_xg = 0;
float error_yg = 0;
float error_x0 = 0;
float error_y0 = 0;
// Task variable
int task = 0;
