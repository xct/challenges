#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void calc(int a, int b, int c){
	if(a < 5)
		if(b + a > 10)
			if(a + c - 5 == 3)
				printf("%d, %d, %d",a,b,c);
}

int main(int argc, char** argv){	
	char buffer[20];
	read(STDIN_FILENO, buffer, 20);
	buffer[19] = '\0';
	int a = buffer[0] - '0';
	int b = buffer[1] - '0';
	int c = buffer[2] - '0';
	calc(a, b, c);
	return 0;
}
