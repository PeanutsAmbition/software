#ifndef _CANNON_H
#define _CANNON_H
#include "mbed.h"
enum
{
	TIMER_LIMIT =100
};


class cannon
{
public:
	/*void turn(void);
	void resetturn(void);
*/
	void Fire(void);

	int t;	
	int goal;
      
};

#endif	//_CANNON_H
