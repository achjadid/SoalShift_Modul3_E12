#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h> 

int main()
{	
	char text[1000];
	char *word;
	FILE *novel;
	scanf("%s",word);
	novel=fopen("novel.txt","r");
	while(fscanf(novel,"%s",text)!=EOF)
	{
		if(strcmp(text,word)==0)
		{	
			printf("ada");
		}
		else
		{
			printf("g ada");
		}
	}
	return 0;
}
