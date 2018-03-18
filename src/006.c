#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 100

#include <stdio.h>


int main(int argc, char** argv){	
	char buffer[SIZE];
	read(STDIN_FILENO, buffer, SIZE);
	buffer[SIZE-1] = '\0';

	int id = getuid();
	printf("id=%d\n",id);
	if(id == 1001){
		printf("Correct\n");
		if(strncmp (buffer+4, "CAFEBABE", 8)==0){
			printf("Secret\n");
			*((int *)0) = 0;
		}
	} else {
		printf("Wrong\n");
	}
	return 0;
}

