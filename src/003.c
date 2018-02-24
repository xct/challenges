#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * This is purposly build to lead to path explosion so angr in explore mode can't solve this. 
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
	char pass[9] = "CAFEBABE\0";
	if(type == 'X'){
		// AFL can find this
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
		// AFL can find this		
		if(strncmp (buf+10, pass, 8)==0){
			// AFL has a very low chance to find this path on its own, however angr can solve this with full exploration easily			
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
	print_bytes(buffer, strlen(buffer));
	parse_header(buffer,strlen(buffer));
	return 0;
}

