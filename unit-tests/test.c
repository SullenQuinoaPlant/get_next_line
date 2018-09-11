#include <unistd.h>
#include <string.h>

#include "get_next_line.c"

int		main()
{
	char *line;
    
	while (get_next_line(0, &line) == 1)
	{
	    write(1, line, strlen(line));
		if (line)
			free(line);
	    write(1, "\n", 1);
	}
	return (0);
}
