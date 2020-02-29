#include <stdio.h>

int i = 1;
void main()
{
	int id1;
	id1 = fork(); // id = 0 for child process

	if(id1 == 0){
		printf("Child proc, i = %d\n", i );
		i++;
		printf("Child proc (after), i = %d\n", i );
		int id2 = fork();
		printf("Child 2 ID = %d\n", id2);
		if(id2 == 0)
			printf("Second child\n");

	}
	else{
		wait();	
		printf("Parent proc, i = %d\n", i );
		i *= 3;
		printf("Parent proc (after), i = %d\n", i );
	}
}
