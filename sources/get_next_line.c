/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 03:15:48 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/10 15:27:36 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		edge(char const *buff, size_t b_len, 
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
	char *const		strt = fd_s->old.p_b;
	char *const		lim = fd_s->old.buffer + fd_s->old.b_sz;;
	size_t			sz;
	char			*p;

	p = strt;
	while (p < lim)
		if (*p == EOL)
		{
			sz = p - strt + 1;
			if (sz && !(*line = malloc(sz)))
				return (-1);
			ft_strncpy(*line, strt, sz - 1);
			(*line)[sz - 1] = '\0';
			edge(fb_s, 
			return (1);
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
