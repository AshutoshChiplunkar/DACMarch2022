#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 80


extern int Transform(char[], int);

int main(int argc, char* argv[])
{
	int fd;

	if(argc < 3)
		return printf("USAGE: %s source-file target-file\n", argv[0]);

	fd = open(argv[1], O_RDONLY, 0);
	if(fd != -1)
	{
		int fdo;

		fdo = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644);
		if(fdo != -1)
		{
			//char buffer[BUFSIZE];
			char* buffer = malloc(BUFSIZE);
			int n;

			do
			{
				n = read(fd, buffer, BUFSIZE);
				Transform(buffer, n);
				write(fdo, buffer, n);
			}
			while(n == BUFSIZE);

			free(buffer);
			close(fdo);
		}
		else
			printf("ERROR: Cannot create %s\n", argv[2]);

		close(fd);
	}
	else
		printf("ERROR: Cannot read from %s\n", argv[1]);
		
}

