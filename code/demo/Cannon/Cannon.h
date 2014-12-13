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
	void turn(void);			//ƒ{[ƒ‹‚ÌF‚É‰‚¶‚½ù‰ñ‚ğ‚·‚éŠÖ”
	void resetturn(void);		//–C“ƒ‚ªù‰ñ‚µ‚½•ª–ß‚éŠÖ”

	void Fire(void);

	float firetheta;
	int t;	
	int goal;
      
};

#endif	//_CANNON_H