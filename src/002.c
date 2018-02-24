#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * Simple magic value guarding the vulnerable code.
 * Input from file.
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
	if(type == 'X'){
		// AFL can find this
		printf("Type X\n");		
	}
	else if(type == 'Y'){
		// AFL can find this
		if(strncmp (buf+10, "CAFEBABE", 8)==0){
			// AFL has a very low chance to find this path on its own, however angr can solve this with full exploration easily			
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
	print_bytes(buffer, filelen);
	parse_header(buffer, filelen);
	fclose(fileptr);
	return 0;
}
