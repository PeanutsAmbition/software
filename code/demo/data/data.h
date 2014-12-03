#ifndef _DATA_H
#define _DATA_H

#include "mbed.h"



class data{
	
	public:
		float x;			//自己位置のx座標
		float y;			//自己位置のy座標
		float theta;			//角度姿勢
		float servoDeg[2];	//�T�[�{�p�x
		
		void SetStatus(float , float); 	//自己位置、角度姿勢を保存
		void OutData(void);		//自己位置をファイルへ出力
		data();				//コンストラクタで自己位置、角度姿勢を初期化
	
};

#endif	//_DATA_H
