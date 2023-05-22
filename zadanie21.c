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
	pid_t pid;
	char bufor[BUF_SIZE];
	char *path = "./rura";
	
	mkfifo(path, 0666);
	
	
	pid = fork();
	
	
	// proces macierzyty
	if(pid > 0){
		fd = open(path, O_RDONLY);
		
		
		while(read(fd, bufor, BUF_SIZE) > 0){
			printf("odebrano: %s\n", bufor);
		}
		
		close(fd);
	}
	else{
		fd = open(path, O_WRONLY);
		char text[22];
		

        	for (int i = 0; i < 10; i++) {
        		sleep(1);
        		sprintf(text, "%s %d", "wartosc", i);
            		write(fd, text, strlen(text));
        	}

        	close(fd);
        	unlink(path);
	
	}
}
