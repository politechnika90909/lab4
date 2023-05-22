#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char** argv) {
	int i;
	for (i = 0; i < 10; ++i){
		sleep(1);
		printf("Serwer: wysyłam linie nr %d\n", i);
	}
	fflush(stdout);
	return (EXIT_SUCCESS);
}
