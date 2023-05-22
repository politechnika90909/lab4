#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 2048


int main(int argc, char** argv) {
	int fd[2];
	pid_t pid;
	char bufor[BUF_SIZE];
	
	
	if(pipe(fd) == -1){
		printf("Błąd\n");
		exit(1);
	}
	
	pid = fork();
	
	
	// proces macierzyty
	if(pid > 0){
		close(fd[1]);
		
		while(read(fd[0], bufor, BUF_SIZE) > 0){
			printf("odebrano: %s\n", bufor);
		}
		
		close(fd[0]);
	}
	else{
		close(fd[0]);
		char text[22];
		

        	for (int i = 0; i < 10; i++) {
        		sleep(1);
        		sprintf(text, "%s %d", "wartosc", i);
            		write(fd[1], text, strlen(text));
        	}

        	close(fd[1]);
	
	}
}
