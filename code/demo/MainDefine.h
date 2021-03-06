#ifndef MAIN_DEFINE_H
#define MAIN_DEFINE_H

#include "mbed.h"
#include "run.h"
#include "map.h"
#include "data.h"
#include "sensor.h"
#include "servo.h"
#include "plan.h"
#include "search.h"
#include "Cannon.h"
#include "ColorSensor.h"
#include "control.h"

#include "mbed.h"
#include "QEI.h"
#include "math.h"

enum{
	GOAL_RED,
	GOAL_YELLOW,
	GOAL_BLUE
};

enum{
	BALL_RED,
	BALL_YELLOW,
	BALL_BLUE,
	BALL_COLOR_DEFAULT
};
enum{
	FUN_RUN,
	FUN_STOP
};
#endif	//MAIN_DEFINE_H

