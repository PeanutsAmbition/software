#include "MainDefine.h"
#include "mbed.h"
#include <new>

AnalogIn	psd2(p19);

using namespace mbed;
ColorSensor colorSensor(p11, p12, p13, p14, 30);

/*sensor::sensor(AnalogIn psd1){
//PSD = new AnalogIn[4] {psd1, psd2, psd3, psd4} ;
}
*/

void sensor::Initrun(void){
    for (i = 0; i < 3; i++) data[i] = psd2.read();
}
bool sensor::GetPSD(void){
    
    Serial pc(USBTX, USBRX);
     pc.baud(115200);
     
     //ave = psd2.read();
     //pc.printf("ave = %f\n",ave);
     
    for (i = 0; i < 2; i++) {
        data[i] = data[i + 1];
    }
    data[2] = psd2.read();
    
    for (i = 0; i < 3; i++) {
        sum = data[i] + sum;
    }
    
    ave = sum / 3;
    sum = 0;
    
	float Length = 26.649 * pow((ave) * 3.3,-1.209);
	pc.printf("Length : %4.1f [cm]\n",Length);
	if(Length<=460.0) return true;
	}

int sensor::GetBallColor(void){
	unsigned R,G,B;
	
	colorSensor.getRGB(R,G,B);
	
	if ((R > 3*B) && (G > 2*B) && (R > G)) return BALL_YELLOW; //yellow
    else if ((R > 2*B) && (R > 2*G)) return BALL_RED;  //red
    else if ((B > 1.5*R) && (B > G)) return BALL_BLUE;  //blue
	else return BALL_COLOR_DEFAULT;
}

