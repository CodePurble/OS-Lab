#include <stdio.h>

void main()
{
	int id;
	printf("Before fork\n");
	id = fork(); // 0 -> child, >0 -> parent, <0 -> error
	printf("After fork, ID = %d\n", id);

}
