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

static t_s_fs	*get_set_fd_state(int get_fd, t_s_fs *set)
{
	static t_s_fs	anchor = (t_s_fs){-1, 0, 0, 0, 0, 0};
	t_s_fs			*p;
	t_s_fs			*prev;
	char			c;

	if (set.fd)
	{
		if (!(p = malloc(sizeof(t_s_fs))))
			return ();
	}
	p = &anchor;
	while (p && p->fd != get_fd && (prev = p) && ((p = p->nxt) || 1))
		prev->nxt = p;
	set = UNALLOCATABLE;
	if (anchor.len && p != &anchor && (set = malloc(sizeof(t_s_fs))))
		memcpy(set, &anchor, sizeof(t_s_fs));
	anchor = p ? *p : (t_s_fs){get_fd, 0, 0, 0, 0, set};
	return (p);
}

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
	else if (get_fd >= 0)
	{
		p = &anchor;
<<<<<<< HEAD
		while (p && p->fd != get_fd && (prev = p))
			p = p->nxt;
=======
		while (p && p->fd != get_fd)
		{
			prev = p;
			p = p->nxt;
		}
>>>>>>> 342cc3bf5020c8eba24337ca5be66b7524f79cdc
		if (p)
			prev->nxt = p->nxt;
		else if (!read(get_fd, &c, 0) && (p = malloc(sizeof(t_s_fs))))
			*p = (t_s_fs){get_fd, 0, 0, 0, 0, 0};
	}
	return (p);
}

static int		save_edge(char const *h_buff, size_t i, size_t count, int fd)
{
	size_t const	ip1 = i + 1;
	size_t			len;
	t_s_fs			*new_s;

	if (count <= ip1)
		return (0);
	len = count - ip1;
	if ((new_s = malloc(sizeof(t_s_fs))) &&
		(new_s->buf = malloc(len)))
	{
		*new_s = (t_s_fs){fd, new_s->buf, len, new_s->buf, len, 0};
		ft_memcpy(new_s->buf, h_buff + ip1, len);
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
		(sz = read(fd->fd, buf, BUFF_SIZE)) == (size_t)-1))
		r = -1;
	i = 0;
	while ((r != -1) && i < sz && buf[i] != EOL)
		i++;
	if (!r && !(r = i == BUFF_SIZE ? read_line(ret, rank + 1, fd) : 0) &&
		!(r = save_edge(buf, i, sz, fd->fd)) && (sz || rank || fd->len) &&
		(r = -1) &&
		(*ret = malloc((sz = fd->len + rank * BUFF_SIZE + i) + 1)))
	{
		*ret += sz;
		**ret = '\0';
	}
	if (*ret)
		while (i--)
			*--(*ret) = buf[i];
	free(buf);
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
<<<<<<< HEAD
			fd->len -= ++len;
=======
			fd->len -= len + 1;
>>>>>>> 342cc3bf5020c8eba24337ca5be66b7524f79cdc
			return (1);
		}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int		ret;
	t_s_fs	*fd;

	if (line)
		*line = malloc(0);
	if (!line || !(fd = get_set_fd_state(fd, GET_FD)))
		return (-1);
	if (!(ret = known_smallline(fd, line)) &&
		(ret = read_line(line, 0, fd)) != -1)
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
	return (ret);
}
