//main is defined (see compiler invocation)
#undef main

#include "get_next_line.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"

#define MAX_1 10
#define	PATH_SZ 1024

int		main(int ac, char *av[])
{
	char	f_path[PATH_SZ] = {0};
	size_t	f_name_sz;
	size_t	f_name_off;

	if (ac < 2)
	{
		printf("test suite requires path to test directory as "
				"first argument\n");
		return (1);
	}
	else
	{
		strncpy(f_path, av[1], PATH_SZ - 1);
		f_name_off = strlen(f_path);
		f_name_sz = PATH_SZ - f_name_off - 1;
	}

	int	td(void * *state)
	{
		char	*placeholder;

		get_next_line(-1, &placeholder);
		free(placeholder);
		return (0);
	}

	T_D(bad_fildes_1, td,
		char	*line;
		int		ret;

		ret = get_next_line(-1, &line);
		free(line);
		printf("\n");
		assert_int_equal(ret, -1);
	)

	T_D(bad_fildes_2, td,
		char	*line;
		int		ret;
		int		bad_fd;

		strncpy(f_path + f_name_off, "/dummy_file", f_name_sz);
		bad_fd = open(f_path, O_RDONLY);
		if ((close(bad_fd)) != -1)
		{
			ret = get_next_line(bad_fd, &line);
			assert_int_equal(ret, -1);
			free(line);
			printf("\n");
		}
		else
			fail();
	)

	T_D(dummy_file, td,
		char	*line;
		int		ret;
		int		fd;

		strncpy(f_path + f_name_off, "/dummy_file", f_name_sz);
		printf("file path to open : %s\n", f_path);
		if ((fd = open(f_path, O_RDONLY)) != -1)
		{
			ret = get_next_line(fd, &line);
			printf("line: %s\n", line);
			free(line);
			assert_int_equal(ret, 1);
			ret = get_next_line(fd, &line);
			printf("line: %s\n", line);
			free(line);
			assert_int_equal(ret, 0);
		}
		else
		{
			printf("fildes not opened\n");
			fail();
		}
	)

	T_D(dummy_file_2, td,
		char	*line;
		int		ret;
		int		fd;

		strncpy(f_path + f_name_off, "/dummy_file_2", f_name_sz);
		printf("file path to open : %s\n", f_path);
		if ((fd = open(f_path, O_RDONLY)) != -1)
		{
			ret = get_next_line(fd, &line);
			printf("line: %s\n", line);
			free(line);
			close(fd);
			assert_int_equal(ret, 1);
		}
		else
		{
			printf("fildes not opened\n");
			fail();
		}
	)

	T_D(dummy_file_2_to_end, td,
		char	*line;
		int		ret;
		int		fd;

		strncpy(f_path + f_name_off, "/dummy_file_2", f_name_sz);
		printf("file path to open : %s\n", f_path);
		if ((fd = open(f_path, O_RDONLY)) != -1)
		{
			while ((ret = get_next_line(fd, &line)))
			{
				
				printf("line: %s\n", line);
				free(line);
			}
			close(fd);
			assert_int_equal(ret, 0);
		}
		else
		{
			printf("fildes not opened\n");
			fail();
		}
	)

	T_D(while_1, td,
		char	*line;
		int		count;
		int		ret;

		count = 0;
		while (1)
		{
			if (count > MAX_1)
				break ;
			if ((ret = get_next_line(0, &line)) == -1)
			{
				printf("error %d in get_next_line\n", errno);
				break;
			}
			count++;
			printf("line %d : %s\n", count, line);
			//free(line);
		}
	)
	return (run_test_arr(ac, av));
}
