#include "Cannon.h"



DigitalOut m1(p29);
DigitalOut m2(p30);



Cannon::Cannon(void)
{
	t = 0;
}

void Cannon::Fire(void)
{
	for(;;)
	{
      m1 = 1;
	  m2 = 0;
	}
}