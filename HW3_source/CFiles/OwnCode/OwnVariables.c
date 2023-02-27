/*
int x 
int y
int theta
int x0
int y0
int xg
int yg

int left
int right
*/
float v = 0;
float w = 0;
//from the log we can see that
float h = 1;

//int w_sampling = 50;//in hz
float theta_g = 0;
float Kw = 0;
float dg = 0;
float R = 0.38;
float deltaX = 0;
float deltaY = 0;
// double R_true = 0.1001405119340;
// double L_true = 0.5052864456892;
float p = 70;
float K_phi = 0;
float dp = 0;
float pi = 3.14159265359;

// define discrete controller state
int q_state = 1;
double eps1 = 10;
double eps2 = 60;
double eps3 = 5;
double diffDeg = 0;
float Kpsi_task6 = 0;
float Kpsi_task8_9 = 0;
float distToInitial = 0;

float error_theta = 0;
float error_v0 = 0;
float error_x0 = 0;
float error_y0 = 0;
float error_xk = 0;
float error_yk = 0;
float thetaR = 0;
// Task variable
int task = 0;
float distToGoal = 0;

