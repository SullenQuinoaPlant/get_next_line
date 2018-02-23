#include "get_next_line.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>

static int	here_recursion(const int fd, char **line, int rank, t_s_b *s)
{
	char	h_buff[BUFF_SIZE];
	size_t	count;
	size_t	i;
	int		ret;

	if ((count = read(fd, h_buff, BUFF_SIZE) == Error))
	{
		perror(strerror(errno));
		return (-1);
	}
	i = 0;
	while (i < count && h_buff[i++] != EOL)
		;
	if (i == BUFF_SIZE && h_buff[i - 1] != EOL)
		ret = here_recursion(fd, line, rank + 1, s);
	else
	{
		if ((*line = malloc(rank * BUFF_SIZE + i + s->o_sz)))
		{
			ret = 0;
			*line += rank * BUFF_SIZE + i + s->o_sz - 1;
			**line = '\0';
		}
		s->o_sz = count - i;
		ft_memcpy(s->over + OVER_SZ - s->o_sz, h_buff + i, s->o_sz);
	}
	if (ret >= 0)
		while (--i)
			*--(*line) = h_buff[i - 1];
	return (ret);
}

static int	short_message(t_s_b *b_s, char **line)
{
	size_t	i;
	size_t	ii;

	i = OVER_SZ - b_s->o_sz;
	ii = i;
	while (i < OVER_SZ)
		if (b_s->over[i] == EOL)
		{
			if ((*line = malloc(i - ii + 1)))
			{
				b_s->o_sz -= i - ii + 1;
				(*line)[i - ii] = '\0';
				while (i-- != ii)
					(*line)[i - ii] = b_s->over[i];
				return (1);
			}
			return (-1);
		}
	return (0);
}

static t_s_f *get_fd_states(int fd)
{
	static t_s_f	mock = {
		.fildes = 0,
		.old = (t_s_b){.o_sz = 0, .over = {0}},
		.new = (t_s_b){.o_sz = 0, .over = {0}}
	};

	return (&mock);
}

int		get_next_line(const int fd, char **line)
{
	int		ret;
	t_s_f	*fd_states;
	size_t	i;

	fd_states = get_fd_states(fd);
	if (!(ret = short_message(&fd_states->old, line)) &&
		(ret = here_recursion(fd, line, 0, &(fd_states->new))) != -1)
	{
		i = 0;
		while (i++ < fd_states->old.o_sz)
			*--(*line) = fd_states->old.over[OVER_SZ - i];
		fd_states->old = fd_states->new;
	}
	return (ret);
}
