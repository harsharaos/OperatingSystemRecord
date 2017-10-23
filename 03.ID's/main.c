/*Write a C program to display Process ID, parent ID, group ID and its effective user ID?*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() 
{
	pid_t pid, ppid;
	gid_t gid;
	uid_t uid;

	/* get the process id */
	if ((pid = getpid()) < 0) {
		perror("unable to get pid");
	} else {
		printf("\n\t The process id is %d", pid);
	}

	/* get the parent process id */
	if ((ppid = getppid()) < 0) {
		perror("unable to get the ppid");
	} else {
		printf("\n\t The parent process id is %d", ppid);
	}

	/* get the group process id */
	if ((gid = getgid()) < 0) {
		perror("unable to get the group id");
	} else {
		printf("\n\t The group id is %d", gid);
	}
	/* get the user process id */
	if((uid = getuid()) < 0){
		perror("unable to get the user id");
	}	else {
		printf("\n\t The user id is %d\n", uid);
	}
	return(0);
}
