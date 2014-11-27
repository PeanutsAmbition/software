#include "MainDefine.h"



DigitalOut m1(p29);
DigitalOut m2(p30);



cannon::cannon(void)
{
	t = 0;
}

void cannon::Fire(void)
{
	for(;;)
	{
      m1 = 1;
	  m2 = 0;
	}
}