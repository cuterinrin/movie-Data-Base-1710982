//�ټ��б�>>��ȭ ���� 2.3
int line_number(void)
	{
		int line=0;
 		char c;
 		
		fp=fopen("movie.dat","r");
		
		while((c=fgetc(fp))!=EOF){
  			if(c=='\n') 
				{line++;}
 	 		fclose(fp);
			}
 		} 
