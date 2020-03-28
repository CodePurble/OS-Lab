#include <stdio.h>
#include <unistd.h>

main()
{
	int i, pipeDescriptor[2];
	char buffer[10];
	i = fork();
	pipe(pipeDescriptor); // Define input and output pipe descriptors
	if(i == 0){
		printf("child writing to pipe\n");
		write(pipeDescriptor[1], "Hello\n", 6);
	}
	else{
		wait();
		read(pipeDescriptor[0], &buffer, 6);
		printf("parent read\n");
		printf("pipeDescriptor[0] = %d, pipeDescriptor[1] = %d\n", pipeDescriptor[0], pipeDescriptor[1]);
		printf("%s", buffer);
	}



}

// Major limitation:
// it can only be used with related (parent-child) processes only
// Overcome by using FIFO's-> file in system -> mkfifo
