/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 03:15:48 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/01 03:12:42 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>

static void	edge(char const *h_buff, size_t i, size_t count, t_s_f *s)
{
	size_t		const ip1 = i + 1;
	size_t		o_sz;

	if (count == i || (count == BUFF_SIZE && ip1 == count))
		s->new.o_sz = 0;
	else
	{
		o_sz = count - ip1;
		s->new.o_sz = o_sz;
		ft_memcpy(s->new.over + OVER_SZ - o_sz, h_buff + ip1, o_sz);
	}
}

static char	*read_line(char **line, int rank, t_s_f *s)
{
	char	h_buff[BUFF_SIZE];
	size_t	count;
	size_t	i;

	if ((count = read(s->fildes, h_buff, BUFF_SIZE)) != ERROR && (count || rank))
	{
		i = 0;
		while (i < count && h_buff[i] != EOL)
			i++;
		if (i == BUFF_SIZE)
			read_line(line, rank + 1, s);
		else if ((*line = malloc(rank * BUFF_SIZE + i + s->old.o_sz + 1)))
		{
			edge(h_buff, i, count, s);
			*line += rank * BUFF_SIZE + i + s->old.o_sz;
			**line = '\0';
		}
		if (*line)
			while (i--)
				*--(*line) = h_buff[i];
	}
	else if (count == ERROR)
		*line = 0;
	return (*line);
}

static int	known_smallline(t_s_b *b_s, char **line)
{
	size_t	i;
	size_t	ii;
	size_t	smallline_sz;

	i = OVER_SZ - b_s->o_sz;
	ii = i;
	while (i < OVER_SZ)
	{
		if (b_s->over[i] == EOL)
		{
			smallline_sz = i - ii + 1;
			if ((*line = malloc(smallline_sz)))
			{
				b_s->o_sz -= smallline_sz;
				(*line)[--smallline_sz] = '\0';
				while (smallline_sz--)
					(*line)[smallline_sz] = b_s->over[--i];
				return (1);
			}
			return (-1);
		}
		i++;
	}
	return (0);
}

static t_s_f *get_fd_states(int fd)
{
	static t_s_f	array[A_LOT];
	char		c;

	if (fd >= 0 && fd < A_LOT && !read(fd, &c, 0))
	{
		array[fd].fildes = fd;
		return (array + fd);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int		ret;
	t_s_f	*fd_state;
	size_t	i;

	ret = -1;
	if (!line)
		return (ret);
	*line = UNALLOCATED;
	if ((fd_state = get_fd_states(fd)) &&
		!(ret = known_smallline(&fd_state->old, line)) &&
		(ret = read_line(line, 0, fd_state) ? 0 : -1) != -1 &&
		*line != UNALLOCATED)
	{
		i = 0;
		while (i++ < fd_state->old.o_sz)
			*--(*line) = fd_state->old.over[OVER_SZ - i];
		fd_state->old = fd_state->new;
		ret = 1;
	}
	else if (*line == UNALLOCATED)
		*line = 0;
	return (ret);
}
