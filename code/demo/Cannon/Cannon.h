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
	void turn(void);			//ボールの色に応じた旋回をする関数
	void resetturn(void);		//砲塔が旋回した分戻る関数

	void Fire(void);

	float firetheta;
	int t;	
	int goal;
      
};

#endif	//_CANNON_H