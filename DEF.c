#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S2,     touch,          sensorTouch)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     leftBack,      tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     scissorFront,  tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     leftFront,     tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     rightBack,     tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     rightFront,    tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     ballRamp,      tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    ballContainer,        tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    grabberRight,         tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    grabberLeft,          tServoStandard)
#pragma config(Servo,  srvo_S1_C3_4,    grabberSide,          tServoStandard)
#pragma config(Servo,  srvo_S1_C3_5,    center,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "robotFunctions.h"
#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

//rightServoUp: 20
//rightServoDown: 200
//leftServoUp: 30
//leftServoDown: 210
//centerUp: 255
//centerDown: 100

void initializeRobot() {
	servo[ballContainer] = 170;
	servo[grabberRight] = 20; //Hook near NXT
	rightServoPos = 0; //up
	servo[grabberLeft] = 30;
	leftServoPos = 0; //up
	servo[grabberSide] = 160;
	servo[center] = 255;
	return;
}

task main() {
	//ball grabber facing opposing ramp from platform
	initializeRobot();
	waitForStart();
	move(7 * 12, -85);
	wait1Msec(3000);
	move(3 * 12, 85);
}
