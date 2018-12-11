#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#define mov 10
//structure definition


struct movInfo{//구조체정의 
		char name[100]; //movie name
		char country[10]; //movie country	//큰일 - int,fl로하면 이상한값 
		int runTime; //movie runtime
		float score; //movie score
	}movInfo_t[100];
	
#if 1


int mv_printAll(void *mv)
{	
	int i=0;
	FILE *fp;
	 
	//파일열기 
	fp=fopen("movie.txt","r");	

	for(i=0;i<mov;i++){//구조체 배열에 각각 영화정보 넣기 
		fscanf(fp,"%s %s %i %f", &movInfo_t[i].name, &movInfo_t[i].country, &movInfo_t[i].runTime, &movInfo_t[i].score);
		}

	for(i=0;i<mov;i++){//각각 프린트 
		printf("--------------------------------------------\n");
		printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", movInfo_t[i].name, movInfo_t[i].country, movInfo_t[i].runTime, movInfo_t[i].score);
	}

	fclose(fp);//파일닫기 	
}

int mv_printScore(void *mv)
{	int cnt=0;
	int i =0;
	float input_score;
	
	printf("lowest score : ");
	scanf("%f", &input_score);

	for(i=0;i<mov;i++){//while 로 바꿀 예정 
		if(movInfo_t[i].score>input_score){	
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", movInfo_t[i].name, movInfo_t[i].country, movInfo_t[i].runTime, movInfo_t[i].score);
			cnt++;
		}
	}
	printf("totaly %i movies are listed!\n", cnt);
}

int mv_printRunTime(void* mv)
{	int cnt=0;
	int i =0;
	int input_run;

	printf("lowest runtime : ");
	scanf("%s", &input_run);
	
	for(i=0;i<mov;i++){
		if(movInfo_t[i].runTime>input_run){	
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", movInfo_t[i].name, movInfo_t[i].country, movInfo_t[i].runTime, movInfo_t[i].score);
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
		if(strncmp(input_con, movInfo_t[i].country, strlen(input_con)) == 0){	//string.h - strncmp
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", movInfo_t[i].name, movInfo_t[i].country, movInfo_t[i].runTime, movInfo_t[i].score);
			cnt++;
		}
	}
	printf("totaly %i movies are listed!", cnt);
}

#endif


