#include "MainDefine.h"



DigitalOut m1(p29);
DigitalOut m2(p30);
DigitalOut led11(LED1);


/*void cannon::turn(float x, float y, float theta, int judge)
{
	if(judge == red){
		goal = 250;
		}
	else if(judge == yellow){
		goal = 900;
		}
	else if(judge == blue){
		goal = 1550;
		}
	servo::move(1,-(theta+3.141/2-atan2(goal-y,x)))
}

void cannon::resetturn(float x, float y, float theta, int judge)
{
	if(judge == red){
		goal = 250;
		}
	else if(judge == yellow){
		goal = 900;
		}
	else if(judge == blue){
		goal = 1550;
		}
	servo::move(1,theta+3.141/2-atan2(goal-y,x))
}*/

void cannon::Fire(void)
{
	/*for(;;)
	{
      m1 = 1;
	  m2 = 0;
	}*/
	
	led11 = 1;
	wait(1);
	
	led11 = 0;
	m1 = 0;			//‘Å‚¿‚¾‚µ
	m2 = 1;
	wait(1.07);		//ŽüŠú1.07s‚Åˆê‰ñ“]
	
	led11 = 1;
	m1 = 0;			//’âŽ~
	m2 = 0;
	wait(2);
}
