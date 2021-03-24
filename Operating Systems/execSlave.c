#include <unistd.h> // fork, exec, getpid
#include <stdio.h> 
#include <stdlib.h> // exit
#include <sys/wait.h> // wait
#include <errno.h> // errno
#include <string.h> // strerror

int main(int argc, char* argv[])
{
	printf("\nSlave started working ... PID: %d \n", getpid());
	printf("Name of the program : %s \n", argv[0]);
	printf("The first parameter of the program: %s \n", argv[1]);
	printf("The second parameter of the program: %s \n", argv[2]);

	sleep(3);
	return 0;
}