#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		ret;
	char	*p_b;

	while ((ret = get_next_line(0, &p_b)) == 1)
	{
		if (p_b)
			printf("%s\n", p_b);
		free(p_b);
	}

	int	fd1 = open("./test.c", O_WRONLY);
	int	fd2 = open("./Makefile", O_WRONLY);
	char	*p1, *p2;
	while ((ret = get_next_line(fd1, &p1)) == 1 &&
		(ret = get_next_line(fd2, &p2)) == 1)
	{
		if (p1)
			printf("%s\n", p1);
		free(p1);
		if (p2)
			printf("%s\n", p2);
		free(p2);
	}
	close(fd1);
	close(fd2);
	return (0);
}

//int		main(int ac, char **av)
//{
//	(void)ac;
//	(void)av;
//	int		fd;
//	int		ret;
//	char	*p_b;
//
//	fd = open("testfile", O_RDONLY);
//	p_b = 0;
//	ret = get_next_line(fd, &p_b);
//	if (p_b)
//		free(p_b);
//	ret = get_next_line(fd, &p_b);
//	if (p_b)
//		free(p_b);
//	ret = get_next_line(fd, &p_b);
//	if (p_b)
//		free(p_b);
//	ret = get_next_line(fd, &p_b);
//	if (p_b)
//		free(p_b);
//	close(fd);
//	return (0);
//}

//int		main(int ac, char **av)
//{
//	(void)ac;
//	(void)av;
//	int		fd;
//	int		ret;
//	char	*p_b;
//
//	fd = open("testfile", O_RDONLY);
//	close(fd);
//	(void)p_b;
//	ret = get_next_line(-99, 0);
//	return (0);
//}

/*
int		main(int ac, char **av)
{
		char	*line;
		int		count;
		int		ret;

#define MAX_1 10
		count = 0;
		while (1)
		{
			if (count > MAX_1 || (ret = get_next_line(0, &line)) == -1)
			{
				if (ret == -1)
					printf("error %d in get_next_line\n", errno);
				break;
			}
			count++;
			printf("line %d : %s\n", count, line);
			free(line);
		}
	return (0);
}
//*/
