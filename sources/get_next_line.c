/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 03:15:48 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/11 13:20:10 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_s_fs	*get_set_fd_state(int get_fd, t_s_fs *set)
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
	else if (get_fd >=  0)
	{
		p = &anchor;
		prev = &anchor;
		while (p->fd != get_fd && (p = p->nxt))
			prev = p;
		if (p)
			prev->nxt = p->nxt;
		else if (!read(get_fd, &c, 0) && (p = malloc(sizeof(t_s_fs))))
			*p = (t_s_fs){get_fd, 0, 0, 0, 0, 0};
	}
	return (p);
}

static int		edge(char const *h_buff, size_t i, size_t count, int fd)
{
	size_t const	ip1 = i + 1;
	size_t			len;
	t_s_fs			*new_s;

	if (count > ip1)
	{
		len = count - ip1;
		if (!(new_s = malloc(sizeof(t_s_fs))) ||
			!(new_s->buf = malloc(len)))
		{
			if (new_s)
				free(new_s);
			return (-1);
		}
		*new_s = (t_s_fs){fd, new_s->buf, len, new_s->buf, len, 0};
		ft_memcpy(new_s->buf, h_buff + ip1, len);
		get_set_fd_state(SET_FD, new_s);
	}
	return (0);
}

static int		read_line(char **line, int rank, t_s_fs *fd_s)
{
	char	h_buff[BUFF_SIZE];
	size_t	count;
	size_t	i;
	int		r;

	r = -1;
	if ((count = read(fd_s->fd, h_buff, BUFF_SIZE)) == GNL_ERR)
		return (r);
	i = 0;
	while (i < count && h_buff[i] != EOL)
		i++;
	if (i == BUFF_SIZE)
		r = read_line(line, rank + 1, fd_s);
	else if ((*line = malloc(fd_s->len + rank * BUFF_SIZE + i + 1)) &&
		!(r = edge(h_buff, i, count, fd_s->fd)))
	{
		*line += fd_s->len + rank * BUFF_SIZE + i;
		**line = '\0';
	}
	else if (*line)
		free(*line);
	if (!r)
		while (i--)
			*--(*line) = h_buff[i];
	return (r);
}

static int		known_smallline(t_s_fs *fd_s, char **line)
{
	char *const		strt = fd_s->p_b;
	char *const		lim = strt + fd_s->len;
	size_t			len;
	char			*p;

	p = strt;
	while (p < lim)
		if (*p++ == EOL)
		{
			len = p - strt;
			if (len && !(*line = malloc(len--)))
				return (-1);
			(*line)[len] = '\0';
			ft_memcpy(*line, strt, len);
			fd_s->p_b = p;
			fd_s->len -= len;
			return (1);
		}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int		ret;
	t_s_fs	*fd_s;

	if (line)
		*line = 0;
	if (!line || !(fd_s = get_set_fd_state(fd, GET_FD)))
		return (-1);
	else if (!(ret = known_smallline(fd_s, line)) &&
			!(ret = read_line(line, 0, fd_s)))
	{
		ft_memcpy((*line -= fd_s->len), fd_s->p_b, fd_s->len);
		fd_s->len = 0;
	}
	if (!fd_s->len)
	{
		ft_cleanfree(fd_s->buf, fd_s->b_sz);
		ft_cleanfree(fd_s, sizeof(t_s_fs));
	}
	else
		get_set_fd_state(SET_FD, fd_s);
	return (ret ? ret : !!**line);
}
