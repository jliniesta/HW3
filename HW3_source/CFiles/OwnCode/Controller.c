// rotation controller

// Initialize which task to complete: 
// task = 1: Task 6
// task = 2: Task 8 or Task 9

// set controller state
theta_g = atan2(yg-y0,xg-x0);
diffDeg = std::abs(theta_g*(180/pi)-theta);
distToInitial = sqrt((x-x0)^2+(y-y0)^2);
distToGoal = sqrt((x-xg)^2+(y-yg)^2);



if(diffDeg < eps1){ // change from rotational controller to line-following
    q_state = 2;
}
else if( diffDeg > eps2){ // change back to rotational controller
    q_state = 1;
}

Serial.print(q_state);

if(distToGoal < eps3)
{
    // Serial.print("Goal reached!");
    send_done();
}

// Serial.print(q_state);



//
// TASK 6
// rotation controller
theta_g = atan2(yg-y0,xg-x0);

if(q_state == 1){
    Kpsi_task6 = 0.5/(0.1*h);
    Kpsi_task8_9 = 1/(0.1*h);
    // Calculate error when v=0

    //theta_g = atan2(yg-y0,xg-x0);
    thetaR = theta_g*(180/pi); //atan2(error_yk,error_xk)*(180/pi);
    error_theta = thetaR - theta;
    w = Kpsi_task6 * error_theta;
    //v = 0;


    // 
    // Task 8 or Task 9
    //Kpsi_task8_9 = 2/(0.1*h);
    //w = 0;
    error_x0 = x0 - x;
    error_y0 = y0 - y;
    error_v0 = (cos(theta*pi/180)*error_x0) + (sin(theta*pi/180)*error_y0);
    v = Kpsi_task8_9 * error_v0;

    // Serial.print(v);
    // Serial.print(w);
}
// line-following controller
else if(q_state == 2){
    Kw = 1/(0.1*h);
    deltaX = (xg - x); 
    deltaY = (yg - y); 
    dg = cos(theta_g)*deltaX + sin(theta_g)*deltaY;
    v = Kw*dg;
    
  

    // // Update right and left
    // right = ((2*v) + w) / 2;
    // left = ((2*v) - w) / 2;

    dp = sin(theta_g)*((x-x0)+p*cos(theta*pi/180)) - cos(theta_g)*((y-y0)+p*sin(theta*pi/180));

    if(abs(dp)>1.2){
        v=v/5;
    }
    // // K_phi = L_true/(p*R_true*h);
    K_phi = 0.5/(p*0.1*h);
    w = K_phi*dp*(180/pi);

}
// update right and left control variables
right = v + w/2;
left = v - w/2;







// theta_g = atan2(yg-y0,xg-x0);

// diffDeg = std::abs(theta_g*(180/pi)-theta);
// if(diffDeg < eps1){ // change from rotational controller to line-following
//     q_state = 2;
// }
// else if( diffDeg > eps2){ // change back to rotational controller
//     q_state = 1;
// }
// Serial.print(q_state);


// //Kw = 1/(R_true*h);
// Kw = 1/(0.1*h);
// deltaX = (xg - x); // convert to meters
// deltaY = (yg - y); // convert to meters
// dg = cos(theta_g)*deltaX + sin(theta_g)*deltaY;
// v = Kw*dg;

// //Serial.print(Kw);

// theta_g = atan2(yg-y0,xg-x0);
// dp = sin(theta_g)*((x-x0)+p*cos(theta*pi/180)) - cos(theta_g)*((y-y0)+p*sin(theta*pi/180));

// // K_phi = L_true/(p*R_true*h);
// K_phi = 0.5/(p*0.1*h);
// w = K_phi*dp*(180/pi);

// //v =0;


// right = v/4 + w/2;
// left = v/4 - w/2;