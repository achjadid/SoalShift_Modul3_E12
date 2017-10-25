#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int lohan=100;
int kepiting=100;

pthread_t cek[4];

void menu(){
	printf("lohan : %d\n", lohan);
	printf("kepiting : %d\n", kepiting);
	printf("Pilih menu :\n");
	printf("1.Beri makan lohan\n");
	printf("2.Beri makan kepiting\n");
}

void* activity(void *agr){
	int i;
	pthread_t id=pthread_self();
	if(pthread_equal(id,cek[0])){
		while(1){
			sleep(10);
			lohan-=15;
		}
	}
	else if(pthread_equal(id,cek[1])){
		while(1){
			sleep(20);
			kepiting-=10;
		}
	}
	else if(pthread_equal(id,cek[2])){
		lohan+=10;
		if(lohan<=0 || lohan>100){
			printf("lohan mati, game selesai\n");
			exit(EXIT_FAILURE);
		}
	}
	else if(pthread_equal(id,cek[3])){
		kepiting+=10;
		if(kepiting<=0 || kepiting>100){
			printf("kepiting mati, game selesai\n");
			exit(EXIT_FAILURE);
		}
	}
}

int main(){
	int err1,err2,err3;
	int opt;
	err1=pthread_create(&(cek[0]),NULL,&activity,NULL);
	err2=pthread_create(&(cek[1]),NULL,&activity,NULL);
	while(1){
		if(lohan<=0 || lohan>100){
			printf("lohan mati, game selesai\n");
			break;
		}
		else if(kepiting<=0 || kepiting>100){
			printf("kepiting mati, game selesai\n");
			break;
		}
		else{
			menu();
			scanf("%d", &opt);
			if(opt==1) err3=pthread_create(&(cek[2]),NULL,&activity,NULL);
			else if(opt==2) err3=pthread_create(&(cek[3]),NULL,&activity,NULL);
		}
	}
}
