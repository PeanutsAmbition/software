#ifndef _SERVO_H
#define _SERVO_H


class servo{
	
	public:
	servo();			//�R���X�g���N�^
	~servo();			//�f�X�g���N�^
	void move(int id,float target);	//�T�[�{�𓮂���
	void servo_first(void);
	
	PwmOut Servo[2];
	
};


#endif	//_SERVO_H
