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
    LFM.stop();
    LRM.stop();
    RFM.stop();
    RRM.stop();
    AM1.stop();
    AM2.stop();
    CM1.stop();
    CM2.stop();
  }

  void AllOn(){
    LFM.spin(forward);
    LRM.spin(forward);
    RFM.spin(forward);
    RRM.spin(forward);
    AM1.spin(forward);
    AM2.spin(forward);
    CM1.spin(forward);
    CM2.spin(forward);
  }

  //Autonomous route selection
  int route = (LS1.value() * 2) + (LS2.value() * 4);

  int x = 1;
  int y = 1;

  //variables
  float speed = .04;

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
  // User control code here, inside the loop
  while (1) {

    //X-Drive Controlling
    LFM.spin(forward, speed * (Controller1.Axis3.value() + Controller1.Axis4.value() + Controller1.Axis1.value()), velocityUnits::pct);
    LRM.spin(forward, speed * (Controller1.Axis3.value() - Controller1.Axis4.value() + Controller1.Axis1.value()), velocityUnits::pct);
    RFM.spin(forward, speed * ((-Controller1.Axis3.value()) + Controller1.Axis4.value() + Controller1.Axis1.value()), velocityUnits::pct);
    RRM.spin(forward, speed * ((-Controller1.Axis3.value()) - Controller1.Axis4.value() + Controller1.Axis1.value()), velocityUnits::pct);

    if ((LFM.isSpinning() || LRM.isSpinning() || RFM.isSpinning() || RRM.isSpinning()) && speed < 1) {
      speed += .04;
    } 

    
    double qtwo = (acos(((x * x) + (y * y) - 1 - (.83 * .83))/(2 * 1 * .83))) * 180/M_PI;
    double qone = (atan(x/y) - atan((sin(qtwo))/(.83 + cos(qtwo)))) * 180/M_PI;

    if (Controller1.ButtonR1.pressing()) {
      AM1.setPosition(qone, degrees);
      AM2.setPosition(qtwo, degrees);
      y += 1;
    }
    if (Controller1.ButtonR2.pressing()) {
      AM1.setPosition(qone, degrees);
      AM2.setPosition(qtwo, degrees);
      y -= 1;
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
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
