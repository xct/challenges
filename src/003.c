#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* 
 * Challenge 003
 */

#define SIZE 100

int func(char *buf, int len){
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
	if(filelen < 18)
		return 0;
	if(func(buffer, filelen)){
		*((int *)0) = 0;
	}
	fclose(fileptr);
	return 0;
}

