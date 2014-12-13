#include "MainDefine.h"

sensor sen;
servo servo;
data data;
run r;

DigitalOut m1(p29);
DigitalOut m2(p30);
DigitalOut led11(LED1);


void cannon::turn(void)
{
	sen.GetBallColor();
	if(sen.GetBallColor() == BALL_RED){				//ƒS[ƒ‹‚ÌˆÊ’u‚ğŒˆ’è
		goal = 250;
		}
	else if(sen.GetBallColor() == BALL_YELLOW){
		goal = 900;
		}
	else if(sen.GetBallColor() == BALL_BLUE){
		goal = 1550;
		}
	
	data.x;
	data.y;
	data.theta;
	
	firetheta=90.0-180/PI*atan2(goal-data.y,data.x)-data.theta;
	
	if(90.0 < firetheta < 90.0){			//–C“ƒù‰ñ‚¾‚¯‚ÅƒS[ƒ‹‚ÉŒü‚¯‚é
		
		servo.move(2,firetheta);
		
		}
		else if(-180.0 < firetheta< -90.0){
			
		servo.move(2,-90);
		r.turn(firetheta+90.0);
	
		}
		else if(90 < firetheta < 180){
			
		servo.move(2,90.0);
		r.turn(firetheta-90.0);
			
		}
}
		


void cannon::resetturn(void)
{
	
	servo.move(2,0);
	
	
}

void cannon::Fire(void)
{
	/*for(;;)
	{
      m1 = 1;
	  m2 = 0;
	}*/
	
	led11 = 1;
	wait(0.5);
	
	led11 = 0;
	m1 = 0;			//‘Å‚¿‚¾‚µ
	m2 = 1;
	wait(1.07);		//üŠú1.07s‚Åˆê‰ñ“]
	
	led11 = 1;
	m1 = 0;			//’â~
	m2 = 0;
	wait(0.5);
}