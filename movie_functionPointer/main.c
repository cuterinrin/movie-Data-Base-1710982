#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"//��� ������� 


int main(int argc, char *argv[]) {
	
	struct movInfo movInfo_t[2000];//��ȭ ������ �����ϴ� �迭, movie.h�� ���ǵ��ִ�. 
	
	FILE *fp; //FILE pointer for reading movie data 
	struct movInfo *mv;//����ü ���� 
	 
	int exit_flag = 0; //while�� ������ ����, 5���� ���� 1�� �Ǹ� while�� Ż���ϰ� �ȴ�. 
	int option; //�޴��� 1,2,3,4,5,��Ÿ  �ɼ� 
	int i=0;//�迭�� ��ȣ 
	int cnt=0;//�� �� ,�ʱ�ȭ 
	
	mv = movInfo_t; //����ü ������ mv 
	
	//���� �д� ��...
	printf("loading the data files..\n");
	
//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat","r");//���� ����  	
	
	while (fscanf(fp,"%s %s %d %f",movInfo_t[i].name,movInfo_t[i].country, &movInfo_t[i].runTime, &movInfo_t[i].score) == 4)//�迭�� ��ȭ ���� ����, �������� 
	/*fscanf�� ����� ���ư��� ��, 0�� �ƴ� ���� ��ȯ�Ѵ�. ������ ������ ���̻� ���� ���Ҷ��� 0�� ��ȯ�Ѵ�.
	�׷��Ƿ� ���� ������ ��, fscanf�� 4�� �ƴ� �� while���� �����ڴٴ� ǥ���̴�. 
	while���� ���ư��� i�� ������Ű��, fscanf�� ���ư��鼭 �� �迭�� ���� ���� �������� �����Ų��.  
	*/ 	
	{
		cnt++;//���� ���� ���� 
		i++;//�迭 ��ȣ ���� 
	}
	
	//1.4 FILE close
	fclose(fp);//���� �ݱ� 
	printf("read done! ���� ��ȭ ������ %i���Դϴ�.\n", cnt);//���� ��ȭ�� ���� ǥ��  
	
#if 1
//2. program start
	//���α׷� ��ü�κ�, ������ �����ϴ� �� ��� ���ư���. 
	while(exit_flag == 0)
	{
		//2.1 print menu message and get input option
		printf("\n--------------------menu--------------------\n");
		printf("1. print all movies\n");
		printf("2. search for specific country movies\n");
		printf("3. search for specific runtime movies\n");
		printf("4. search for specific score\n");
		printf("5. exit\n");
		printf("--------------------------------------------\n");
		printf("select an option : ");
		scanf("%i", &option);//����ġ�� �ɼ� �Է¹ޱ� 
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n\n\n");
				
				mv_printAll(mv, cnt);
				//����ü �迭�� �����ͷ� �Ѱ��ְ�, ��ȭ �� ������ �Ѱ��ش�. ������ for���� ������ ���� ������ �Ѵ�. �Ʒ� �Լ��鵵 ��� ����  
				break;//�ٵ��� ������ �ٽ� while ������ ���ư� option�ް� switch����  
				
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
				printf("\n\nBye Bye!!\n\n");
				exit_flag = 1;//exit_flag�� 0�϶� while��� > 1�̸� ���� 
				
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		
	}
	 
	#endif
	return 0;
}
