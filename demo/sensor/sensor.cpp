#include "sensor.h"

AnalogIn	psd1(p17);
AnalogIn	psd2(p18);
AnalogIn	psd3(p19);
AnalogIn	psd4(p20);
/*
DigitalOut	color1(p11);
DigitalIn	color2(p12);
DigitalIn	color3(p13);
DigitalIn	color4(p14);
*/

sensor::sensor(){
	PSD[0]		= psd1;
	PSD[1]		= psd2;
	PSD[2]		= psd3;
	PSD[3]		= psd4;
	
	Length[0]	= 0;
	Length[1]	= 0;
	Length[2] 	= 0;
	Length[3] 	= 0;
}

sensor::~sensor(){
}

void sensor::encordPSD(void){
	
	int i;
	for(i=0;i<4;i++){
		Length[i] = (10138 / (PSD[i] - 911)) + 6;
	}
}
