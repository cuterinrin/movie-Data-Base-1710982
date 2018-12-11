#include <stdio.h>
#include <stdlib.h>
#include <string.h>//strncmp사용, strlen사용 
#include "movie.h"

//structure definition

struct movInfo movInfo_t[2000]; 
	

#if 1

int mv_printAll(struct movInfo* mv, int cnt)//모든 영화를 출력하는 함수 
{		
	int i = 0;
	
	for(i=0;i<cnt;i++){//영화수만큼 진행하고 나온다. 영화 수는 main에서 이미 계산, 가져오면 된다. 
		printf("--------------------------------------------\n");
		printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", mv[i].name, mv[i].country, mv[i].runTime, mv[i].score);//영화 정보 출력 
	}
	printf("--------------------------------------------\n");
	printf("\ntotaly %i movies are listed!\n", cnt); //받아온 영화 갯수 출력 

}

int mv_printScore(struct movInfo* mv, int cnt)//일정 점수이상의 영화를 출력하는 함수 
{	int score_cnt=0;//검색될 영화 갯수 변수 지정  
	int i=0;
	float input_score;//검색할 점수 변수 지정 
	
	printf("lowest score : ");
	scanf("%f", &input_score);//점수 입력받음 

	for(i=0;i<cnt;i++){
		if(mv[i].score>input_score){//배열에 저장된 점수가 입력점수보다 클 때 출력 
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", mv[i].name, mv[i].country, mv[i].runTime, mv[i].score);
			score_cnt++;//출력시 ++ > 검색된 영화수 
		}
	}
	printf("--------------------------------------------\n");
	printf("\ntotaly %i movies are listed!\n", score_cnt);//갯수출력  
}

int mv_printRunTime(struct movInfo* mv, int cnt)
{	int run_cnt=0;//검색될 영화 갯수 변수 지정 
	int i =0;
	int input_run;//검색할 상영 시간 변수 지정 

	printf("lowest runtime : ");
	scanf("%i", &input_run);//상영시간 입력받음 
	
	for(i=0;i<cnt;i++){
		if(mv[i].runTime>input_run){//배열에 있는 상영시간이 입력 시간보다 클 때 출력. 
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", mv[i].name, mv[i].country, mv[i].runTime, mv[i].score);
			run_cnt++;//출력시 ++ >  검색된 영화 수  
		}
	}
	printf("--------------------------------------------\n");
	printf("\ntotaly %i movies are listed!\n", run_cnt); //갯수출력  
}

int mv_printCountry(struct movInfo* mv,int cnt)
{	int con_cnt=0;//검색될 영화 갯수 변수 지정 
	int i =0;
	char input_con[20];//검색할 나라, 글자는 배열에 저장될 때 한글자씩 되므로 배열로 선언 
	 
	printf("select country : "); 
	scanf("%s", input_con);//나라 입력받음, 문자열 > 배열에 글자 저장 
		
	for(i=0;i<cnt;i++){
		if(strncmp(input_con, mv[i].country, strlen(input_con)) == 0){	//string.h - strncmp - 앞단어와 뒷단어 일치, 글자수 일치시 0을 반환 > 0일시 출력하기 
			printf("--------------------------------------------\n");
			printf("NAME : %s (%s) \nRunning Time : %i, Score : %3f\n", mv[i].name, mv[i].country, mv[i].runTime, mv[i].score);
			con_cnt++;//일치할때 ++ > 일치한 단어수 = 출력된 영화수 
		}
	}
	printf("--------------------------------------------\n");
	printf("\ntotaly %i movies are listed!\n", con_cnt);//갯수출력  
}

#endif


