#include "run.h"
run r;

int main(void) {
    
    while(1) {
        r.straight(1000);
        r.WheelReset();
        wait(1);
        r.turn(180);
        r.WheelReset();
        wait(1);
    }
}

