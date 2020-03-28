#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void mySignal(int signum)
{
	printf("\nCaught signal %d\n", signum);
	sleep(2);
	/* signal(SIGINT, SIG_DFL); // Perform default action */
	signal(SIGINT, SIG_IGN); // Ignore SIGINT
}

void main()
{
	int i;
	signal(SIGINT /* signal name */, mySignal /* signal handler */); 
	// SIGKILL cannot be captured
	// Other signals - SIGFPE, SIGSEGV, etc.
	for(i = 0; i < 10; i++){
		printf("press ctrl-c\n");
		sleep(1);
	}
}
