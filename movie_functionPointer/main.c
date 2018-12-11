#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"//헤더 끌어오기 


int main(int argc, char *argv[]) {
	
	struct movInfo movInfo_t[2000];//영화 정보를 저장하는 배열, movie.h에 정의돼있다. 
	
	FILE *fp; //FILE pointer for reading movie data 
	struct movInfo *mv;//구조체 선언 
	 
	int exit_flag = 0; //while문 돌리는 조건, 5번을 눌러 1이 되면 while을 탈출하게 된다. 
	int option; //메뉴의 1,2,3,4,5,기타  옵션 
	int i=0;//배열의 번호 
	int cnt=0;//줄 수 ,초기화 
	
	mv = movInfo_t; //구조체 포인터 mv 
	
	//파일 읽는 중...
	printf("loading the data files..\n");
	
//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat","r");//파일 열기  	
	
	while (fscanf(fp,"%s %s %d %f",movInfo_t[i].name,movInfo_t[i].country, &movInfo_t[i].runTime, &movInfo_t[i].score) == 4)//배열에 영화 정보 저장, 갯수세기 
	/*fscanf는 제대로 돌아갔을 때, 0이 아닌 수를 반환한다. 파일이 끝나서 더이상 읽지 못할때는 0을 반환한다.
	그러므로 읽지 못했을 때, fscanf가 4가 아닐 때 while문을 나가겠다는 표현이다. 
	while문이 돌아갈때 i를 증가시키면, fscanf가 돌아가면서 각 배열에 읽은 값을 차례차례 저장시킨다.  
	*/ 	
	{
		cnt++;//파일 갯수 증가 
		i++;//배열 번호 증가 
	}
	
	//1.4 FILE close
	fclose(fp);//파일 닫기 
	printf("read done! 읽은 영화 갯수는 %i개입니다.\n", cnt);//읽은 영화의 갯수 표시  
	
#if 1
//2. program start
	//프로그램 몸체부분, 조건을 만족하는 한 계속 돌아간다. 
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
		scanf("%i", &option);//스위치의 옵션 입력받기 
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n\n\n");
				
				mv_printAll(mv, cnt);
				//구조체 배열을 포인터로 넘겨주고, 영화 총 갯수도 넘겨준다. 갯수는 for문을 돌릴때 제한 역할을 한다. 아래 함수들도 모두 동일  
				break;//다돌면 나가서 다시 while 맨위로 돌아가 option받고 switch실행  
				
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
				exit_flag = 1;//exit_flag가 0일때 while계속 > 1이면 나감 
				
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		
	}
	 
	#endif
	return 0;
}
