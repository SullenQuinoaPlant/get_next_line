/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 03:15:48 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/10 15:01:38 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		edge(char const *h_buff, size_t i, size_t count, t_s_fs *s)
{
	size_t const	ip1 = i + 1;
	size_t			o_sz;

	if (count == i || (count == BUFF_SIZE && ip1 == count))
		s->new.o_sz = 0;
	else
	{
		o_sz = count - ip1;
		s->new.o_sz = o_sz;
		ft_memcpy(s->new.over + OVER_SZ - o_sz, h_buff + ip1, o_sz);
	}
}

static char		*read_line(char **line, int rank, t_s_fs *s)
{
	char	h_buff[BUFF_SIZE];
	size_t	count;
	size_t	i;

	if ((count = read(s->fildes, h_buff, BUFF_SIZE)) != ERROR &&
			(count || rank || s->old.o_sz))
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

static int		known_smallline(t_s_fs *fb_s, char **line)
{
	size_t const	sz = fd_s->old.sz;
	char *const		p = fd_s->old.over;;
	size_t	i;
	size_t	smallline_sz;

	i = -1;
	while (++i < sz)
		if (p[i] == EOL)
		{
			if ((*line = malloc(i)))
			{
				b_s->o_sz -= smallline_sz;
				(*line)[--smallline_sz] = '\0';
				while (smallline_sz--)
					(*line)[smallline_sz] = b_s->over[--i];
			}
			else
				return (-1);
			edge(p, i, fb_s);
			return (1);
		}
	return (0);
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

static t_s_fs	*get_fd_state(int fd)
{
	static t_s_fs	anchor = (t_s_fs){-1, (t_s_b){0, 0}, 0};
	t_s_fs			*p;
	t_s_fs			*prev;
	char			c;

	if (fd < 0)
		return (0);
	p = &anchor;
	while (p->fd != fd && (prev = p))
		p = p->nxt;
	if (p)
		prev->nxt = p->nxt;
	else if (!p && read(fd, &c, 0))
		return (0);
	else if (!(p = malloc(sizeof(t_s_fs))))
		return (0);
	else
		*p = {fd, (t_s_b){0, 0}, 0};
	p->nxt = anchor->nxt;
	anchor->nxt = p;
	return (p);
}

int				get_next_line(const int fd, char **line)
{
	int		ret;
	t_s_fs	*fd_state;
	size_t	i;

	ret = -1;
	if (!line)
		return (ret);
	*line = UNALLOCATED;
	if ((fd_state = get_fd_state(fd)) &&
			!(ret = known_smallline(fd_state, line)) &&
			(ret = read_line(line, 0, fd_state) != -1 &&
			*line != UNALLOCATED)
		return (1)
	else if (*line == UNALLOCATED)
		*line = 0;
	return (ret);
}
