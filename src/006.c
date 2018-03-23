#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 100

#include <stdio.h>


int func(char *buffer, int len){
	int i, count = 0;
	for(i=0;i<SIZE;i++){
		if(buffer[i]=='A')
			count++;
	}
	printf("%d\n",count);
	if (count == 42) {
		if(strncmp(buffer+42,"SUPERSECRETP4SSWORD",19)==0){
			printf("Secret!\n");
			return 1;
		}
		printf("Almost.. !\n");		
	}
	return 0;
}

// path explosion
int main(int argc, char** argv){	
	char buffer[SIZE];
	read(STDIN_FILENO, buffer, SIZE);
	buffer[SIZE-1] = '\0';
	
	if (func(buffer,SIZE)){
		*((int *)0) = 0;
	}
	return 0;
}

