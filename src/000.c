#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parse_header(char *buf){
		if(strncmp (buf+10, "CAFEBABE", 8)==0){			
			printf("Secret!\n");
			*((int *)0) = 0;
		}	
}

int main(int argc, char** argv){	
	char buffer[20];
	read(STDIN_FILENO, buffer, 20);
	buffer[19] = '\0';
	parse_header(buffer);
	return 0;
}
