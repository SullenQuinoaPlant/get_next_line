//# pragma GCC system_header

#ifndef MY_MACRO_OVERLAY
# define MY_MACRO_OVERLAY

# include <stdarg.h>
# include <stddef.h>
# include <setjmp.h>
# include <cmocka.h>

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# ifndef HOW_MANY_TESTS
#  define HOW_MANY_TESTS 500
# endif

# define TEST_ARR tests

struct CMUnitTest	TEST_ARR[HOW_MANY_TESTS];
size_t				test_index = 0;

//This didn't work (sad) can't forward declare functions within functions
// the forward declared function gets promoted to 'static' and 
// defining static function whithin function is not allowed. 
// couldn't figure out a way to make the forward declaration work
//# define T(x) \
//			void x(void* *);\
//			TEST_ARR[test_index++] = (struct CMUnitTest)cmocka_unit_test(x);\
//			void x(void* *state){

# define T(test_name, test_code) \
	void	test_name(void* *state) {\
		test_code\
	};TEST_ARR[test_index++] = (struct CMUnitTest)cmocka_unit_test(test_name);

# define T_D(test_name, tear_down, test_code) \
	void	test_name(void* *state) {\
		test_code\
	};TEST_ARR[test_index++] = (struct CMUnitTest)cmocka_unit_test_teardown(test_name, tear_down);



static int		search_test_arr_by_name(const char *t_name)
{
	size_t	i;

	i = 0;
	while (i < HOW_MANY_TESTS)
	{
		if (!strcmp(t_name, TEST_ARR[i].name))
			return (i);
		i++;
	}
	return (0);
}

static int		search_test_arr(const char *search_for)
{
	int		ret;

	if ((ret = search_test_arr_by_name(search_for)))
		return (ret);
	else
		return ((ret = atoi(search_for)) < HOW_MANY_TESTS ? ret : 0);
}

static int		run_test_arr(int ac, char *av[])
{
	if (ac == 2)
	{
	    return (
			_cmocka_run_group_tests(
						"TEST_ARR", TEST_ARR,
						test_index, 0, 0
			)
		);
	}
	else if (ac > 2)
	{
		int		i;
		int		test_index;
		int		ret_value;

		i = 1;
		ret_value = 0;
		while (++i < ac)
		{
			test_index = search_test_arr(av[i]);
			ret_value += _cmocka_run_group_tests(av[i], &TEST_ARR[test_index], 1, 0, 0);
		}
		return (ret_value);
	}
}
	
#endif
