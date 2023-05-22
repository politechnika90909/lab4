#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define BUF_SIZE 2048


int main(int argc, char** argv) {
	int fd;
	char bufor[BUF_SIZE];
	char *path = "./rura2";
	char text[20];
	
	
	mkfifo(path, 0666);
	fd = open(path, O_WRONLY);
	

	for (int i = 0; i < 10; ++i){
		
        	sprintf(text, "%s %d\n", "wartosc", i);
            	write(fd, text, strlen(text));
            	sleep(1);
	}
	
	
	close(fd);
	
	unlink(path);
	printf("serwer\n");
	
	return 0;
}
