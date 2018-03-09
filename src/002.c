#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parse_header(char *buf, int len){
	char type = buf[1];
	if(type == 'X'){		
		printf("Type X\n");		
	}
	else if(type == 'Y'){		
		if(strncmp (buf+10, "CAFEBABE", 8)==0){				
			volatile unsigned char *ptr = (volatile unsigned char *)0x0;
			printf("Secret!\n");
			*((int *)0) = 0;
		}
		printf("Error no type detected\n");
	}
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
	parse_header(buffer, filelen);
	fclose(fileptr);
	return 0;
}
