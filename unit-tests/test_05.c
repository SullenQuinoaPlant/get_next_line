#include "get_next_line.c"

int	main()
{
	char 	*line = NULL;
	int	r;
    
	r = get_next_line(-99, NULL) == -1;
	r = get_next_line(-1, NULL) == -1;
	r = get_next_line(-10000, NULL) == -1;
	r = get_next_line(1, NULL) == -1;
	r = get_next_line(99, NULL) == -1;
	r = get_next_line(-99, &line) == -1;
	r = get_next_line(-1, &line) == -1;
	r = get_next_line(-10000, &line) == -1;
	r = get_next_line(42, &line) == -1;

	return (0);
}
