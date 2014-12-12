#include "MainDefine.h"

run r;
sensor s;
void encordPSD(void);
void Initrun(void);

DigitalOut led111(LED1);
DigitalOut led22(LED2);
//DigitalOut led3(LED3);

int main(void) {
    //led3 = 1;
    wait(2);
    //led3 = 0;
    while(1) {
        
        s.Initrun();
        s.encordPSD();
        wait(0.3);
         
        
        /*

        //led111 = 1;
        r.straight(1000);
        //led111 = 0;
        //wait(2);
        //led22 = 1; 
        r.WheelReset();
        wait(1);
        //led22 = 0;
        
        //led3 = 1;
        r.turn(180);
        //led3 = 0;
        r.WheelReset();
        wait(1);
        */
        
        
    }
}

