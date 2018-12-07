#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

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
	int i=0;//for에서 쓸 i 
	//파일열기 
	fp=fopen("movie.txt","r");	

	for(i=0;i<10;i++){//구조체 배열에 각각 영화정보 넣기 
		fscanf(fp,"%s %s %i %f", &movInfo_t.name[i], &movInfo_t.madeIn[i], &movInfo_t.runTime[i], &movInfo_t.score[i]);
		}

	for(i=0;i<10;i++){//각각 프린트 
		printf("--------------------------------------------");
		printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", &movInfo_t.name[i], &movInfo_t.madeIn[i], &movInfo_t.runTime[i], &movInfo_t.score[i]);
	}
		printf("--------------------------------------------");

	fclose(fp);//파일닫기 


	
}

int mv_printScore(void* obj, void* arg)
{
	
}

int mv_printRunTime(void* obj, void* arg)
{
	
}

int mv_printCountry(void* obj, void* arg)
{
	
}




