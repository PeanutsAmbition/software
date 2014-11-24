#include "Cannon.h"



DigitalOut m1(p29);
DigitalOut m2(p30);



cannon::cannon(void)
{
	t = 0;
}

void cannon::Fire(void)
{
	while(1)
	{
      m1 = 1;
	  m2 = 0;
	}
}