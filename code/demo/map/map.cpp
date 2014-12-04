#include "MainDefine.h"


map :: map(){
	
	a[0].xMin = 0.0; 	a[0].yMin = 0.0; 	a[0].xMax = 1000.0; a[0].yMax = 4000.0;
	a[1].xMin = 0.0; 	a[1].yMin = 4000.0; a[1].xMax = 3000.0; a[1].yMax = 5000.0;
	a[2].xMin = 3000.0; a[2].yMin = 1000.0; a[2].xMax = 4000.0; a[2].yMax = 5000.0;
	a[3].xMin = 1000.0; a[3].yMin = 0.0; 	a[3].xMax = 4000.0; a[3].yMax = 4000.0;

	goal[GOAL_RED] = 0.0;
	goal[GOAL_YELLOW] = 0.0;
	goal[GOAL_BLUE] = 0.0;
}

int map :: searchArea(float x , float y){
	
	int i;
	
	for(i = 0 ; i < mapNo ; i++){
		
		bool xFlg = false;
		bool yFlg = false;
		if(a[i].xMin < x || a[i].xMax > x){
			
			xFlg = true;
			
		}
		
		if(a[i].yMin < y || a[i].yMax > y){
			
			yFlg = true;
			
		}
		
		if(xFlg && yFlg){
			
			return i;
			
		}
	}
	
	return 0;
	
}
