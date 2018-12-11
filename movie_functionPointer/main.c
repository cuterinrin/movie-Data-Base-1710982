#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"


int main(int argc, char *argv[]) {
	
	struct movInfo movInfo_t[100];
	
	FILE *fp; //FILE pointer for reading movie data 
	struct movInfo *mv;//����ü �� �� 
	 
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	char c;
	int i=0;
	int cnt=0;//�� �� ,�ʱ�ȭ 
	
	mv = movInfo_t;
	
	//���� �д� ��...
	printf("loading the data files..\n");
	
//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat","r");//�Լ�����  	
	
	while (fscanf(fp,"%s %s %d %f",movInfo_t[i].name,movInfo_t[i].country, &movInfo_t[i].runTime, &movInfo_t[i].score) == 4)
	{
		cnt++;
		i++;
	}
	
	
	printf("%s %s %f %i\n", movInfo_t[i-1].name, movInfo_t[i-1].country, movInfo_t[i-1].score, movInfo_t[i-1].runTime);

	//1.4 FILE close
	fclose(fp);//��  
	printf("read done! ���� ��ȭ ������ %i���Դϴ�.\n", cnt);
#if 1
//2. program start
	while(exit_flag == 0)
	{
		//2.1 print menu message and get input option
		printf("\n------------------menu------------------\n");
		printf("1. print all movies\n");
		printf("2. search for specific country movies\n");
		printf("3. search for specific runtime movies\n");
		printf("4. search for specific score\n");
		printf("5. exit\n");
		printf("----------------------------------------\n");
		printf("select an option : ");
		scanf("%i", &option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n\n\n");
				for(i=0;i<cnt;i++){//���� ����Ʈ 
					printf("--------------------------------------------\n");
					printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", movInfo_t[i].name, movInfo_t[i].country, movInfo_t[i].runTime, movInfo_t[i].score);
					}
				
				break;
				
			case 2: //print movies of specific country
				mv_printCountry(mv, cnt);
				
				break;

			case 3: //print movies with long runtime
				mv_printRunTime(mv, cnt);

				break;
				
			case 4: //print movies with high score
				mv_printScore(mv, cnt);

				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;//exit_flag�� 0�϶� while���>1�̸� ���� 
				
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		
	}
	#endif
	return 0;
}
