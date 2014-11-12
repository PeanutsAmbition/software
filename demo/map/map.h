#ifndef _MAP_INCLUDE
#define _MAP_INCLUDE

#define mapNo 4					//使用エリアの数

class map{
	
	public:
		struct Area{			//エリア毎の構造体
			
			float xMin;		//エリアのx座標の最大値
			float yMin;		//エリアのy座標の最大値
			float xMax;		//エリアのx座標の最小値
			float yMax;		//エリアのy座標の最小値
			
		};
		
		struct Area a[mapNo];		//エリアを定義
		
		map();				//コンストラクタでエリアに情報を持たせる
		
		int searchArea(float , float);	//自分がどこのエリアに居るのかを返す
		
};

#endif	//_MAP_INCLUDE
