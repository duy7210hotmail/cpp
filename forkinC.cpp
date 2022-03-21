//#include <stdio.h> 
//#include <sys/types.h>
#include <unistd.h>
#include <iostream>

int main() {
	fork();
	printf("Fork testing code\n");
	return EXIT_SUCCESS;
}
