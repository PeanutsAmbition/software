#ifndef	_SENSOR_H
#define	_SENSOR_H


AnalogIn	psd1(p17);
AanlogIn	psd2(p18);
AnalogIn	psd3(p19);
Analogin	psd4(p20);

ColorSensor ColorSensor(p11, p12, p13, p14, 30);

class sensor
{
	public:
		sensor();
		~sensor();
		
		float	Length[4];
		void	encordPSD(void);
		int		GetBallColor(void);
		
	private:
		float	PSD[4];
	
};

#endif	//_SENSOR_H