/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       WMC Programmers                                           */
/*    Created:      Thu Sep 30 2021                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LFM                  motor         7               
// LRM                  motor         9               
// RFM                  motor         11               
// RRM                  motor         2 
// AM1                  motor         20
// AM2                  motor         18
// CM1                  motor         17
// CM2                  motor         19
// LS1                  limit         A
// LS2                  limit         B
// P1                   pneumatics    C
// P2                   pneumatics    D
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
//#include <cmath>
using namespace vex;
// A global instance of competition
competition Competition;


//Function declaration

//stop functions
void StopAll(){
  LFM.stop(hold);
  LRM.stop(hold);
  RFM.stop(hold);
  RRM.stop(hold);
  AM1.stop(hold);
  AM2.stop(hold);
  CM1.stop(hold);
  CM2.stop(hold);
}
  void StopAllArm(){
  AM1.stop(hold);
  AM2.stop(hold);
  CM1.stop(hold);
  CM2.stop(hold);
}
  void StopAllChasis(){
  LFM.stop(hold);
  LRM.stop(hold);
  RFM.stop(hold);
  RRM.stop(hold);
}
void pre_auton(void){
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //Sets all motors
  LFM.setPosition(0, degrees);
  LRM.setPosition(0, degrees);
  RFM.setPosition(0, degrees);
  RRM.setPosition(0, degrees);
  AM1.setPosition(0, degrees);
  AM2.setPosition(0, degrees);
  CM1.setPosition(0, degrees);
  CM2.setPosition(0, degrees);
  LFM.setVelocity(100, percent);
  LRM.setVelocity(100, percent);
  RFM.setVelocity(100, percent);
  RRM.setVelocity(100, percent);
  AM1.setVelocity(50, percent);
  AM2.setVelocity(50, percent);
  CM1.setVelocity(100, percent);
  CM2.setVelocity(50, percent);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void){

  //Autonomous route selection
  int route = (LS1.value() * 1) + (LS2.value() * 2);

  switch(route){
    case 0:
      StopAll();
    break;
    case 1:
      //pick up alliance tower
        //move forward
        //grab alliance tower
        //load rings?
        //move back
        //lift onto platform?
      LFM.spinFor(950, degrees),
      RFM.spinFor(950, degrees),
      LRM.spinFor(950, degrees),
      RRM.spinFor(950, degrees);
      P1.open();
      P2.open();
      LFM.spinFor(-900, degrees),
      RFM.spinFor(-900, degrees),
      LRM.spinFor(-900, degrees),
      RRM.spinFor(-900, degrees);
    break;
    case 2:
      //ram neutral tower
        //move forard
        //grab neutral tower
        //reverse
        //lift onto platform?
      LFM.spinFor(2014, degrees),
      RFM.spinFor(2014, degrees),
      LRM.spinFor(2014, degrees),
      RRM.spinFor(2014, degrees);
      P1.open();
      P2.open();
      LFM.spinFor(-1500, degrees),
      RFM.spinFor(-1500, degrees),
      LRM.spinFor(-1500, degrees),
      RRM.spinFor(-1500, degrees);
    break;
    case 3:
      
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

void usercontrol(void){

  //initialization
  StopAll();

  while(1){

    //Screen printing
    Controller1.Screen.clearLine();
    Controller1.Screen.print(CM2.position(degrees));

    //X-Drive Controlling
    LFM.spin(forward, (((-Controller1.Axis3.value()) - Controller1.Axis4.value() - Controller1.Axis1.value())), percent);
    LRM.spin(forward, (((-Controller1.Axis3.value()) + Controller1.Axis4.value() - Controller1.Axis1.value())), percent);
    RFM.spin(forward, ((Controller1.Axis3.value() - Controller1.Axis4.value() -  Controller1.Axis1.value())), percent);
    RRM.spin(forward, ((Controller1.Axis3.value() + Controller1.Axis4.value() -  Controller1.Axis1.value())), percent);
    //Velocity tapering and button control
    if(Controller1.ButtonR1.pressing()){
      AM1.spin(forward);
    }
    else{
      AM1.stop(hold);
    }

    if(Controller1.ButtonR2.pressing()){
      AM1.spin(reverse);
    }
    else{
      AM1.stop(hold);
    }

    if(Controller1.ButtonL1.pressing()){
      AM2.spin(forward);
    }
    else{
      AM2.stop(hold);
    }

    if(Controller1.ButtonL2.pressing()){
      AM2.spin(reverse);
    }
    else{
      AM2.stop(hold);
    }

    if(Controller1.ButtonUp.pressing()){
      CM1.spin(forward);
    }
    else{
      CM1.stop(hold);
    }

    if(Controller1.ButtonDown.pressing()){
      CM1.spin(reverse);
    }
    else{
      CM1.stop(hold);
    }

    if(Controller1.ButtonLeft.pressing() && CM2.position(degrees) <= 900){
      CM2.spin(forward);
    }
    else{
      CM2.stop(hold);
    }

    if(Controller1.ButtonRight.pressing() && CM2.position(degrees) >= -900){
      CM2.spin(reverse);
    }
    else{
      CM2.stop(hold);
    }
    if(Controller1.ButtonA.pressing()){
      P1.open();
      P2.open();
    }
    else if(Controller1.ButtonB.pressing()){
      P1.close();
      P2.close();
    }
  }
  wait(20, msec); // Sleep the task for a short amount of time toc prevent wasted resources.
}
int main(){ // Main will set up the competition functions and callbacks.

  Competition.autonomous(autonomous); // Set up callbacks for autonomous and driver control periods.
  Competition.drivercontrol(usercontrol);
  pre_auton(); // Run the pre-autonomous function.
  
  while(true){ // Prevent main from exiting with an infinite loop.
    wait(100, msec);
  }
}
