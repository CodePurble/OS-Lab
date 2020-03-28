#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void mySig(int signum)
{
	printf(" signal received %d\n", sigNum);
	exit(0);
}

void main(int argc, char* argv[])
{
	int i = atoi(argv[1]);
	if(argc <= 1){
		fprintf(stderr, "Please pass a valid integer parameter");
		exit(0);
	}
	signal(SIGALRM, mySig);
	printf(" Sleeping for %d seconds\n", i);
	alarm(i); // Halt for i seconds
	pause(); // Wait for interrupt
}
