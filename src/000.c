#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * Challenge 000 
 * This is an example that is very easy to solve with symbolic execution.
 */

#define SIZE 100

int func(char *buf){
		if(strncmp (buf+10, "CAFEBABE", 8)==0){			
			printf("Secret!\n");
			return 1;
		}	
	return 0;
}

int main(int argc, char** argv){	
	char buffer[SIZE];
	int len = read(STDIN_FILENO, buffer, SIZE);
	buffer[len] = '\0';
	if(func(buffer)){
		*((int *)0) = 0;
	}
	return 0;
}
