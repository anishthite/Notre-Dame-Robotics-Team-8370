#pragma config(Motor,  port2,           frontDriveR,   tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port3,           frontDriveL,   tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           backDriveR,    tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port5,           backDriveL,    tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port6,           topShootR,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           bottomShootR,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           belt,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           bottomShootL,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          topShootL,     tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	clearTimer(T1);
	// time less than 1 second
	motor(topShootR) = 127;
	motor(bottomShootR) = 127;
	motor(topShootL) = 127;
	motor(bottomShootL) = 127;

	while(time1[T1] < 3000)
{
	motor[belt] = 0;
}

while(time1[T1] < 4000)
{
	// turn on belt
	motor[belt] = 127;
}

while(time1[T1] < 5000)
{
	// turn on belt
	motor[belt] = 0;
}
while(time1[T1] < 6000)
{
	// turn on belt
	motor[belt] = 127;
}
while(time1[T1] < 7000)
{
	// turn on belt
	motor[belt] = 0;
}
AutonomousCodePlaceholderForTesting();
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
// User control code here, inside the loop


while (true)
{
	// This is the main execution loop for the user control program. Each time through the loop
	//your program should update motor + servo values based on feedback from the joysticks.
	//if (vexRT[Btn5D] == 1) {
	//	startTask(autonomous);
	//}

	int LSy = vexRT[Ch3]; // Between -127 and 127
	int RSy = vexRT[Ch2]; // ^

	/*
	* DRIVE
	*/
	motor[frontDriveL] = RSy; // Left Motor
	motor[backDriveL] = RSy;
	motor[frontDriveR] = LSy;
	motor[backDriveR] = LSy; // Right Motor

	/*
	* Shoot
	*/

	while (vexRT[Btn7U] == 1)
	{
		motor(topShootR) = 127;
		motor(bottomShootR) = 127;
		motor(topShootL) = 127;
		motor(bottomShootL) = 127;
	}

	while (vexRT[Btn5U] == 1)
	{
		motor(topShootR) = 0;
		motor(bottomShootR) = 0;
		motor(topShootL) = 0;
		motor(bottomShootL) = 0;
	}
	// HALF
	while (vexRT[Btn7D] == 1)
	{
		motor(topShootR) = 64;
		motor(bottomShootR) = 64;
		motor(topShootL) = 64;
		motor(bottomShootL) = 64;
	}

	/*
	* Belt
	*/
	while (vexRT[Btn8U] == 1)
	{
		motor(belt) = 127;
	}
	while (vexRT[Btn8D] == 1)
	{
		motor(belt) = -127;
	} while (vexRT[Btn8D] == 0 && vexRT[Btn8U] == 0){
		motor(belt) = 0;
	}

	UserControlCodePlaceholderForTesting();
}
}
