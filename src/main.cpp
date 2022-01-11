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
// LFM                  motor         1               
// LRM                  motor         2               
// RFM                  motor         3               
// RRM                  motor         4 
// AM1                  motor         5
// AM2                  motor         6
// CM1                  motor         7
// CM2                  motor         8
// LS1                  limit         A
// LS2                  limit         B
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <cmath>

using namespace vex;

// A global instance of competition
competition Competition;

//Function declaration
void StopAll(){
    LFM.stop(brake);
    LRM.stop(brake);
    RFM.stop(brake);
    RRM.stop(brake);
    AM1.stop(brake);
    AM2.stop(brake);
    CM1.stop(brake);
    CM2.stop(brake);
  }

long double adjustment() {
  long double x = 0;
  long double theta = AM2.position(degrees);
  long double angle =  -(std::abs(cos(theta)) + 1) * 10.125 + 20.25;
  long double y = (angle / (4 * M_PI)) * 360;  
  long double rotations = y - x;
  x = y
  return rotations;
}
  
void pre_auton(void) {
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
  AM1.setVelocity(100, percent);
  AM2.setVelocity(100, percent);
  CM1.setVelocity(25, percent);
  CM2.setVelocity(10, percent);
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

void autonomous(void) {

  //Autonomous route selection
  int route = (LS1.value() * 2) + (LS2.value() * 4);
  //Automomous route selection
  switch(route){
    case 0:
      StopAll();
    break;
    case 1:
      
    break;
    case 2:
      
    break;
    case 3:
      
    break;
    case 4:
      
    break;
    case 5:
      
    break;
    case 6:
      
    break;
    case 7:
      
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

  //variables/initialization
  float speed = .04;
  int b = 0;

  StopAll();

  // User control code here, inside the loop
  while (1) {

    //X-Drive Controlling
    LFM.spin(forward, speed * (Controller1.Axis3.value() + Controller1.Axis4.value() + Controller1.Axis1.value()), velocityUnits::pct);
    LRM.spin(forward, speed * (Controller1.Axis3.value() - Controller1.Axis4.value() + Controller1.Axis1.value()), velocityUnits::pct);
    RFM.spin(forward, speed * ((-Controller1.Axis3.value()) + Controller1.Axis4.value() + Controller1.Axis1.value()), velocityUnits::pct);
    RRM.spin(forward, speed * ((-Controller1.Axis3.value()) - Controller1.Axis4.value() + Controller1.Axis1.value()), velocityUnits::pct);

    //Velocity tapering and button control
    if ((LFM.isSpinning() || LRM.isSpinning() || RFM.isSpinning() || RRM.isSpinning()) && speed < 1) {
      speed += .04;
    } 
    else if (Controller1.ButtonR1.pressing()) {
      AM1.spin(forward);
      LFM.spinFor(adjustment(), degrees);
      LFM.spinFor(adjustment(), degrees);
      LFM.spinFor(adjustment(), degrees);
      LFM.spinFor(adjustment(), degrees);
    }
    else if (Controller1.ButtonR2.pressing()) {
      AM1.spin(reverse);
      LFM.spinFor(adjustment(), degrees);
      LFM.spinFor(adjustment(), degrees);
      LFM.spinFor(adjustment(), degrees);
      LFM.spinFor(adjustment(), degrees);
    }
    else if (Controller1.ButtonL1.pressing()) {
      AM2.spin(reverse);
      LFM.spinFor(adjustment(), degrees);
      LFM.spinFor(adjustment(), degrees);
      LFM.spinFor(adjustment(), degrees);
      LFM.spinFor(adjustment(), degrees);
    }
    else if (Controller1.ButtonL2.pressing()) {
      AM2.spin(forward);
      LFM.spinFor(adjustment(), degrees);
      LFM.spinFor(adjustment(), degrees);
      LFM.spinFor(adjustment(), degrees);
      LFM.spinFor(adjustment(), degrees);
    }
    else if (Controller1.ButtonUp.pressing()) {
      CM1.spin(forward);
    }
    else if (Controller1.ButtonDown.pressing()) {
      CM1.spin(reverse);
    }
    else if (Controller1.ButtonLeft.pressing()) {
      CM2.spin(forward);
    }
    else if (Controller1.ButtonRight.pressing()) {
      CM2.spin(reverse);
    }
    else if (Controller1.ButtonB.pressing() && b == 0) {
      LFM.setVelocity(50, percent);
      LRM.setVelocity(50, percent);
      RFM.setVelocity(50, percent);
      RRM.setVelocity(50, percent);
      b = 1;
    }
    else if (Controller1.ButtonB.pressing() && b == 1) {
      LFM.setVelocity(100, percent);
      LRM.setVelocity(100, percent);
      RFM.setVelocity(100, percent);
      RRM.setVelocity(100, percent);
      b = 0;
    }
    else if (Controller1.ButtonR1.pressing() || Controller1.ButtonR2.pressing() || Controller1.ButtonL1.pressing() || Controller1.ButtonL2.pressing() || Controller1.ButtonUp.pressing() || Controller1.ButtonDown.pressing() || Controller1.ButtonLeft.pressing() || Controller1.ButtonRight.pressing() != true) {
    StopAll();
    }
 }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
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
