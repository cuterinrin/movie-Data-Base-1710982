#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#define mov 10
//structure definition
typedef struct movInfo {
	char name[100];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;
movInfo[100];

void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr;
	
	//allocate memory and set the member variables
	
	return (void*)mvPtr;
}

void printMv(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}

int mv_printAll(void* obj, void* arg)
{	
	int i=0;//for���� �� i 
	//���Ͽ��� 
	fp=fopen("movie.txt","r");	

	for(i=0;i<mov;i++){//����ü �迭�� ���� ��ȭ���� �ֱ� 
		fscanf(fp,"%s %s %i %f", &movInfo_t.name[i], &movInfo_t.madeIn[i], &movInfo_t.runTime[i], &movInfo_t.score[i]);
		}

	for(i=0;i<mov;i++){//���� ����Ʈ 
		printf("--------------------------------------------\n");
		printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", &movInfo_t.name[i], &movInfo_t.madeIn[i], &movInfo_t.runTime[i], &movInfo_t.score[i]);
	}

	fclose(fp);//���ϴݱ� 


	
}

int mv_printScore(void* obj, void* arg)
{
	for(i=0;i<mov;i++){
		if(movInfo_t.score[i]>score){	
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", &movInfo_t.name[i], &movInfo_t.madeIn[i], &movInfo_t.runTime[i], &movInfo_t.score[i]);
		}
	}
}

int mv_printRunTime(void* obj, void* arg)
{
		for(i=0;i<mov;i++){
		if(movInfo_t.runTime[i]>runTime){	
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", &movInfo_t.name[i], &movInfo_t.madeIn[i], &movInfo_t.runTime[i], &movInfo_t.score[i]);
		}
	}
}

int mv_printCountry(void* obj, void* arg)
{
		for(i=0;i<mov;i++){
		if(movInfo_t.madeIn[i] == country){	
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", &movInfo_t.name[i], &movInfo_t.madeIn[i], &movInfo_t.runTime[i], &movInfo_t.score[i]);
		}
	}
}




