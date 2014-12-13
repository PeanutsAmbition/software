#include "MainDefine.h"

plan::plan(){
}

plan::~plan(){
}

void plan::RunPlan(){
	int state=0;
	switch(state){
		case 0:
		control.GoPosition(250.0,200.0);
		state++;
		break;
		case 1:
		servo.move(2,90.0);
		Cannon.Fire();
		servo.move(2,0.0);
		state++;
		break;
		case 2:
		control.GoPosition();
		state++;
		break;
		case 3:
		searchBall();
		state++;
		break;
		default:
		return;
	}
}