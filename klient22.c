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
	
	
	mkfifo(path, 0666);
	fd = open(path, O_RDONLY);
	
	
	while(read(fd, bufor, sizeof(bufor)) > 0){
		
		printf("odebrano: %s\n", bufor);
		sleep(1);
	}
	
	close(fd);
	unlink(path);
	
	return 0;
}

// uruchomic w oddzielnych terminalach najpierw serwer potem klient

//gcc -c serwer22.c -o serwer.o; gcc -o serwer serwer.o; gcc -c klient22.c -o klient.o; gcc -o klient klient.o
