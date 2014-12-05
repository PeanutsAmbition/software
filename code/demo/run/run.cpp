#include "MainDefine.h"
#define wheelGain 0.0

QEI wheelR(p5,p6,NC,100,QEI::X4_ENCODING);
QEI wheelL(p7,p8,NC,100,QEI::X4_ENCODING);
PwmOut pwmL(p21);
DigitalOut m1L(p22);
DigitalOut m2L(p23);
PwmOut pwmR(p24);
DigitalOut m1R(p25);
DigitalOut m2R(p26);

DigitalOut led1(LED1);
DigitalOut led2(LED2);

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
		
	    if(Length[0] < l){
	        
	        if(RightLength == LeftLength){
	        
	            pwmR = speed;
	            pwmL = speed;
	                    
	        }else if(RightLength > LeftLength){
	            
	            pwmR = wheelGain;
	            pwmL = speed;
	        
	        }else if(RightLength < LeftLength){
	            
	            pwmR = speed;
	            pwmL = wheelGain;
	            
	        }
	                
	     }else{
			//data.SetStatus(Length , Theta);
	        EndFlg = true;
	            
	    }
	    data.SetStatus(dLength , dTheta);
		if(EndFlg) return; 
    }
            
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

