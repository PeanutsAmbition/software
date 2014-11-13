#include "math.h"
#include "data.h"
LocalFileSystem SeqFile("Local");

FILE *fp1;

data :: data(){
	
	x = 0.0;
	y = 0.0;
	theta = 0.0;
	
}


void data :: SetStatus(float l , float d){
	
	x += cos(theta) * l;
	y += sin(theta) * l;
	theta += d;
	if((l != 0) || (d != 0)){
		OutData();
	}
	
}
	

void data :: OutData(void){
	

	
	fp1 = fopen("/Local/Position.txt","a");
	
	fprintf(fp1,"(x , y , theta) = (%lf , %lf , %lf)\n",x,y,theta);
	
	fclose(fp1);
	
}
	
	
