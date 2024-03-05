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


Drive chassis(

//Specify your drive setup below. There are seven options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
ZERO_TRACKER_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(leftFrontMotor,leftBackMotor),

//Right Motors:
motor_group(rightFrontMotor,rightBackMotor),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT12,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
4.125,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.66,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
6,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 3;
bool auto_started = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  while(auto_started == false){            //Changing the names below will only change their names on the
    Brain.Screen.clearScreen();            //brain screen for auton selection.
    switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
      case 1:
        Brain.Screen.printAt(50, 50, "Far Side");
        break;
      case 2:
        Brain.Screen.printAt(50, 50, "Close Side");
        break;
      case 3:
        Brain.Screen.printAt(50, 50, "Swing Test");
        break;
      case 4:
        Brain.Screen.printAt(50, 50, "Full Test");
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
      farSide();
      break;
    case 2:
      closeSide();
      break;
    case 3:
      skillsProgramming();
      break;
    case 4:
      full_test();
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

  
   thread c(cataSpin);

  
  


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
    ratchet.spin(reverse,100,pct);
   }else if(Controller1.ButtonRight.pressing()){
    ratchet.spinToPosition(0,deg);
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
