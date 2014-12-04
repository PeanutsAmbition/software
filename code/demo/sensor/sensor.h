#ifndef	_SENSOR_H
#define	_SENSOR_H

#include "ColorSensor.h"

// AnalogIn	psd1(p17);
// AnalogIn	psd2(p18);
// AnalogIn	psd3(p19);
// AnalogIn	psd4(p20);


class sensor
{
	public:
		// オーバーライドしないならなぜ宣言した
		sensor(AnalogIn psd1, AnalogIn psd2, AnalogIn psd3, AnalogIn pad4);
		~sensor();
		
		float	Length[4];
		void	encordPSD(void);
		int		GetBallColor(void);
		
	private:
		AnalogIn	*PSD;
	
};

#endif	//_SENSOR_H