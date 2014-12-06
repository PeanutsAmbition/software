#include "MainDefine.h"
//LocalFileSystem SeqFile("Local");

FILE *fp1;

data :: data(){
	
	x = 0.0;
	y = 0.0;
	theta = 0.0;
	servoDeg[0] = 0.0;
	servoDeg[1] = 0.0;
	
	fp1 = fopen("/Local/psition.csv","a");
	fprintf(fp1,"x , y , theta \n");
	fclose(fp1);
	
}


void data :: SetStatus(float l , float d){
	
	x += cos(theta) * l;
	y += sin(theta) * l;
	theta += d;
	if((l != 0) || (d != 0)){
		OutData();
	}
	
}
	

/*void data :: OutData(void){
	

	
	fp1 = fopen("/Local/Position.csv","a");
	
	fprintf(fp1,"%lf , %lf , %lf\n",x,y,theta);
	
	fclose(fp1);
	
}*/
	
	
