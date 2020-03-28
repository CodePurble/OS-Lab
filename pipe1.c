#include <stdio.h>
#include <unistd.h>

main()
{
	int i, pipeDescriptor[2];
	char buffer[10];

	pipe(pipeDescriptor); // Define input and output pipe descriptors
	printf("pipeDescriptor[0] = %d, pipeDescriptor[1] = %d/n", pipeDescriptor[0], pipeDescriptor[1]);

	write(pipeDescriptor[1], "Hello\n", 6);
	read(pipeDescriptor[0], &buffer, 6);

	printf("%s", buffer);
}
