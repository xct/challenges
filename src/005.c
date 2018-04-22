#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

/* 
 * Challenge 005
 * This is the same as 004 however with a twist. Even when combining fuzzing and symbolic Execution this one is very hard to solve, 
 * the "A"-Condition could place "A"s in Areas where to password check later is, which makes it unsolvable for the symbolic executor. Also no length is enforced which makes it a matter of luck
 * weather afl generates files large enough.
 */

#define SIZE 100

int func(char *buffer, int len){
	int i, count = 0;
	for(i=0;i<len;i++){
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
