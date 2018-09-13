/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 03:15:48 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/12 15:03:49 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_s_fs	*get_set_fd_state(int get, t_s_fs *set)
{
	static t_s_fs	anchor = (t_s_fs){-1, 0, 0, 0, 0, 0};
	t_s_fs			*p;
	t_s_fs			*prev;
	char			c;

	if ((p = set))
	{
		set->nxt = anchor.nxt;
		anchor.nxt = set;
	}
	else if (get >= 0)
	{
		p = &anchor;
		while (p && p->fd != get && (prev = p))
			p = p->nxt;
		if (p)
			prev->nxt = p->nxt;
		else if ((p = !read(get, &c, 0) ? malloc(sizeof(t_s_fs)) : 0))
			*p = (t_s_fs){get, 0, 0, 0, 0, 0};
	}
	return (p);
}

static int		case_edge(char const *last_b, size_t i, size_t rd_sz, int fd)
{
	size_t			len;
	t_s_fs			*new_s;

	if (rd_sz == i)
		return (0);
	len = rd_sz - i;
	if ((new_s = malloc(sizeof(t_s_fs))) &&
		(new_s->buf = malloc(len)))
	{
		*new_s = (t_s_fs){fd, new_s->buf, len, new_s->buf, len, 0};
		ft_memcpy(new_s->buf, last_b + i, len);
		get_set_fd_state(SET_FD, new_s);
		return (0);
	}
	else
		free(new_s);
	return (-1);
}

static int		read_line(char **ret, int rank, t_s_fs *fd)
{
	char	*buf;
	size_t	sz;
	size_t	i;
	int		r;

	r = 0;
	if (!(buf = malloc(BUFF_SIZE)) ||
		(sz = read(fd->fd, buf, BUFF_SIZE)) == (size_t)-1)
		r = -1;
	i = 0;
	if (!r)
		while (i < sz && buf[i++] != EOL)
			;
	if (!r && !(r = i == BUFF_SIZE ? read_line(ret, rank + 1, fd) : 0) &&
		!((r = case_edge(buf, i, sz, fd->fd)) == -1) &&
		(sz || rank || fd->len) &&
		(*ret = malloc((sz = fd->len + rank * BUFF_SIZE + i--))) &&
		(*ret += --sz))
			**ret = '\0';
	if (*ret)
		while (i--)
			*(*ret)-- = buf[i];
	ft_cleanfree(buf, BUFF_SIFE);
	return (r);
}

static int		known_smallline(t_s_fs *fd, char **line)
{
	char *const		strt = fd->p_b;
	char *const		lim = strt + fd->len;
	size_t			len;
	char			*p;

	p = strt;
	while (p < lim)
		if (*p++ == EOL)
		{
			len = p - strt;
			if (len && !(*line = malloc(len)))
				return (-1);
			(*line)[--len] = '\0';
			ft_memcpy(*line, strt, len);
			fd->p_b = p;
			fd->len -= len + 1;
			return (1);
		}
	return (0);
}

int				get_next_line(const int at_fd, char **line)
{
	int		r;
	t_s_fs	*fd;

	if (line)
		*line = malloc(0);
	if (!line || !(fd = get_set_fd_state(at_fd, GET_FD)))
		return (-1);
	if (!(r = known_smallline(fd, line)) &&
		(r = read_line(line, 0, fd)) != -1)
	{
		ft_memcpy((*line -= fd->len), fd->p_b, fd->len);
		fd->len = 0;
	}
	if (!fd->len)
	{
		ft_cleanfree(fd->buf, fd->b_sz);
		ft_cleanfree(fd, sizeof(t_s_fs));
	}
	else
		get_set_fd_state(SET_FD, fd);
	return (r ? r : !!**line);
}
