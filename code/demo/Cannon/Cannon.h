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

	int t;	//���[�^�𓮂����Ă��鎞��
      
};








#endif	//_CANNON_H