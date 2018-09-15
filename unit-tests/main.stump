//main is defined (see compiler invocation)
#undef main

#include "get_next_line.h"

#include <stdio.h>

int		main(void)
{
	char	*p;
	int		r;

	while ((r = get_next_line(0, &p)) == 1)
	{
		printf("%s\n", p);
		free(p);
	}
	return (0);
}
