#ifndef _SERVO_H
#define _SERVO_H


class servo{
	
	public:
	servo();			//コンストラクタ
	~servo();			//デストラクタ
	void move(int id,float target);	//サーボを動かす
	void servo_first(void);
	
	PwmOut Servo[2];
	
};


#endif	//_SERVO_H
