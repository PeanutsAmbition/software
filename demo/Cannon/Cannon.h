#ifndef _CANNON_H
#define _CANNON_H
#include "mbed.h"
enum
{
	TIMER_LIMIT =100
};


public class cannon
{
public:
	cannon(void);
	//~cannon(void);

	void Fire(void);

	int t;	//モータを動かしている時間
      
};








#endif	//_CANNON_H