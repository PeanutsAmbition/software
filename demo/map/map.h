#define mapNo 4

class map{
	
	public:
		struct Area{
			
			float xMin;
			float yMin;
			float xMax;
			float yMax;
			
		};
		
		struct Area a[mapNo];
		
		map();
		
		int searchArea(float , float);
		
};
