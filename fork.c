#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void fork();
void fork(){
	if(fork()!=-1){
		int get=getpid();
		printf("Process id:,%d",get);
		printf("\n");
	}
	else{
		printf("No child process created.");
		exit(0);
	}
}
int main(){
	fork();
}
