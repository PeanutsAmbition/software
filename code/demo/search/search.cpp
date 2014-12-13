#include "MainDefine.h"

sensor sensor;
data data;
servo servo;
run run;
control control;

search::search(){
}

search::~search(){
}

void search::SearchBall(){
	while(1){
		Search_theta=180.0;
		control.GoPosition(data.x,data.y+50.0);
		run.turn(90.0);
		while(SearchTheta>0.0){
			Search_theta=Search_theta-5.0;
			run.turn(-5.0);
			if(sensor.GetPSD){
				default_x=data.x;
				default_y=data.y;
				GetBall();
				FireBall();
				
			}
		}
		control.GoPosition(default_x,default_y);
	}
}

void search::GetBall(){
	servo.move(90.0);
	Fun(FUN_RUN);
	do{
		run.speed=0.2;
		run.straight(1);
	}while(GetBallColor()!=BALL_COLOR_DEFAULT);
	servo.move(-30.0);
	Fun(FUN_STOP);
	servo.move(5.0);
}