#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parse_header(char *buf, int len){
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
			volatile unsigned char *ptr = (volatile unsigned char *)0x0;
			printf("Secret!\n");
			*((int *)0) = 0;
		}
		printf("Error no type detected\n");
	}
}

int main(int argc, char** argv){	
	char buffer[20];
	read(STDIN_FILENO, buffer, 20);
	buffer[19] = '\0';
	parse_header(buffer,strlen(buffer));
	return 0;
}

