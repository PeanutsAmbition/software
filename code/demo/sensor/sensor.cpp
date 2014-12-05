#include "MainDefine.h"
#include "mbed.h"
#include <new>

using namespace mbed;
ColorSensor colorSensor(p11, p12, p13, p14, 30);

sensor::sensor(AnalogIn psd1, AnalogIn psd2, AnalogIn psd3, AnalogIn psd4){
	PSD = new AnalogIn[4] {psd1, psd2, psd3, psd4};
}

sensor::~sensor(){
}

void sensor::encordPSD(void){
	
	int i;
	for(i=0;i<4;i++){
		Length[i] = (10138 / (PSD[i] - 911)) + 6;
	}
}

int sensor::GetBallColor(void){
	unsigned R,G,B;
	
	colorSensor.getRGB(R,G,B);
	
	if ((R > 3*B) && (G > 2*B) && (R > G)) return BALL_YELLOW; //yellow
    else if ((R > 2*B) && (R > 2*G)) return BALL_RED;  //red
    else if ((B > 1.5*R) && (B > G)) return BALL_BLUE;  //blue
	else return BALL_COLOR_DEFAULT;
}
