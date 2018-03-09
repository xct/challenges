#include <stdlib.h>
#include <magic.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){
	char buffer[100];
	read(STDIN_FILENO, buffer, 100);
	buffer[99] = '\0';

	magic_t myt = magic_open(MAGIC_CONTINUE|MAGIC_ERROR/*|MAGIC_DEBUG*/|MAGIC_MIME);
    magic_load(myt,NULL);
    printf("magic output: '%s'\n",magic_buffer(myt, buffer, 100));
    magic_close(myt);
	return 0;
}
