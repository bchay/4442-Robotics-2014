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


void initializeRobot() {
	servo[ballContainer] = 170;
	servo[grabberRight] = 20; //Hook near NXTS
	rightServoPos = 0; //up
	servo[grabberLeft] = 30;
	leftServoPos = 0; //up
	servo[grabberSide] = 160;
	servo[center] = 255;
	return;
}

task main() {
	initializeRobot();
	waitForStart();

	while (true) {
		getJoystickSettings(joystick);
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		motor[rightBack] = 0;
		motor[rightFront] = 0;
		motor[scissorFront] = 0;
		motor[ballRamp] = 0;
		if(joystick.joy1_TopHat == 6) servo[ballContainer] += 10;
		if(joystick.joy1_TopHat == 2) servo[ballContainer] -= 10;
		if(joystick.joy2_TopHat == 0) servo[grabberSide] = 160;
		if(joystick.joy2_TopHat == 4) servo[grabberSide] = 0;

		if(joy2Btn(4) == 1) {
				servo[grabberRight] = 20; //Up
				rightServoPos = 0;
		}
		if(joy2Btn(2) == 1) {
				servo[grabberRight] = 210; //Down
				rightServoPos = 1;
	}
		if(joy2Btn(1) == 1) {
				servo[grabberLeft] = 30; //Right
				leftServoPos = 0;
		}

		if(joy2Btn(3) == 1) {
				servo[grabberLeft] = 200; //left
				leftServoPos = 1;
		}
		if(joy1Btn(1) == 1) servo[center] = 0;
		if(joy1Btn(3) == 1) servo[center] = 255;
		if(joystick.joy1_y1 > 30 && SensorValue[Touch] == 0) motor[scissorFront] = 80;
		if(joystick.joy1_y1 < -30) motor[scissorFront] =  -80;
		if(joystick.joy1_y2 > 10) motor[ballRamp] = 75;
		if(joystick.joy1_y2 < -10) motor[ballRamp] = -75;

		if(joystick.joy2_y1 > 30 || joystick.joy2_y1 < -30) { //10
			if(joystick.joy1_y1 >= 70 && rightServoPos == 0 && leftServoPos == 0) {
				motor[rightFront] = 70;
				motor[rightBack] = 70;
			} else if (joystick.joy2_y1 <= -70) {
				motor[rightFront] = -70;
				motor[rightBack] = -70;
			} else {
				motor[rightFront] = joystick.joy2_y1;
				motor[rightBack] = joystick.joy2_y1;
			}
		}
		if(joystick.joy2_y2 > 30 || joystick.joy2_y2 < -30) { //10
			if(joystick.joy1_y2 >= 70 && rightServoPos == 0 && leftServoPos == 0s) {
				motor[leftFront] = 70;
				motor[leftBack] = 70;
			} else if (joystick.joy2_y2 <= -70) {
				motor[leftFront] = -70;
				motor[leftBack] = -70;
			} else {
				motor[leftFront] = joystick.joy2_y2;
				motor[leftBack] = joystick.joy2_y2;
			}
		}
		wait1Msec(100);
	}
}
