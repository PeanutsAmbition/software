#include "MainDefine.h"

run run;
data data;

void control::GoPosition(float x,float y){
	
	float length = sqrt(pow(data.x-x,2)+pow(data.y-y,2));
	
	Transform(x,y);
	run.straight(length);
}

void Transform(float x,float y){
	float deg=theta-atan(y/x);
	run.turn(deg);
}