using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LFM;
extern motor LRM;
extern motor RFM;
extern motor RRM;
extern motor AM1;
extern motor AM2;
extern motor CM1;
extern motor CM2;
extern limit LS1;
extern limit LS2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
