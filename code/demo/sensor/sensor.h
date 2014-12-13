#ifndef	_SENSOR_H
#define	_SENSOR_H

#include "ColorSensor.h"

// AnalogIn	psd1(p17);
// AnalogIn	psd2(p18);
// AnalogIn	psd3(p19);
 //AnalogIn	psd4(p20);


class sensor
{
	public:
		// オーバーライドしないならなぜ宣言した
		
		float	Length;
		bool	GetPSD(void);
		int		GetBallColor(void);
		float 	data[3];
		void 	run(void);
		void 	Initrun(void);
		float 	sum,ave;
		int 	i;

		
	private:
		AnalogIn	*PSD;
	
};

#endif	//_SENSOR_H
