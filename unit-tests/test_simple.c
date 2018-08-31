#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.c"

int	main(int ac, char **av)
{
	char 	*line = NULL;
	int	r;
	int	fd;
    
	if (ac != 2)
		return (-1);
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		r = 1;
		while (r == 1)
		{
			r = get_next_line(fd, &line);
			if (line)
			{
				write(1, line, strlen(line));
				//write(1, "\n", 1);
				free(line);
				line = 0;
			}
		}
			
	}
	close(fd);
	return (0);
}
