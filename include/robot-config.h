using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LFM;
extern motor LRM;
extern motor RFM;
extern motor RRM;
extern motor VM;
extern motor SM;
extern motor FL1;
extern motor FL2;
extern limit LS1;
extern limit LS2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
