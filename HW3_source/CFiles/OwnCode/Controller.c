// Initialize which task to complete: 
// task = 1: Task 6
// task = 2: Task 8
// task = 3: Task 9
task = 3;
error_xg = xg - x;
error_yg = yg - y;
//
// TASK 6
//
if (task == 1)
{
    // Calculate w when v=0
    thetaR = atan2(error_yg,error_xg)*(180/pi);
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
// Task 8
//
else if (task == 2) 
{
    // Calculate v when w=0
    w = 0;
    error_x0 = (x0 - x);
	error_y0 = (y0 - y);
	vc = (cos(theta*pi/180)*error_x0) + (sin(theta*pi/180)*error_y0);
	v = (Kpsi_task8_9 * vc) / 100;
}

//
// Task 9
//
else if (task == 3) 
{
    // Calculate w
    thetaR = atan2(error_yg/100,error_xg/100)*(180/pi);
    if ((thetaR == -180 || thetaR == 180) && (theta == 180 || theta == -179 || theta == 179)) 
    {
        w = 0;
    }
    else 
    {
        error_theta = thetaR - theta;
        w = Kpsi_task6 * error_theta;
    }
    // Calculate v
    error_x0 = (x0 - x);
	error_y0 = (y0 - y);
	vc = (cos(theta*pi/180)*error_x0) + (sin(theta*pi/180)*error_y0);
	v = (Kpsi_task8_9 * vc) / 100;
}

// Update right and left
right = ((2*v) + w) / 2;
left = ((2*v) - w) / 2;
