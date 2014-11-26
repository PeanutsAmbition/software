#include "sensor.h"

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