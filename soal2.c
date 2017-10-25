#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

pthread_t thr1;
pthread_t thr2;
char player1[101],player2[101];
int nilai1=0,nilai2=0;
int peta1[20],peta2[20];


int main(){
	while(1){
		printf("Player 1 : ");
		scanf("%s", player1);
		printf("Player 2 : ");
		scanf("%s", player2);
		for(int i=1;i<=16;i++){
			peta1[i]=0;
			peta2[i]=0;
		}
		pthread_create(&(thr1),NULL,&play1,NULL);
		pthread_create(&(thr2),NULL,&play2,NULL);
		pthread_join(thr1,NULL);
		pthread_join(thr2,NULL);
	}
}
