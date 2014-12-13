#include "MainDefine.h"

//PwmOut servo1(p23);
//PwmOut servo2(p24);
data data;

servo::servo(){
}

servo::~servo(){
}

void servo::move(int id,float target){
	PwmOut s = Servo[id];
	int pos = (int)data.servoDeg[id]+1400;
    int tar = (int)target*10+1400;
    
    if(pos<tar){
        for(int p=pos;p<tar;p+=10){
            s.pulsewidth_us(p);
            wait_ms(20);
        }
    }else{
        for(int p=pos;p>=tar;p-=10){
            s.pulsewidth_us(p);
            wait_ms(20);
        }
    }
    data.servoDeg[id] = (float)(tar-1400);
}

void servo_first(void){
	Servo[0]=servo1;
	Servo[1]=servo2;
	for(int i=0;i<2;i++){
	    int start=500;
	    int end=1400;
	    for(int p=start;p<end;p+=10){
	        Servo[i].pulsewidth_us(p);
	        wait_ms(20);
	    }
	    data.servoDeg[i] = 0.0;
	}
}