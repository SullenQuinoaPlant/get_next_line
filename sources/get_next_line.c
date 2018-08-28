/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 03:15:48 by nmauvari          #+#    #+#             */
/*   Updated: 2018/08/28 06:30:17 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>

static void	edge(char const *h_buff, size_t i, size_t count, t_s_f *s)
{
	if (count == i || (count == BUFF_SIZE && i + 1 == count))
		s->new.o_sz = 0;
	else
	{
		s->new.o_sz = count - (i + 1);
		ft_memcpy(s->new.over + OVER_SZ - s->new.o_sz, h_buff + i + 1, s->new.o_sz);
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
	return (*line);
}

static int	known_smallline(t_s_b *b_s, char **line)
{
	size_t	i;
	size_t	ii;

	i = OVER_SZ - b_s->o_sz;
	ii = i;
	while (i < OVER_SZ)
	{
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
		i++;
	}
	return (0);
}

static t_s_f *get_fd_states(int fd)
{
	static t_s_f	array[A_LOT];

	if (fd >= 0)
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
	*line = UNALLOCATED;
	if ((fd_state = get_fd_states(fd)) &&
		!(ret = known_smallline(&fd_state->old, line)) &&
		(*line = read_line(line, 0, fd_state)))
	{
		ret = 0;
		if (*line != UNALLOCATED)
		{
			i = 0;
			while (i++ < fd_state->old.o_sz)
				*--(*line) = fd_state->old.over[OVER_SZ - i];
			fd_state->old = fd_state->new;
			ret = 1;
		}
	}
	else
		*line = malloc(0);
	return (ret);
}
