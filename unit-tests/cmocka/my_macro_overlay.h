//# pragma GCC system_header

#ifndef MY_MACRO_OVERLAY
# define MY_MACRO_OVERLAY

# include <stdarg.h>
# include <stddef.h>
# include <setjmp.h>
# include <cmocka.h>

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
	
#endif
