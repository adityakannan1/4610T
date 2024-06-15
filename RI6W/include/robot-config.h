using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor_group rightMotors;
extern motor_group leftMotors;
extern motor arm;
extern motor claw;
extern controller Controller1;
extern digital_out MogoMech;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );