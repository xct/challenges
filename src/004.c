#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* 
 * Challenge 004
 * This is an example that is easy to solve with symbolic execution. We have 2 loops that were the number of cycles is dependend on the user input.
 */

#define SIZE 100

int func(char *buf, int len){
	int a = buf[0] - '0';
	int b = buf[1] - '0';
	printf("a = %d\n",a);
	printf("b = %d\n",b);
	while(a--){
		while(b--){			
			if (a+b == 8){		
				printf("Secret!\n");		
				return 1;
			} else {
				return 0;
			}				
		}
	}	
	return 0;
}

int main(int argc, char** argv){	
	char buffer[SIZE];
	read(STDIN_FILENO, buffer, SIZE);
	buffer[SIZE-1] = '\0';
	if(func(buffer,strlen(buffer))){
		*((int *)0) = 0;
	}
	return 0;
}
