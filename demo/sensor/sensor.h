#ifndef	_SENSOR_H
#define	_SENSOR_H

#include "mbed.h"

AnalogIn	psd1(p17);
AanlogIn	psd2(p18);
AnalogIn	psd3(p19);
Analogin	psd4(p20);
/*
DigitalOut	color1(p11);
DigitalIn	color2(p12);
DigitalIn	color3(p13);
DigitalIn	color4(p14);
*/
class sensor
{
	public:
		sensor();
		~sensor();
		
		float	Length[4];
		void	encordPSD(void);
		
	private:
		float	PSD[4];
	
};

#endif	//_SENSOR_H