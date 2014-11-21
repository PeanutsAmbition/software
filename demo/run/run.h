#ifndef _RUN_INCLUDE
#define _RUN_INCLUDE


#include "QEI.h"
#define PI 3.14159265359
#define wheelGain 0	　		//減速速度
#define speed 0.7			//最高速度


class run{
	
	public:
		run();			//コンストラクタ
		void straight(float);	//直進(引数は距離(mm))
		void turn(float);	//旋回(引数は角度(deg))
		void WheelReset(void);	//エンコーダの値のリセット
		
		float RightLength;	//右の車輪の進行距離
		float LeftLength;	//左の車輪の進行距離
		float Theta[2];		//旋回した角度
		float dTheta;		//角速度
		float Length[2];	//進行距離
		float dLength;		//進行速度
	
	private:
		float wheel;		//車輪の間隔
		
		void getLength(void);	//エンコーダの処理
		
};
		
#endif	//_RUN_INCLUDE

