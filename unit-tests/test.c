#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.c"

//int		main(int ac, char **av)
//{
//	int		ret;
//	char	*p_b;
//
//	while ((ret = get_next_line(0, &p_b)) == 1)
//		if (p_b)
//			printf("%s\n", p_b);
//	if (!ret && p_b)
//		printf("%s\n", p_b);
//
//	int	fd1 = open("./test.c", O_WRONLY);
//	int	fd2 = open("./Makefile", O_WRONLY);
//	char	*p1, *p2;
//	while ((ret = get_next_line(fd1, &p1)) == 1 &&
//		(ret = get_next_line(fd2, &p2)) == 1)
//	{
//		if (p1)
//			printf("%s\n", p1);
//		if (p2)
//			printf("%s\n", p2);
//	}
//	close(fd1);
//	close(fd2);
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

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int		fd;
	int		ret;
	char	*p_b;

	fd = open("testfile", O_RDONLY);
	close(fd);
	(void)p_b;
	ret = get_next_line(-99, 0);
	return (0);
}
