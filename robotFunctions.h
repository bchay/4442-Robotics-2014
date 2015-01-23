#ifndef robotFunctions_h
#define robotFunctions_h

int rightServoPos;
int leftServoPos;
void move(float distance, int power) { //distance in inches
	if(power > 0 && (rightServoPos != 0 || leftServoPos != 0)) return;
	motor[leftFront] = 0;
	motor[leftBack] = 0;
	motor[rightFront] = 0;
	motor[rightBack] = 0;
	distance = distance / .008131;
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[leftBack] = 0;
	nMotorEncoder[rightFront] = 0;
	nMotorEncoder[rightBack] = 0;

	nMotorEncoderTarget[rightFront] = distance;
	nMotorEncoderTarget[rightBack] = distance;
	nMotorEncoderTarget[leftBack] = distance;
	nMotorEncoderTarget[leftFront] = distance;
	motor[rightFront] = power;
	motor[rightBack] = power;
	motor[leftBack] = power;
	motor[leftFront] = power;

	while(nMotorRunState[leftBack] != runStateIdle && nMotorRunState[leftFront] != runStateIdle && nMotorRunState[rightBack] != runStateIdle && nMotorRunState[rightFront] != runStateIdle) {}
	motor[leftFront] = 0;
	motor[leftBack] = 0;
	motor[rightFront] = 0;
	motor[rightBack] = 0;
	wait1Msec(200);
}

void turn(float degree, int power, bool leftDir) {
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	nMotorEncoder[rightBack] = 0;
	nMotorEncoder[leftBack] = 0;
	float stopTurn = degree / .04305555555;
	if(leftDir) {
		nMotorEncoderTarget[rightFront] = stopTurn * -1;
		nMotorEncoderTarget[rightBack] = stopTurn * -1;
		nMotorEncoderTarget[leftBack] = stopTurn;
		nMotorEncoderTarget[leftFront] = stopTurn;
		motor[leftFront] = power;
		motor[leftBack] = power;
		motor[rightFront] = power * -1;
		motor[rightBack] = power * -1;
		while(nMotorRunState[leftBack] != runStateIdle && nMotorRunState[leftFront] != runStateIdle && nMotorRunState[rightBack] != runStateIdle && nMotorRunState[rightFront] != runStateIdle) {}
	} else {
		nMotorEncoderTarget[rightFront] = stopTurn;
		nMotorEncoderTarget[rightBack] = stopTurn;
		nMotorEncoderTarget[leftBack] = stopTurn * -1;
		nMotorEncoderTarget[leftFront] = stopTurn * -1;
		motor[leftFront] = power * -1;
		motor[leftBack] = power * -1;
		motor[rightFront] = power;
		motor[rightBack] = power;
		while(nMotorRunState[leftBack] != runStateIdle && nMotorRunState[leftFront] != runStateIdle && nMotorRunState[rightBack] != runStateIdle && nMotorRunState[rightFront] != runStateIdle) {}
	}
		motor[leftFront] = 0;
		motor[leftBack] = 0;
		motor[rightFront] = 0;
		motor[rightBack] = 0;
		wait1Msec(200);
}

void grabRollingGoalRight() {
	servo[grabberRight] = 100;
	rightServoPos = 1;
}

void releaseRollingGoalRight() {
	servo[grabberRight] = 210;
	rightServoPos = 0;
}

void grabRollingGoalLeft() {
	servo[grabberLeft] = 200;
	leftServoPos = 1;
}

void releaseRollingGoalLeft() {
	servo[grabberLeft] = 30;
	leftServoPos = 0;
}

void grabRollingGoalSide() {
	servo[grabberSide] = 20;
}

void releaseRollingGoalSide() {
	servo[grabberSide] = 180;
}

void dropInSmall() {
		servo[center] = 40;
}

#endif
