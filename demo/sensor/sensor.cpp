#include "MainDefine.h"

sensor::sensor(){
	PSD = {
		psd1,
		psd2,
		psd3,
		psd4
	};
	
	Length = {
		0,
		0,
		0,
		0
	};
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
	
	ColorSensor.getRGB(R,G,B);
	
	if ((R > B) && (G > B) && (G > 1000)) return BALL_YELLOW; //yellow
    else if ((R > B) && (R > G)) return BALL_RED;  //red
    else if ((B > R) && (B > G)) return BALL_BLUE;  //blue
	else return BALL_COLOR_DEFAULT;
}