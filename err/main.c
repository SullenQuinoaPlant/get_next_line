#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *line;

//	get_next_line(5, &line);
//	printf("->%s\n", line);

	printf ("b s : %d", BUFF_SIZE);
	fflush(stdout);
	int fd = 0;
	fd = open("t.txt", O_RDONLY);
	while ((get_next_line(fd, &line)) == 1)
	{
		printf("->%s\n", line);
	}
	return (0);
}
