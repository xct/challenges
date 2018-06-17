#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * Challenge 000 
 * This is an example that is very easy to solve with symbolic execution.
 */

#define SIZE 100

int func(char *buf){
		if(strncmp (buf+10, "CAFEBABE", 8)==0){			
			printf("Secret!\n");
			return 1;
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
	if(filelen < 18)
		return 0;
	if(func(buffer)){
		*((int *)0) = 0;
	}
	fclose(fileptr);
	return 0;
}