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

static t_s_fs	*get_set_fd_state(int get_fd, t_s_fs *set)
{
	static t_s_fs	anchor = (t_s_fs){-1, 0, 0, 0, 0, 0};
	t_s_fs			*p;
	t_s_fs			*prev;
	char			c;

	if ((p = set))
	{
		set->nxt = anchor->nxt;
		anchor.nxt = set;
	}
	if (get_fd < 0)
		return (p);
	p = &anchor;
	prev  = &anchor;
	while (p->fd != get_fd && (p = p->nxt))
		prev = p;
	if (p)
	{
		prev->nxt = p->nxt;
		p->nxt = 0;
	}
	else if (!read(get_fd, &c, 0) && (p = malloc(sizeof(t_s_fs))))
		*p = (t_s_fs){get_fd, 0, 0, 0, 0, 0};
	return (p);
}

static int		edge(char const *h_buff, size_t i, size_t count)
{
	size_t const	ip1 = i + 1;
	size_t			len;
	t_s_fs			*new;

	if (count > ip1)
	{
		len = count - ip1;
		if ((new = malloc(sizeof(t_s_fs))) &&
			(new->buf = malloc(len)))
		{
			*new = {fd_s->fd, new->buf, len, new->buf, len, 0};
			ft_memcpy(new->buf, h_buff + ip1, len);
			return (get_set_fd_state(SET_FD, new) ? 0 : -1);
		}
		else if (new)
			free(new);
	}
	return (-1);
}

static int	read_line(char **line, int rank, t_s_fs *fd_s)
{
	char	h_buff[BUFF_SIZE];
	size_t	count;
	size_t	i;
	int		r;

	if ((count = read(fd_s->fildes, h_buff, BUFF_SIZE)) == -1)
		return (-1);
	i = 0;
	while (i < count && h_buff[i] != EOL)
		i++;
	if (i == BUFF_SIZE)
		r = read_line(line, rank + 1, fd_s->s);
	else if ((*line = malloc(fd_s->len + rank * BUFF_SIZE + i + 1)) &&
		!(r = edge(h_buff, i, count)))
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
			if (sz && !(*line = malloc(len--)))
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
	t_s_fs	*fd_state;
	size_t	i;

	if (!line || !(fd_state = get_set_fd_state(fd, GET_FD)))
		return (-1);
	else if (!(ret = known_smallline(fd_state, line)) &&
			!(ret = read_line(line, 0, fd_state)))
	{
		ft_memcpy((*line -= fd_state->len), fd_s->p_b, fd_s->len);
		fd_state->len = 0;
	}
	if (!fd_state->len)
	{
		ft_cleanfree(fd_s->buf, fd_s->b_sz);
		ft_cleanfree(fd_s, sizeof(t_s_fs));
	}
	else
		get_set_fd_state(SET_FD, fd_s);
	if (ret = -1)
		*line = malloc(0);
	return (ret);
}
