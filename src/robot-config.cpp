#include "vex.h"

using namespace vex;


// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LFM = motor(PORT7, ratio18_1, false);
motor LRM = motor(PORT9, ratio18_1, false);
motor RFM = motor(PORT11, ratio18_1, false);
motor RRM = motor(PORT2, ratio18_1, false);
motor AM1 = motor(PORT20, ratio18_1, false);
motor AM2 = motor(PORT18, ratio18_1, true);
motor CM1 = motor(PORT17, ratio6_1, false);
motor CM2 = motor(PORT19, ratio18_1, false);
limit LS1 = limit(Brain.ThreeWirePort.A);
limit LS2 = limit(Brain.ThreeWirePort.B);

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
