#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 2048


int main(int argc, char** argv) {
	/* trying to run command */
	FILE *command_result = popen("./serwer", "r");
	if (command_result) {
		char bufor[BUF_SIZE];
		/* reading output line */
		fgets(bufor, BUF_SIZE, command_result);
		
		/* if "file" was not finished */
		while (!feof(command_result)) {
			printf("%c\n", bufor[strlen(bufor) - 2]);
			fgets(bufor, BUF_SIZE, command_result);
			//fread(bufor, sizeof(char), 0, command_result);
			
		}
		/* end of readiing results */
		pclose(command_result);
		fflush(stdout);
		return EXIT_SUCCESS;
	}
	else {
		printf("Niepowodzenie funkcji popen \n");
		fflush(stdout);
		return EXIT_FAILURE;
	}
}
