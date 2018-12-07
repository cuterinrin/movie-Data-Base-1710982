#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"


int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	int (*repFunc)(void* obj, void* arg); //function pointer for using list_repeatFunc() function
	void *arg; //a void pointer for passing argument to repFunc
	int cnt; //integer variable
	
//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat","r");//함수열기  
	
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while ( /* read name, country, runtime and score*/!= NULL )
	{	
		//generate a movie info instance(mvInfo) with function mv_genMvInfo() 
    	sscanf(fp, %s%i%s,&name,&runTime,&country,&score);//sscanf함수 - 형식에 맞춰 나눠서 저장  
        
		list_addTail(mvInfo, list);
	}

	//1.4 FILE close
	fclose(fp);//닫  
	
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
				
				repFunc = mv_printAll;
				arg = NULL;
				break;
				
			case 2: //print movies of specific country
				printf("%s", name);
				break;
				
			case 3: //print movies with long runtime
				printf("%s", runTime);

				break;
				
			case 4: //print movies with high score
				printf("%s", score);

				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;
				
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
		
		//2.3 print number of movies
	 
	  


	
	return 0;
}
