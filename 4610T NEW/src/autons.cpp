#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 15);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);

  //Nichols PID.6,.5,.125
}



void controllerScreen(){
  while(true){
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("InertialA: %f",InertialA.rotation(degrees));
    
  }
  
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}
void hangtwo(){
  hang.spinFor(2.75,sec);
}
void farSideQuals(){
  chassis.drive_distance(50);
  chassis.turn_to_angle(90);
  intake.spin(reverse,100,pct);
  wait(.25,sec);
  chassis.drive_distance(6.5);
  chassis.turn_to_angle(-115);
  intake.spin(forward,100,pct);
  chassis.drive_distance(27);
  chassis.turn_to_angle(20);
  chassis.drive_distance(9);
  pistonL.set(true);
  chassis.turn_to_angle(90);
  thread h(hangtwo);
  chassis.drive_distance(16);
  intake.spin(reverse,100,pct);
  chassis.drive_distance(8.5);
  chassis.drive_distance(-5);
  chassis.turn_to_angle(45);
  chassis.drive_distance(-35);
}
void pistl(){
  pistonL.set(true);
}
void closeSide(){
  InertialA.resetHeading();
  chassis.set_heading(0);
  thread n(controllerScreen);
  thread p(pistl);
  wait(.5,sec);
  chassis.turn_to_angle(330);
  chassis.drive_distance(-13);
  pistonL.set(false);
  chassis.drive_distance(-20);
  hang.spinFor(3.5,sec);
}
void skillsProgramming(){
  InertialA.resetHeading();
  chassis.set_heading(0);
  thread a(controllerScreen);
  chassis.drive_distance(-33);
  chassis.drive_distance(17);
  chassis.turn_to_angle(94);
  chassis.drive_distance(3);
  pistonL.set(true);
  cata.spin(forward,100,pct);
  wait(30,sec);
  cata.stop();
  pistonL.set(false);
  chassis.turn_to_angle(130);
  chassis.drive_distance(-40);
  chassis.turn_to_angle(117);
  chassis.drive_distance(-50);
  chassis.left_swing_to_angle(70);
  chassis.drive_distance(-24);
  chassis.turn_to_angle(40);
  chassis.drive_distance(-12); 
  chassis.left_swing_to_angle(145);
  chassis.drive_distance(20);
  pistonL.set(true);
  pistonR.set(true);
  chassis.left_swing_to_angle(290);
  chassis.set_drive_constants(10,4,0,0,0);
  chassis.drive_distance(15);
  chassis.drive_distance(-15);
  chassis.drive_distance(20);
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  pistonL.set(false);
  pistonR.set(false);
  chassis.drive_distance(-15);
  chassis.turn_to_angle(220);
  chassis.drive_distance(5);
  pistonL.set(true);
  pistonR.set(true);
  chassis.left_swing_to_angle(290);
  chassis.drive_distance(10);



}

void farSideElims(){
  chassis.drive_distance(50);
  chassis.turn_to_angle(90);
  intake.spin(reverse,100,pct);
  wait(.25,sec);
  chassis.drive_distance(6.5);
  chassis.turn_to_angle(-115);
  intake.spin(forward,100,pct);
  chassis.drive_distance(27);
  chassis.turn_to_angle(20);
  chassis.drive_distance(9);
  chassis.turn_to_angle(90);
  pistonL.set(true);
  chassis.drive_distance(16);
  intake.spin(reverse,100,pct);
  chassis.drive_distance(8.5);
  pistonL.set(false);
  chassis.drive_distance(-5);
  intake.spin(forward,100,pct);
  chassis.turn_to_angle(-72);
  chassis.drive_distance(34);
  chassis.turn_to_angle(90);
  chassis.drive_distance(20);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);

}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}
