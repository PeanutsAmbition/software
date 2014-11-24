#ifndef	_SENSOR_H
#define	_SENSOR_H

#include "mbed.h"


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
