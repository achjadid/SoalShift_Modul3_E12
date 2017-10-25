#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h> 

void* findword(void* arg)
{	
	int i=0, a;
	char text[1500];
	char *word;
	FILE *novel;
	scanf("%s",word);
	a=strlen(word);
	novel=fopen("Novel.txt","r");
	while(fscanf(novel,"%s",text)!=EOF)
	{
		if(!strncmp(text,word,a))
		{	
			i++;
		}
	}
	printf("%s: %d\n",word,i);
	fclose(novel);
	return 0;
}

int main()
{
	int i;
	int err;
	pthread_t tid[2];	
	for(i=0;i<2;i++)
	{
		err=pthread_create(&(tid[i]),NULL,&findword,NULL);
		if(err!=0)
	        {
			printf("\n can't create thread : [%s]",strerror(err));
		}

	}
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	return 0;
}
