#include "MainDefine.h"
//#define wheelGain 0.0

QEI wheelR(p5,p6,NC,100,QEI::X4_ENCODING);
QEI wheelL(p7,p8,NC,100,QEI::X4_ENCODING);
PwmOut pwmL(p21);
DigitalOut m1L(p23);
DigitalOut m2L(p22);
PwmOut pwmR(p24);
DigitalOut m1R(p25);
DigitalOut m2R(p26);

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);
data data;


run :: run(){
	
	wheel = 50 * PI;
	RightLength = 0.0;
	LeftLength = 0.0;
	Theta[0] = 0.0;
	Theta[1] = 0.0;
	dTheta = 0.0;
	Length[0] = 0.0;
	Length[1] = 0.0;
	dLength = 0.0;
	speed = 0.7;
	wheelGain = 0.1;
	
}

void run :: straight(float l){
    
    WheelReset();
    
    bool EndFlg = false;
    
	m1R = 1;
    m2R = 0;
           
    m1L = 1;
    m2L = 0;
    while(1){
	    
	    getLength();
		led1=1;
	    if(Length[0] < l){
	        
	        if(RightLength == LeftLength){
	        	led2=1;
	            pwmR = speed;
	            pwmL = speed;
	        	wait(0.5);  
	        	led2=0;
	        	wait(0.1);          
	        }else if(RightLength > LeftLength){
	            led3=1;
	            pwmR = wheelGain;
	            pwmL = speed;
	        	wait(0.5); 
	        	led3=0;
	        	wait(0.1);
	        }else if(RightLength < LeftLength){
	            led4=1;
	            pwmR = speed;
	            pwmL = wheelGain;
	            wait(0.5); 
	            led4=0;
	            wait(0.1);
	        }
	                
	     }else{
			//data.SetStatus(Length , Theta);
	        EndFlg = true;
	            led2=1;
	            led3=1;
	            led4=1;
	            pwmR=0;
	            pwmL=0;
	    }
	    data.SetStatus(dLength , dTheta);
		if(EndFlg) return; 
    }
            led1=0;
}

void run :: WheelReset(void){
    
    pwmR = 0;
    pwmL = 0;
    wheelR.reset();
    wheelL.reset();
    
}

void run :: turn(float deg_){
    WheelReset();
    
    float deg;
    deg = (deg_/180)*PI;
    
	bool EndFlg = false;
	
	m1R = 1;
    m2R = 0;
    
    m1L = 0;
    m2L = 1;
	
    while(1){
        
        getLength();
        
        if((Theta[0] < deg) && (Theta[0] > deg * (-1))){
           
            
            if((RightLength + LeftLength) == 0){
                
                pwmR = speed;
                pwmL = speed;
                
            }else if((RightLength + LeftLength) > 0){
                
                pwmR = speed;
                pwmL = wheelGain;
                
            }else if((RightLength + LeftLength) < 0){
                
                pwmR = wheelGain;
                pwmL = speed;
                
            }
        }else{
			
//			data.SetStatus(Length , Theta);
            EndFlg = true;
        }
        data.SetStatus(dLength , dTheta);
		if(EndFlg) return;
    }
}

void run :: getLength(void){
    
    Length[1] = Length[0];
    Theta[1] = Theta[0];
    
    RightLength = wheel * ((wheelR.getPulses() / -614 )/ (18 / 5));
    LeftLength = wheel * ((wheelL.getPulses() / 765) / (18 / 5));
	
	Length[0] = (RightLength + LeftLength) / 2;
	Theta[0] = (RightLength - LeftLength) / 181;
	
	dLength = Length[0] - Length[1];
    dTheta = Theta[0] - Theta[1];
    
}