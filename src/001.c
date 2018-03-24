#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* 
 * Challenge 001
 * This is an example that is very easy to solve with symbolic execution. Compared to 000 2 more branches were added.
 */

#define SIZE 100

int func(char *buf, int len){
	char type = buf[1];
	if(type == 'X'){		
		printf("Type X\n");		
	}
	else if(type == 'Y'){		
		if(strncmp (buf+10, "CAFEBABE", 8)==0){					
			printf("Secret!\n");
			return 1;
		}
		printf("Error no type detected\n");
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
