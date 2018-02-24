//main is defined (see compiler invocation)
#undef main

#include "get_next_line.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"

#define MAX_1 20
#define	PATH_SZ 1024

int		main(int ac, char *av[])
{
	char	f_path[PATH_SZ] = {0};
	size_t	f_name_sz;
	size_t	f_name_off;

	if (ac < 2)
	{
		printf("test suite requires path to test directory as\
				first argument\n");
		return (1);
	}
	else
	{
		strncpy(f_path, av[1], PATH_SZ - 1);
		f_name_off = strlen(f_path);
		f_name_sz = PATH_SZ - f_name_off - 1;
	}

	T(nop,
		(void)state;
	)

	T(bad_fildes_1,
		char	*line;
		int		ret;

		ret = get_next_line(-1, &line);
		printf("\n");
		assert_int_equal(ret, -1);
	)

	T(bad_fildes_2,
		char	*line;
		int		ret;
		int		bad_fd;

		strncpy(f_path + f_name_off, "/dummy_file", f_name_sz);
		bad_fd = open(f_path, O_RDONLY);
		if ((close(bad_fd)) != -1)
		{
			ret = get_next_line(bad_fd, &line);
			assert_int_equal(ret, -1);
			printf("\n");
		}
		else
			fail();
	)

	T(dummy_file,
		char	*line;
		int		ret;
		int		fd;

		strncpy(f_path + f_name_off, "/dummy_file", f_name_sz);
		fd = open(f_path, O_RDONLY);
		if ((fd = open("dummy_file", O_RDONLY)) != -1)
		{
			ret = get_next_line(fd, &line);
			assert_int_equal(ret, 0);
			printf("line: %s\n", line);
			close(fd);
		}
		else
		{
			printf("fildes not opened\n");
			fail();
		}
	)
	
	T(while_1,
		char	*line;
		int		count;
		int		ret;

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
	return (run_test_arr(ac, av));
}
