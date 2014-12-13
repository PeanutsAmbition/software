#include "MainDefine.h"

data data;

servo::servo(){
	Servo = {servo1,servo2};
	for(int i=0;i<2;i++){
	    int start=500;
	    int end=1400;
	    for(int p=start;p<end;p+=10){
	        servo[i].pulsewidth_us(p);
	        wait_ms(20);
	    }
	    data.servoDeg[i] = 0.0;
	}
}

servo::~servo(){
}

void servo::move(int id,float target){
	PwmOut s = Servo[id];
	int pos = (int)theta+1400;
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
    data.servoDeg[i] = (float)(tar-1400);
}
