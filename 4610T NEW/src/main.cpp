#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// rightFrontMotor      motor         5               
// leftFrontMotor       motor         6               
// rightBackMotor       motor         7               
// leftBackMotor        motor         8               
// Controller1          controller                    
// intake               motor         9               
// cata                 motor         13              
// pistonR              digital_out   G               
// pistonL              digital_out   H               
// InertialA            inertial      12              
// hang                 motor_group   18, 19          
// ratchet              motor         17              
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;

//vex initialization
Drive chassis(ZERO_TRACKER_ODOM,motor_group(leftFrontMotor,leftBackMotor),motor_group(rightFrontMotor,rightBackMotor),PORT12,4.125,0.66,360,PORT1,-PORT2,PORT3,-PORT4,3,2.75,6,1,-2.75,5.5);

int current_auton_selection = 4;
bool auto_started = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  while(auto_started == false){          
    Brain.Screen.clearScreen();            
    switch(current_auton_selection){       
      case 1:
        Brain.Screen.printAt(50, 50, "Far Side Quals");
        break;
      case 2:
        Brain.Screen.printAt(50, 50, "Close Side");
        break;
      case 3:
        Brain.Screen.printAt(50, 50, "Programming Skills");
        break;
      case 4:
        Brain.Screen.printAt(50, 50, "Far Side Elims");
        break;
      case 5:
        Brain.Screen.printAt(50, 50, "Odom Test");
        break;
      case 6:
        Brain.Screen.printAt(50, 50, "Tank Odom Test");
        break;
      case 7:
        Brain.Screen.printAt(50, 50, "Holonomic Odom Test");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 1;
    }
    task::sleep(10);
  }
}

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){       
    case 1:         //Tap the screen to cycle through autons.
      farSideQuals();
      break;
    case 2:
      closeSide();
      break;
    case 3:
      skillsProgramming();
      break;
    case 4:
      farSideElims();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
}














/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {

  // User control code here, inside the loop
  while (1) {

   
   
   
   //intake
  
   if (Controller1.ButtonL1.pressing()) {
     intake.spin(forward, 100, percent);
   }
   else if (Controller1.ButtonL2.pressing()) {
     intake.spin(reverse, 100, percent);
   }
   else {
     intake.stop(coast);
   }


   //cata

  
   if (Controller1.ButtonA.pressing()) {
     cata.spin(forward, 100, percent);
   }else if (Controller1.ButtonX.pressing()){
     cata.stop();
   }

  


   //pullups


   if (Controller1.ButtonUp.pressing()) {
    hang.spin(forward,100,pct);
   }else if(Controller1.ButtonDown.pressing()){
    hang.spin(reverse,100,pct);
   }else{
    hang.setStopping(hold);
    hang.stop();
   }
   if(Controller1.ButtonLeft.pressing()){
    ratchet.spin(forward,25,pct);
   }else if(Controller1.ButtonRight.pressing()){
    ratchet.spin(reverse,25,pct);
   }else{
    ratchet.setStopping(hold);
    ratchet.stop();
   }


   //wings


   if (Controller1.ButtonR1.PRESSED) {
     pistonR.set(true);
     pistonL.set(true);
   }
  


   if (Controller1.ButtonR2.PRESSED) {
     pistonL.set(false);
     pistonR.set(false);
   }
   leftFrontMotor.spin(forward, (Controller1.Axis3.value() + (Controller1.Axis1.value())), percent);
   leftBackMotor.spin(forward, (Controller1.Axis3.value() + (Controller1.Axis1.value())), percent);
   rightFrontMotor.spin(forward, (Controller1.Axis3.value() - (Controller1.Axis1.value())), percent);
   rightBackMotor.spin(forward, (Controller1.Axis3.value() - (Controller1.Axis1.value())), percent);
 

   wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
