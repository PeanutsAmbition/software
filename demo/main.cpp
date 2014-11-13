#include "run.h"



int main(void) {
    
    while(1) {
        c_run->straight(1000);
        c_run->WheelReset();
        wait(1);
        c_run->turn(180);
        c_run->WheelReset();
        wait(1);
    }
}

