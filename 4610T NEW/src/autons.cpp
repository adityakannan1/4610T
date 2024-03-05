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

void farSide(){/*
  chassis.set_heading(0);
  thread distance(controllerScreen);
  chassis.drive_distance();
  chassis.turn_to_angle(90);
  intake.spin(reverse,100,pct);
  chassis.drive_distance();
  chassis.drive_distance();
  chassis.turn_to_angle(180);
  intake.spin(forward,100,pct);
  chassis.drive_distance();
  chassis.turn_to_angle();
  chassis.drive_distance();
  pistonL.set(true);
  chassis.turn_to_angle(90);
  chassis.drive_distance();
  chassis.drive_distance();
  chassis.turn_to_angle(45);
  chassis.drive_distance();
  hang.spinFor(3,sec);
*/
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
  cataSpinFor(44);
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

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
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
