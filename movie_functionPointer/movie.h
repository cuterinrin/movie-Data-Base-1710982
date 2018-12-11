
struct movInfo{
		char name[100]; //movie name
		char country[10]; //movie country	//큰일 - int,fl로하면 이상한값 
		int runTime; //movie runtime
		float score; //movie score
	};

int mv_printAll(void* mv, int cnt);
int mv_printScore(struct movInfo* mv, int cnt);
int mv_printRunTime(struct movInfo* mv, int cnt);
int mv_printCountry(struct movInfo* mv, int cnt);

