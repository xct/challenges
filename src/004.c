#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

/* 
 * Challenge 004
 * This is is an example of path explosion combined with a late magic value check. The program is constructed so that symbolic execution can not solve the first part,
 * but is required to solve the second part. The analysis tool needs to combine fuzzing with symbolic execution to reach the secret compartment. The length is forced here, else this would
 * be hard to solve when afl cuts of testcases because it does not know about the later check.
 */

#define SIZE 100

int func(char *buffer, int len){
	int i, count = 0;	
	for(i=0;i<80;i++){
		if(buffer[i]=='A')
			count++;
	}	
	printf("%d\n",count);
	if (count == 42) {
		if(strncmp(buffer+80,"SUPERSECRETP4SSWORD",19)==0){
			printf("Secret!\n");
			return 1;
		}
		printf("Almost.. !\n");		
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
	if(filelen < 100)
		return 0;
	if(func(buffer, filelen)){
		*((int *)0) = 0;
	}
	fclose(fileptr);
	return 0;
}