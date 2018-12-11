#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

//structure definition

struct movInfo movInfo_t[100];
	

#if 1

int mv_printAll(void *mv, int cnt)
{		
	int i = 0;
	
	for(i=0;i<cnt;i++){//���� ����Ʈ 
		printf("--------------------------------------------\n");
		printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", movInfo_t[i].name, movInfo_t[i].country, movInfo_t[i].runTime, movInfo_t[i].score);
	}
	
	printf("totaly %i movies are listed!\n", cnt);

}

int mv_printScore(struct movInfo* mv, int cnt)
{	int score_cnt=0;
	int i =0;
	float input_score;
	
	printf("lowest score : ");
	scanf("%f", &input_score);

	for(i=0;i<cnt;i++){//while �� �ٲ� ���� 
		if(mv[i].score>input_score){	
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", movInfo_t[i].name, movInfo_t[i].country, movInfo_t[i].runTime, movInfo_t[i].score);
			score_cnt++;
		}
	}
	printf("totaly %i movies are listed!\n", score_cnt);
}

int mv_printRunTime(struct movInfo* mv, int cnt)
{	int run_cnt=0;
	int i =0;
	int input_run;

	printf("lowest runtime : ");
	scanf("%s", &input_run);
	
	for(i=0;i<cnt;i++){
		if(mv[i].runTime>input_run){	
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", mv[i].name, mv[i].country, mv[i].runTime, mv[i].score);
			run_cnt++;
		}
	}
	printf("totaly %i movies are listed!\n", run_cnt);
}

int mv_printCountry(struct movInfo* mv,int cnt)
{	int con_cnt=0;
	int i =0;
	char input_con[20];
	 
	printf("select country : ");
	scanf("%s", input_con);
		
	for(i=0;i<cnt;i++){
		if(strncmp(input_con, mv[i].country, strlen(input_con)) == 0){	//string.h - strncmp
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", mv[i].name, mv[i].country, mv[i].runTime, mv[i].score);
			con_cnt++;
		}
	}
	printf("totaly %i movies are listed!\n", con_cnt);
}

#endif


