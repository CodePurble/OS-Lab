#include <stdio.h>

void main()
{
	int id;
	id = fork();
	if(id == 0)
		printf("Child proc, PPID = %d, PID = %d\n", getppid(), getpid());
	else{
		wait();	
		printf("Parent proc, PPID = %d, PID = %d\n", getppid(), getpid());

	}
}
