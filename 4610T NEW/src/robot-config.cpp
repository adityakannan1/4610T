#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor rightFrontMotor = motor(PORT5, ratio6_1, false);
motor leftFrontMotor = motor(PORT6, ratio6_1, true);
motor rightBackMotor = motor(PORT7, ratio6_1, false);
motor leftBackMotor = motor(PORT8, ratio6_1, true);
controller Controller1 = controller(primary);
motor intake = motor(PORT9, ratio18_1, false);
motor cata = motor(PORT13, ratio36_1, false);
digital_out pistonR = digital_out(Brain.ThreeWirePort.G);
digital_out pistonL = digital_out(Brain.ThreeWirePort.H);
inertial InertialA = inertial(PORT12);
motor hangMotorA = motor(PORT18, ratio36_1, true);
motor hangMotorB = motor(PORT19, ratio36_1, false);
motor_group hang = motor_group(hangMotorA, hangMotorB);
motor ratchet = motor(PORT17, ratio18_1, false);
rotation cataPos = rotation(PORT15,true);
distance cataDist = distance(PORT16);
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