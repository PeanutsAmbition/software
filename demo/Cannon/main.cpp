#include "mbed.h"
#include "Cannon.h"
Cannon c;
DigitalOut led1(LED1);

int main()
{
    led1 = 1;
    c.Fire();
    
}