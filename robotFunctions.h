#ifndef robotFunctions_h
#define robotFunctions_h

void move(float distance, int power) { //distance in inches
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
}

void turn(float degree, int power, bool leftDir) {
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	nMotorEncoder[rightBack] = 0;
	nMotorEncoder[leftBack] = 0;
	float stopTurn = degree / .045;
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
}

void grabRollingGoalRight() {
	servo[grabberRight] = 20;
}

void releaseRollingGoalRight() {
	servo[grabberRight] = 180;
}

void grabRollingGoalLeft() {
	servo[grabberLeft] = 20;
}

void releaseRollingGoalLeft() {
	servo[grabberLeft] = 180;
}

void grabRollingGoalSide() {
	servo[grabberSide] = 20;
}

void releaseRollingGoalSide() {
	servo[grabberSide] = 180;
}

void moveScissorLiftPos(int startHeight, int endHeight) {
	nMotorEncoder[scissorFront] = 0;
	if(startHeight == 0 && endHeight == 30)	nMotorEncoderTarget[scissorFront] = 1500;
	else if (startHeight == 0 && endHeight == 60) nMotorEncoderTarget[scissorFront] = 3000;
	else if (startHeight == 0 && endHeight == 60) nMotorEncoderTarget[scissorFront] = 0; //CHANGE
	motor[scissorFront] = 70;
	while(nMotorRunState[scissorFront] != runStateIdle) {}
	motor[scissorFront] = 0;
}

void moveScissorLift(bool directionUp) {
	int dir = 1;
	if(directionUp) dir = -1;
	motor[scissorFront] = 75 * dir;
}

void dropBallInGoal() {
	servo[ballContainer] = 20; //Horizontal
	wait1Msec(1000); //Wait for balls to drop
	servo[ballContainer] = 220; //Upright
}

void dropInCenter() {
		servo[center] = 20;
}

#endif
