/* Write a C program to display fie attributes of size, permissions, no. of blocks
 allocated and the owner for a given file.*/
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
			struct stat sb;
	 if (stat(argv[1], &sb) == -1) {
				perror("stat");
				exit(EXIT_FAILURE);
		}

	 printf("File type:\t\t");
	 switch (sb.st_mode & S_IFMT) {
				case S_IFDIR:
					printf("directory\n");
					break;
				case S_IFIFO:
					printf("FIFO/pipe\n");
					break;
				case S_IFREG:
					printf("regular file\n");
					break;
				default:
					printf("unknown?\n");
					break;
		}
		printf("I-node number:\t\t%ld\n", (long) sb.st_ino);
		printf("Mode:\t\t%lo (octal)\n",(unsigned long) sb.st_mode);
		printf("Link count:\t\t%ld\n", (long) sb.st_nlink);
		printf("Ownership:\t\tUID=%ld   GID=%ld\n",(long) sb.st_uid, (long) sb.st_gid);
		printf("Preferred I/O block size:\t%ld bytes\n",(long) sb.st_blksize);
		printf("File size:\t\t%lld bytes\n",(long long) sb.st_size);
		printf("Blocks allocated:\t\t%lld\n",(long long) sb.st_blocks);

		printf("Last status change:\t\t%s", ctime(&sb.st_ctime));
		printf("Last file access:\t\t%s", ctime(&sb.st_atime));
		printf("Last file modification:\t\t%s", ctime(&sb.st_mtime));

	 exit(EXIT_SUCCESS);

	return 0;
}
/*	execution 
	gcc main.c
	./a.out "home/user/Desktop/test.txt"
	or
	a "C:\Users\user\Desktop\test.txt"
	*/