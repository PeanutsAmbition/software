#ifndef _COLOR_SENSOR_H
#define _COLOR_SENSOR_H

#include "mbed.h"
#define RED   0
#define GREEN 1
#define BLUE  2
#define OTHER 3

class ColorSensor
{
  private:
    DigitalIn *Dout;
    DigitalOut *Range;
    DigitalOut *CK;
    DigitalOut *Gate;
    int time;
    double R, G, B;
  public:
    ColorSensor(PinName Dout, PinName Range, PinName CK, PinName Gate, int time);
    ColorSensor(void);
    void getRGB(unsigned short RGB[]);
    void getRGB(unsigned& R, unsigned& G, unsigned& B);
    unsigned checkRGB(unsigned& R, unsigned& G, unsigned& B);
    int judge();
    void setWhite();
};

#endif  //_COLOR_SENSOR_H