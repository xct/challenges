#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/*
 * A little more dynamic.
 * Input from stdin.
 */

void print_bytes(char *buf, int len){
	int i =0;	
	while (i < len)
	{
	     printf("%02X ",(unsigned char) buf[i]);
	     i++;
	}
	printf("\n");
}

void parse_header(char *buf, int len){
	char type = buf[1];
	char pass[33] = "0ed1f373aa7243d31e20be369e299e11\0";
	int key = 16;
	if(type == 'X'){
		// AFL can find this
		printf("Type X\n");		
	}
	else if(type == 'Y'){
		int n = buf[5] - '0';
		printf("%d\n",n);	
		if (n > key){	
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
		}		
	printf("Error no type detected\n");
	}
}

int main(int argc, char** argv){	
	char buffer[20];
	read(STDIN_FILENO, buffer, 20);
	buffer[19] = '\0';
	print_bytes(buffer, strlen(buffer));
	parse_header(buffer,strlen(buffer));
	return 0;
}

