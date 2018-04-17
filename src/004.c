#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

/* 
 * Challenge 004
 * This is is an example of path explosion combined with a late magic value check. The program is constructed so that symbolic execution can not solve the first part,
 * but is required to solve the second part. The analysis tool needs to combine fuzzing with symbolic execution to reach the secret compartment.
 * Even when combining fuzzing and symbolic Execution this one is hard to solve, since the "A"-Condition could place "A"s in Areas where to password check later is - 
 * which makes it unsolvable for the symbolic executor.
 */

#define SIZE 100

int func(char *buffer, int len){
	int i, count = 0;
	for(i=0;i<80;i++){
		if(buffer[i]=='A')
			count++;
	}
	printf("%d\n",count);
	if (count == 42) {
		if(strncmp(buffer+80,"SUPERSECRETP4SSWORD",19)==0){
			printf("Secret!\n");
			return 1;
		}
		printf("Almost.. !\n");		
	}
	return 0;
}

int main(int argc, char** argv){	
	char buffer[SIZE];
	read(STDIN_FILENO, buffer, SIZE);
	buffer[SIZE-1] = '\0';
	
	if (func(buffer,SIZE)){
		*((int *)0) = 0;
	}
	return 0;
}