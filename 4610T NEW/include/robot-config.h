using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor rightFrontMotor;
extern motor leftFrontMotor;
extern motor rightBackMotor;
extern motor leftBackMotor;
extern controller Controller1;
extern motor intake;
extern motor cata;
extern digital_out pistonR;
extern digital_out pistonL;
extern inertial InertialA;
extern motor_group hang;
extern motor hangMotorA;
extern motor hangMotorB;
extern motor ratchet;
extern distance cataDist;
extern rotation cataPos;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );