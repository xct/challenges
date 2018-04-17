#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* 
 * Challenge 003
 */

#define SIZE 100

int func(char *buf, int len){
	char type = buf[1];
	char pass[9] = "CAFEBABE\0";
	if(type == 'X'){		
		printf("Type X\n");		
	}
	else if(type == 'Y'){
		int n = buf[5] - '0';
		printf("%d\n",n);		
		while (n) {
			n--;			
			pass[n]++;			
		}
		printf("%s\n",pass);			
		if(strncmp (buf+10, pass, 8)==0){				
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

