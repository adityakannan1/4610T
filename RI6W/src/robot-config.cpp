#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor rightMotorsMotorA = motor(PORT1, ratio6_1, true);
motor rightMotorsMotorB = motor(PORT2, ratio6_1, true);
motor_group rightMotors = motor_group(rightMotorsMotorA, rightMotorsMotorB);
motor leftMotorsMotorA = motor(PORT3, ratio6_1, false);
motor leftMotorsMotorB = motor(PORT4, ratio6_1, false);
motor_group leftMotors = motor_group(leftMotorsMotorA, leftMotorsMotorB);
motor arm = motor(PORT5, ratio18_1, false);
motor claw = motor(PORT6, ratio18_1, false);
controller Controller1 = controller(primary);
digital_out MogoMech = digital_out(Brain.ThreeWirePort.A);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}