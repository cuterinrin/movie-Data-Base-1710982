//��� �κ�, main���� ����ü�� �Լ��� �˷��ش�. 

struct movInfo{
		char name[100]; //movie name
		char country[20]; //movie country
		int runTime; //movie runtime
		float score; //movie score
	};

int mv_printAll(struct movInfo* mv, int cnt);
int mv_printScore(struct movInfo* mv, int cnt);
int mv_printRunTime(struct movInfo* mv, int cnt);
int mv_printCountry(struct movInfo* mv, int cnt);

