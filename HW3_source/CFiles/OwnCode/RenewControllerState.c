// reset x0, y0
// distToGoal = (x-xg)^2 + (y-yg)^2;
// if(q_state == 2 && distToGoal < 5){
//     q_state = 1;
// }
q_state = 1;
Serial.print(q_state);

// Serial.print("RENEW STATE!!");


// theta_g = atan2(yg-y0,xg-x0);


// // change discrete state based on theta
// Serial.print(theta);
// diffDeg = std::abs(theta_g*(180/pi)-theta);

// if(diffDeg < eps1){ // change from rotational controller to line-following
//     q_state = 2;
// }
// else if( diffDeg > eps2){ // change back to rotational controller
//     q_state = 1;
// }


//Serial.print(diffDeg);