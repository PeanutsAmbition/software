#ifndef _CANNON_H
#define _CANNON_H
#include "mbed.h"
enum
{
	TIMER_LIMIT =100
};


public class Cannon
{
public:
	Cannon(void);
	//~Cannon(void);

	void Fire(void);

	int t;	//���[�^�𓮂����Ă��鎞��
      
};








#endif	//_CANNON_H