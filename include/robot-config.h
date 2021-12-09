using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LFM;
extern motor LRM;
extern motor RFM;
extern motor RRM;
extern limit LS1;
extern limit LS2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
