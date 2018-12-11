#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#define mov 10
//structure definition

#if 1
typedef struct movInfo {
	char name[100];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t[100];


int mv_printAll(void *mv)
{	
	int i=0;
	FILE *fp;
	 
	//파일열기 
	fp=fopen("movie.txt","r");	

	for(i=0;i<mov;i++){//구조체 배열에 각각 영화정보 넣기 
		fscanf(fp,"%s %s %i %f", &movInfo_t[i].name, &movInfo_t[i].madeIn, &movInfo_t[i].runTime, &movInfo_t[i].score);
		}

	for(i=0;i<mov;i++){//각각 프린트 
		printf("--------------------------------------------\n");
		printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", movInfo_t[i].name, movInfo_t[i].madeIn, movInfo_t[i].runTime, movInfo_t[i].score);
	}

	fclose(fp);//파일닫기 	
}

int mv_printScore(void *mv)
{	int cnt=0;
	int i =0;
	float input_score;
	
	printf("lowest score : ");
	scanf("%s", &input_score);

	for(i=0;i<mov;i++){
		if(movInfo_t.score[i]>input_score){	
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", movInfo_t.name[i], movInfo_t.madeIn[i], movInfo_t.runTime[i], movInfo_t.score[i]);
			cnt++;
		}
	}
	printf("totaly %i movies are listed!", cnt);
}

int mv_printRunTime(void* mv)
{	int cnt=0;
	int i =0;
	int input_run;

	printf("lowest runtime : ");
	scanf("%s", &input_run);
	
	for(i=0;i<mov;i++){
		if(movInfo_t.runTime[i]>input_run){	
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", movInfo_t.name[i], movInfo_t.madeIn[i], movInfo_t.runTime[i], movInfo_t.score[i]);
			cnt++;
		}
	}
	printf("totaly %i movies are listed!", cnt);
}

int mv_printCountry(void* mv)
{	int cnt=0;
	int i =0;
	char input_con;
	 
	printf("select country : ");
	scanf("%s", &input_con);
		
	for(i=0;i<mov;i++){
		if(strncmp(input_con, movInfo_t[i].madeIn, strlen(input_con)) == 0){	//string.h dlttdma - 한글자씩 읽는걸로 대체 
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", movInfo_t.name[i], movInfo_t.madeIn[i], movInfo_t.runTime[i], movInfo_t.score[i]);
			cnt++;
		}
	}
	printf("totaly %i movies are listed!", cnt);
}

#endif


