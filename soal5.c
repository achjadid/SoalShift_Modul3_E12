#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h> 

int main()
{	
	int i=0;
	char text[1500];
	char *word;
	FILE *novel;
	scanf("%s",word);
	novel=fopen("Novel.txt","r");
	while(fscanf(novel,"%s",text)!=EOF)
	{
		if(strcmp(text,word)==0)
		{	
			i++;
		}
	}
	printf("%s: %d\n",word,i);
	return 0;
}
