#include "QEI.h"
#define PI 3.14159265359
#define wheelGain 0
#define speed 0.7


class run{
	
	public:
		run();
		void straight(float);
		void turn(float);
		void WheelReset(void);
		
		float RightLength;
		float LeftLength;
		float Theta[2];
		float dTheta;
		float Length[2];
		float dLength;
	
	private:
		float wheel;
		
		void getLength(void);
		
};
		

