//main is defined (see compiler invocation)
#undef main

#include "get_next_line.h"

#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"


int		main(void)
{
	T(nop,
		ft_putstr("hello world\n");
	)
    return (\
		_cmocka_run_group_tests("TEST_ARR", TEST_ARR,\
					test_index, 0, 0)\
	);
}
