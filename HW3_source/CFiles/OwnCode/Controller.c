// Initialize which task to complete: 
// task = 1: Task 6
// task = 2: Task 8 or Task 9
task = 1;
error_xk = xg - x0;
error_yk = yg - y0;
//
// TASK 6
//
if (task == 1)
{
    // Calculate error when v=0
    thetaR = atan2(error_yk,error_xk)*(180/pi);
    if ((thetaR == -180 || thetaR == 180) && (theta == 180 || theta == -179 || theta == 179)) 
    {
        w = 0;
        v = 0;
    }
    else 
    {
        error_theta = thetaR - theta;
        w = Kpsi_task6 * error_theta;
        v = 0;
    }
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
