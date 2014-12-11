#include "mbed.h"

Serial pc(USBTX, USBRX);

// 距離センサからのアナログ入力を取得するオブジェクトの宣言
AnalogIn in(p20);

float sum,ave;
int i;
float data[100];

// 関数のプロトタイプ宣言
void run(void);
void Initrun(void);

int main() {
    Initrun();
    // 0.5秒毎にrun関数を実行する
    //input.attach(&run,0.5);  
    
    // 無限ループ
    while(1) {
        run();
        /*pc.baud(115200);
        pc.printf("%f\n", in.read() * 3.3);
        pc.printf("%f\n", 26.649 * (double)powf((in.read() * 3.3),-1.209));
        */
        wait(0.3);
    }
}

void Initrun(void){
    for (i = 0; i < 3; i++) data[i] = in.read();
}

// run関数内でセンサから値を取得し、電圧値から距離に変換したものをLCDに表示している。
void run(void)
{
    pc.baud(115200);
    
    for (i = 0; i < 2; i++) {
        data[i] = data[i + 1];
    }
    data[2] = in.read();
    
    for (i = 0; i < 3; i++) {
        sum = data[i] + sum;
    }
    
    ave = sum / 3;
    sum = 0;
    
    // 距離センサは、5～80[cm]の距離に対して3.2～0.4[V]の電圧が出力される。
    // mbedは0～3.3[V]の入力を0.0～1.0に変換し内部で処理している。
    // そこで、距離センサからの出力電圧を0.0～1.0に変換すると
    // 0.121(=0.4/3.3)～0.97(=3.2/3.3)になるので、この値に収まる場合は
    // 距離を求め、それ以外は測定範囲外の表示をする。
    //if (0.121 <= ave && ave <= 0.970){
        // 先ほどもとめた出力電圧から距離を求める近似式を使用する
        // pow(x,y)はxのy乗をもとめる関数
        //float range = 26.663 * pow((data*3.3),-1.25);
       float range = 26.649 * powf((ave) * 3.3,-1.209);
        
        pc.printf("Range: %4.1f[cm]\n",range);
    //}else{
       // 測定範囲外の場合のLCD表示
       //pc.printf("Range: ----[cm]\n");
    //}
}