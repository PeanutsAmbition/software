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
	void turn(void);			//�{�[���̐F�ɉ��������������֐�
	void resetturn(void);		//�C�������񂵂����߂�֐�

	void Fire(void);

	float firetheta;
	int t;	
	int goal;
      
};

#endif	//_CANNON_H