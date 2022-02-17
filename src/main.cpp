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
// LFM                  motor         11              
// LRM                  motor         20               
// RFM                  motor         9               
// RRM                  motor         7
// CM                   motor         17
// AM1                  motor         17
// AM2                  motor         17
// PM                   motor         5
// LS1                  limit         A
// LS2                  limit         B
// P1                   pneumatics    F
// P2                   pneumatics    G
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

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
  CM.stop(hold);
}
  void StopAllChasis(){
  LFM.stop(hold);
  LRM.stop(hold);
  RFM.stop(hold);
  RRM.stop(hold);
}

/*
  void FoWo(){
  LFM.startSpinFor(-180, degrees);
  RFM.startSpinFor(180, degrees);
  LRM.startSpinFor(-180, degrees);
  RRM.spinFor(180, degrees);
}
void BaWo(){
  LFM.startSpinFor(180, degrees);
  RFM.startSpinFor(-180, degrees);
  LRM.startSpinFor(180, degrees);
  RRM.spinFor(-180, degrees);
}
void RiWo(){
  LFM.startSpinFor(-180, degrees);
  RFM.startSpinFor(-180, degrees);
  LRM.startSpinFor(180, degrees);
  RRM.spinFor(180, degrees);
}
void LeWo(){
  LFM.startSpinFor(180, degrees);
  RFM.startSpinFor(180, degrees);
  LRM.startSpinFor(-180, degrees);
  RRM.spinFor(-180, degrees);
  
}
*/
void pre_auton(void){
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //Sets all motors
  LFM.setPosition(0, degrees);
  LRM.setPosition(0, degrees);
  RFM.setPosition(0, degrees);
  RRM.setPosition(0, degrees);
  CM.setPosition(0, degrees);
  LFM.setVelocity(100, percent);
  LRM.setVelocity(100, percent);
  RFM.setVelocity(100, percent);
  RRM.setVelocity(100, percent);
  CM.setVelocity(100, percent);
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
     /*  P2.open();
      wait(.25, sec);
      
       P1.close();
      wait(.5, sec);
*/
CM.spin(forward);
    break;
    case 1:
      //pick up alliance tower
        //move forward
        //grab alliance tower
        //load rings?
        //move back
        //lift onto platform?;
      LFM.startSpinFor(-950, degrees);
      RFM.startSpinFor(950, degrees);
      LRM.startSpinFor(-950, degrees);
      RRM.spinFor(950, degrees);
      P1.close();
      wait(.25, sec);
      P2.open();
      wait(.5, sec);
      P1.open();
      wait(.25, sec);
      P2.close();
      CM.startSpinFor(1070, degrees);
      LFM.startSpinFor(900, degrees);
      RFM.startSpinFor(-900, degrees);
      LRM.startSpinFor(900, degrees);
      RRM.startSpinFor(-900, degrees);
      
    break;
    case 2:
      //ram neutral tower
        //move forard
        //grab neutral tower
        //reverse
        //lift onto platform?
      /*AM1.startSpinFor(25, degrees);
      AM2.spinFor(25, degrees);
      LFM.startSpinFor(-2014, degrees);
      RFM.startSpinFor(2014, degrees);
      LRM.startSpinFor(-2014, degrees);
      RRM.spinFor(2014, degrees);
      P1.close();
      wait(.25, sec);
      P2.open();
      wait(.5, sec);
      P1.open();
      wait(.25, sec);
      P2.close();
      CM.startSpinFor(1070, degrees);
      LFM.startSpinFor(1950, degrees);
      RFM.startSpinFor(-1950, degrees);
      LRM.startSpinFor(1950, degrees);
      RRM.startSpinFor(-1950, degrees);*/
      P2.open();
      wait(.25, sec);
      
       P1.close();
      wait(.5, sec);

    break;
    case 3:
      //DANCE
      LFM.startSpinFor(-360, degrees);
      RFM.startSpinFor(360, degrees);
      LRM.startSpinFor(-360, degrees);
      RRM.spinFor(360, degrees);
      LFM.startSpinFor(900, degrees);
      RFM.startSpinFor(900, degrees);
      LRM.startSpinFor(900, degrees);
      RRM.startSpinFor(900, degrees);
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
 P2.open();
  //initialization

  while(1){
    

    //Screen printing

    double velocityControl1 = (Controller1.Axis2.position() + 100);
    double velocityControl2 = (velocityControl1 / 200);
    Controller1.Screen.clearLine();
    Controller1.Screen.print(velocityControl2 * 100);
    
    //X-Drive Controlling
    
    LFM.spin(forward, (((-Controller1.Axis3.position()) - Controller1.Axis4.position() - (Controller1.Axis1.position() / 2))) * velocityControl2, percent);
    LRM.spin(forward, (((-Controller1.Axis3.position()) + Controller1.Axis4.position() - (Controller1.Axis1.position() / 2))) * velocityControl2, percent);
    RFM.spin(forward, ((Controller1.Axis3.position() - Controller1.Axis4.position() -  (Controller1.Axis1.position() / 2))) * velocityControl2, percent);
    RRM.spin(forward, ((Controller1.Axis3.position() + Controller1.Axis4.position() -  (Controller1.Axis1.position() / 2))) * velocityControl2, percent);
    /*
    LFM.spin(forward, (-((-Controller1.Axis3.position()) - Controller1.Axis4.position() + Controller1.Axis1.position())) * velocityControl2, percent);
    LRM.spin(forward, (-((-Controller1.Axis3.position()) + Controller1.Axis4.position() + Controller1.Axis1.position())) * velocityControl2, percent);
    RFM.spin(forward, (-(Controller1.Axis3.position() - Controller1.Axis4.position() +  Controller1.Axis1.position())) * velocityControl2, percent);
    RRM.spin(forward, (-(Controller1.Axis3.position() + Controller1.Axis4.position() +  Controller1.Axis1.position())) * velocityControl2, percent);
    */
    //Velocity tapering and button control

    if(Controller1.ButtonB.pressing()){
      CM.spin(forward);
    }
    else if (Controller1.ButtonA.pressing()) {
      CM.spin(reverse);
    }
    else {
      CM.stop(hold);
    }

    if(Controller1.ButtonL1.pressing()){
     AM1.spin(forward);
     AM2.spin(forward);
    }
    else if(Controller1.ButtonL2.pressing()){
     AM1.spin(reverse);
     AM2.spin(reverse);
    }
    else{
      AM1.stop(hold);
      AM2.stop(hold);
    }
    if ((Controller1.Axis3.value() != 0) || (Controller1.Axis4.value() != 0) || (Controller1.Axis1.value() != 0) == true) {
    }
    else {
      StopAllChasis();
    }

     
    if(Controller1.ButtonUp.pressing()){
      P1.close();
      wait(.5, sec);
    }

    if(Controller1.ButtonDown.pressing()){
      P1.open();
      wait(.5, sec);
    }
    if(Controller1.ButtonLeft.pressing()){
      PM.spin(forward);
    }
    if(Controller1.ButtonRight.pressing()){
      PM.spin(reverse);
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
