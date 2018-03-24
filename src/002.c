#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* 
 * Challenge 002
 * This is an example that is very easy to solve with symbolic execution. The difference compared to 001 is that the input is now coming from a file instead of stdin.
 */

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
	FILE *fileptr;
	char *buffer;
	long filelen;
	fileptr = fopen(argv[1], "rb");
	if (!fileptr){
		printf("Could not open file\n");
		return 1;
	}
	fseek(fileptr, 0, SEEK_END);          
	filelen = ftell(fileptr);             
	rewind(fileptr);                     
	buffer = (char *)malloc((filelen+1)*sizeof(char));
	fread(buffer, filelen, 1, fileptr);
	printf("Successfully read file\n");	
	if(func(buffer, filelen)){
		*((int *)0) = 0;
	}
	fclose(fileptr);
	return 0;
}
