//main is defined (see compiler invocation)
#undef main

#include "get_next_line.h"

#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"

#define MAX_1 20
int		main(int ac, char *av[])
{
	T(nop,
		(void)state;
	)
	
	T(while_1,
		char	*line;
		int		count;

		while (1)
		{
			if ((ret = get_next_line(0, &line)) == -1 || count > MAX_1)
			{
				printf("error %d in get_next_line\n", errno);
				break;
			}
			count++;
			printf("line %d : %s\n", count, line);	
		}
	)
	
    return (\
		_cmocka_run_group_tests("TEST_ARR", TEST_ARR,\
					test_index, 0, 0)\
	);
}
