#include "ColorSensor.h"
// カラーセンサーテストプログラム
// 赤、緑、青を判定する。
#define coef 1.05

ColorSensor::ColorSensor(
    PinName dout, PinName range, 
    PinName ck, PinName gate, int tm)
{
  Dout  = new DigitalIn(dout);
  Range = new DigitalOut(range);
  CK    = new DigitalOut(ck);
  Gate  = new DigitalOut(gate);
  time  = tm;       // 積算時間(ms)

  *CK = 0;
  *Gate = 0;
  *Range= 1;    // 高感度モード
  setWhite();
}

void ColorSensor::setWhite()
{
  unsigned short RGB[3];
  getRGB(RGB);
  R = RGB[0];
  G = RGB[1];
  B = RGB[2];
}

ColorSensor::ColorSensor(void) {
  unsigned short RGB[3];
  double R, G, B, r, g, b;

  Dout  = new DigitalIn(p11);    // Dout
  Range = new DigitalOut(p12);   // Range
  CK    = new DigitalOut(p13);   // CK
  Gate  = new DigitalOut(p14);   // Gate

  *CK   = 0; //ck
  *Gate = 0; //gate
  *Range = 1;  // 高感度モード range
  time = 10;   // 10ms
  setWhite();
}

void ColorSensor::getRGB(unsigned short RGB[])
{
    unsigned short i, j, coldata;

     *Gate = 1; 
     wait_ms(time);      // 積算時間
     *Gate  = 0; 
     for(i=0; i<3; i++) {
       coldata=0;
       for(j=0; j<12; j++) {
         *CK = 1; 
         wait_us(1);
         coldata>>=1;
         if(*Dout) coldata|=0x800;
         *CK = 0;
         wait_us(1);
      }
      RGB[i]=coldata;
    }
}

void ColorSensor::getRGB(
  unsigned& R, unsigned& G, unsigned& B)
{
    unsigned i, j, coldata;

     *Gate = 1; 
     wait_ms(time);       //  積算時間
     *Gate = 0;
     for(i=0; i<3; i++) {
       coldata=0;
       for(j=0; j<12; j++) {
         *CK = 1;
         wait_us(1);
         coldata>>=1;
         if(*Dout) coldata|=0x800;
         *CK = 0;
         wait_us(1);
       }
       switch(i) {
        case 0: R=coldata; break;
        case 1: G=coldata; break;
        case 2: B=coldata; break;
      }
    }
  }

// 比率を%で返す
//少し変更しました(2013/8)
unsigned ColorSensor::checkRGB(
  unsigned& R, unsigned& G, unsigned& B)
{
     unsigned i, j, coldata;
     double I;
     
     *Gate = 1; 
     wait_ms(time);      //  積算時間
     *Gate = 0;
     for(i=0; i<3; i++) {
       coldata=0;
       for(j=0; j<12; j++) {
         *CK = 1; 
         wait_us(1);
         coldata>>=1;
         if(*Dout) coldata|=0x800;
         *CK = false;
         wait_us(1);
       }
       switch(i) {
        case 0: R=coldata; break;
        case 1: G=coldata; break;
        case 2: B=coldata; break;
      }
    }
    I = R*0.65 + G + B*1.3;
    R = R*0.65 *100/I;
    G = G*100/I;
    B = B*1.3 *100/I;
    return I;
}

int ColorSensor::judge()
{
  unsigned short RGB[3];
  double r,g,b;
  *CK   = 0; //ck
  *Gate = 0; //gate
  *Range = 1;  // 高感度モード range

  getRGB(RGB);
  r = RGB[0]*100/R;
  g = RGB[1]*100/G;
  b = RGB[2]*100/B;
  if(r > g) {
       if(r > b*coef) return RED;
       else if(b > r*coef) return GREEN;
  }
   else {
     if(g > b*coef) return GREEN;
     else if(b > g*coef) return BLUE;
   }
  return OTHER;
}
