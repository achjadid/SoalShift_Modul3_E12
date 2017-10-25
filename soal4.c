#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int num[101];

int main(){
	char strfac[101];
	char temp,temp1,temp2;
	scanf("%s", strfac); //scan the first string
	int n=0;
	do{ //scan input
		scanf("%d%c", &num[n], &temp);
		n++;
		if(n!=1){ //sort
			int k=1;
			temp1=num[n-k-1];
			temp2=num[n-k];
			while(temp1>temp2){
				num[n-k-1]=temp2;
				num[n-k]=temp1;
				k++;
				temp1=num[n-k-1];
				temp2=num[n-k];
			}
		}
	}while(temp!='\n');
}


