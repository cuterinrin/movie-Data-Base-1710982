#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"


int main(int argc, char *argv[]) {
	
	struct movInfo{//구조체정의 
		char name[100]; //movie name
		char country[10]; //movie country	//큰일 - int,fl로하면 이상한값 
		int runTime; //movie runtime
		float score; //movie score
	}movInfo_t[100];
	
	FILE *fp; //FILE pointer for reading movie data 
	struct movInfo *mv;//구조체 선 언 
	 
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	char c;
	int i;
	int cnt;//줄 수 
	
	mv = movInfo_t;
	
	//파일 읽는 중...
	printf("loading the data files...");
	
//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat","r");//함수열기  	
	
	while (fscanf(fp,"%s %s %d %f",movInfo_t[i].name,movInfo_t[i].country, &movInfo_t[i].runTime, &movInfo_t[i].score) == 4)
	{
		printf("%s %s %d %f\n",movInfo_t[i].name,movInfo_t[i].country, movInfo_t[i].runTime, movInfo_t[i].score);
		cnt++;
	}
	

	//1.4 FILE close
	fclose(fp);//닫  
	printf("읽은 영화 갯수는 %i개입니다.", cnt);

//2. program start
	while(exit_flag == 0)
	{
		//2.1 print menu message and get input option
		printf("-----------------------------------------");
		printf("1.print all movies ");
		printf("2. search for specific country movies");
		printf("3. search for specific runtime movies");
		printf("4. search for specific score");
		printf("5. exit");
		printf("-----------------------------------------");
		printf("select an option : ");
		scanf("%i", &option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				mv_printAll(mv);
				
				break;
				
			case 2: //print movies of specific country
				mv_printCountry(mv);
				
				break;

			case 3: //print movies with long runtime
				mv_printRunTime(mv);

				break;
				
			case 4: //print movies with high score
				mv_printScore(mv);

				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;//exit_flag가 0일때 while계속>1이면 나감 
				
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		
	}
	
	return 0;
}
