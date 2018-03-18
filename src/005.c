#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 100

int parse_header(char *buf, int len){
	int a = buf[0] - '0';
	int b = buf[1] - '0';
	printf("a = %d\n",a);
	printf("b = %d\n",b);
	while(a--){
		while(b--){			
			if (a+b == 8){
				printf("Almost..\n");
				if(strncmp (buf+2, "CAFEBABE", 8)==0){				
					printf("Secret!\n");					
					return 1;
				} else {
					return 0;
				}				
			}
		}
	}
	return 0;
}

int main(int argc, char** argv){	
	char buffer[SIZE];
	read(STDIN_FILENO, buffer, SIZE);
	buffer[SIZE-1] = '\0';
	if(parse_header(buffer,strlen(buffer))){
		*((int *)0) = 0;
	}
	return 0;
}

