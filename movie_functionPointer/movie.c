#include <stdio.h>
#include <stdlib.h>
#include <string.h>//strncmp���, strlen��� 
#include "movie.h"

//structure definition

struct movInfo movInfo_t[2000];
	

#if 1

int mv_printAll(struct movInfo* mv, int cnt)//��� ��ȭ�� ����ϴ� �Լ� 
{		
	int i = 0;
	
	for(i=0;i<cnt;i++){//��ȭ����ŭ �����ϰ� ���´�. ��ȭ ���� main���� �̹� ���, �������� �ȴ�. 
		printf("--------------------------------------------\n");
		printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", mv[i].name, mv[i].country, mv[i].runTime, mv[i].score);//��ȭ ���� ��� 
	}
	printf("--------------------------------------------\n");
	printf("\ntotaly %i movies are listed!\n", cnt); //�޾ƿ� ��ȭ ���� ��� 

}

int mv_printScore(struct movInfo* mv, int cnt)//���� �����̻��� ��ȭ�� ����ϴ� �Լ� 
{	int score_cnt=0;
	int i=0;
	float input_score;
	
	printf("lowest score : ");
	scanf("%f", &input_score);//���� �Է¹��� 

	for(i=0;i<cnt;i++){
		if(mv[i].score>input_score){//�迭�� ����� ������ �Է��������� Ŭ �� ��� 
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", mv[i].name, mv[i].country, mv[i].runTime, mv[i].score);
			score_cnt++;//��½� ++ > �˻��� ��ȭ�� 
		}
	}
	printf("--------------------------------------------\n");
	printf("\ntotaly %i movies are listed!\n", score_cnt);//�������  
}

int mv_printRunTime(struct movInfo* mv, int cnt)
{	int run_cnt=0;
	int i =0;
	int input_run;

	printf("lowest runtime : ");
	scanf("%i", &input_run);//�󿵽ð� �Է¹��� 
	
	for(i=0;i<cnt;i++){
		if(mv[i].runTime>input_run){//�迭�� �ִ� �󿵽ð��� �Է� �ð����� Ŭ �� ���. 
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", mv[i].name, mv[i].country, mv[i].runTime, mv[i].score);
			run_cnt++;//��½� ++ >  �˻��� ��ȭ ��  
		}
	}
	printf("--------------------------------------------\n");
	printf("\ntotaly %i movies are listed!\n", run_cnt); //�������  
}

int mv_printCountry(struct movInfo* mv,int cnt)
{	int con_cnt=0;
	int i =0;
	char input_con[20];//���ڴ� �迭�� ����� �� �ѱ��ھ� �ǹǷ� �迭�� ���� 
	 
	printf("select country : "); 
	scanf("%s", input_con);//���� �Է¹���, ���ڿ� > �迭�� ���� ���� 
		
	for(i=0;i<cnt;i++){
		if(strncmp(input_con, mv[i].country, strlen(input_con)) == 0){	//string.h - strncmp - �մܾ�� �޴ܾ� ��ġ, ���ڼ� ��ġ�� 0�� ��ȯ > 0�Ͻ� ����ϱ� 
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", mv[i].name, mv[i].country, mv[i].runTime, mv[i].score);
			con_cnt++;//��ġ�Ҷ� ++ > ��ġ�� �ܾ�� = ��µ� ��ȭ�� 
		}
	}
	printf("--------------------------------------------\n");
	printf("\ntotaly %i movies are listed!\n", con_cnt);//�������  
}

#endif


