/*
Write a C program that asks the user to type an integer ‘n’ and then create a child process.
The child process will compute the factorial of ‘n’and return that value to the parent and then
the parent will display “The factorial of <number> is: <value>”
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int fd[2];
	int n,i;
	double result=1,r1;
	// create pipe descriptors
	pipe(fd);
	// fork() returns 0 for child process, child-pid for parent process.
	if (fork() == 0)
	{
		printf("find factorial of :\n");
		scanf("%d",&n);//take the number
		for(i=1; i<=n; ++i)
		{
			result *= i;              // result = result*i;
		}
		close(fd[0]);
		write(fd[1], &n, sizeof(n));
		write(fd[1], &result, sizeof(result));
		// close the write descriptor
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		// now read the data (will block)
		read(fd[0], &n, sizeof(n));
		read(fd[0], &r1, sizeof(r1));
		printf("The factorial of %d is: %.0f\n",n, r1 );
		// close the read-descriptor
		close(fd[0]);
	}
	return 0;
}
/*
	gcc main.c
	./a.out
	(or)
	a
	find factorial of : 4
	the factorial of 4 is : 24
*/