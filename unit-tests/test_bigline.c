#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "get_next_line.c"

int		main()
{
	char *line;
	int fd;
	int fd2;
    
	fd = open("testline.txt", O_RDONLY);
	fd2 = open("res.txt", O_CREAT | O_RDWR | O_TRUNC, 0755);

	while (get_next_line(fd, &line) == 1)
	{
	    write(fd2, line, strlen(line));
		if (line)
			free(line);
	    write(fd2, "\n", 1);
	}
	if (line)
	{
		write(fd2, line, strlen(line));
		free(line);
	}
	close(fd);
	close(fd2);
	return (0);
}
