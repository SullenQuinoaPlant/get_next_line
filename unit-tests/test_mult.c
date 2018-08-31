#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "get_next_line.c"

struct	file {
	char	*p_infile;
	int	fd_infile;
	int	fd_outfile;
	int	r;
};

int		main(int ac, char **av)
{
	struct file	*files;
	struct file	f;
	int		i;
	char		*p;
	int		r;


	if (!(files = malloc((ac - 1) * sizeof(struct file))))
		return (-1);
	i = 0;
	while (++i < ac)
	{
		f.p_infile = av[i];
		f.fd_infile =
			open(
				f.p_infile,
				O_RDONLY);
		f.fd_outfile = -1;
		if (p = malloc(strlen(av[i]) + 5))
		{
			sprintf(p, "%s_cpy", av[i]);
			f.fd_outfile = open(
				p, O_CREAT | O_RDWR | O_TRUNC);
			free(p);
			p = 0;
		}
		f.r = 1;
		files[i] = f;
	}

	r = 1;
	while (r == 1)
	{
		i = 0;
		while (++i < ac)
		{

			if (files[i].r != 1)
				continue;
			get_next_line(files[i].fd_infile, &p);
			if (p)
			{
				write(files[i].fd_outfile, p, strlen(p));
				free(p);
				p = 0;
				write(files[i].fd_outfile, "\n", 1);
			}
		}
		r = 0;
		i = 0;
		while (++i < ac && !r)
		{
			if (files[i].r == 1)
				r = 1;
		}
	}
	i = 0;
	while (++i < ac)
	{
		close(files[i].fd_infile);
		close(files[i].fd_outfile);
	}
	free(files);
	return (0);
}
