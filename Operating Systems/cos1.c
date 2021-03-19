#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int f;

int main(void)
{
	printf("\nProgram running: PID = %d \n", getpid());
	f = fork();

	if(f == 0) // child
	{
		printf("\nChild process: my parent pid = %d\n", getpid());
		sleep(2);
		exit(0);
	}
	else // parent
	{
		printf("\nParent process: my pid = %d\n", getpid());
		printf("Parent process: my parent pid = %d\n", getpid());
		printf("Parent process: my child's pid = %d\n", f);
		sleep(2);
		exit(0);
	}
	return(0);
}