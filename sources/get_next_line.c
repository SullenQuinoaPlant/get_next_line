/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 03:15:48 by nmauvari          #+#    #+#             */
/*   Updated: 2018/08/28 03:55:31 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>

static int	edge(char const *h_buff, size_t i, size_t count, t_s_f *s)
{
	if (count == BUFF_SIZE && i + 1 == count)
	{
		if ((s->new.o_sz = read(s->fildes, s->new.over, OVER_SZ)) == ERROR)
			return (-1);
	}
	else
	{
		s->new.o_sz = count == i ? 0 : count - i - 1;
		ft_memcpy(s->new.over + OVER_SZ - s->new.o_sz, h_buff + i + 1, s->new.o_sz);
	}
	if (s->new.o_sz)
		return (1);
	s->fildes = CLOSE;
	return (0);
}

static int	here_recursion(char **line, int rank, t_s_f *s)
{
	char	h_buff[BUFF_SIZE];
	size_t	count;
	size_t	i;
	int		ret;

	if ((count = read(s->fildes, h_buff, BUFF_SIZE)) == ERROR)
		return (-1);
	i = 0;
	while (i < count && h_buff[i] != EOL)
		i++;
	ret = -1;
	if (i == BUFF_SIZE)
		ret = here_recursion(line, rank + 1, s);
	else if ((*line = malloc(rank * BUFF_SIZE + i + s->old.o_sz + 1)))
	{
		ret = edge(h_buff, i, count, s);
		*line += rank * BUFF_SIZE + i + s->old.o_sz;
		**line = '\0';
	}
	if (ret != -1)
		while (i--)
			*--(*line) = h_buff[i];
	return (ret);
}

static int	short_message(t_s_b *b_s, char **line)
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

//static t_s_f	*get_fd_states(int fd)
//{
//	static t_s_f			new = {.fildes = STEM};
//	static t_list			top;
//	t_list					*iter;
//	t_list					*prev;
//	
//	if (fd == CLOSE)
//	{
//		void	cleanup(void *at, size_t sz)
//		{
//			ft_bzero(at, sz);
//			free(at);
//		}
//		ft_lstdel(&top.next, &cleanup);
//		return (0);
//	}
//	iter = &top;
//	while ((prev = iter) && (iter = iter->next))
//		if ((*(t_s_f*)iter->content).fildes == CLOSE)
//		{
//			prev->next = iter->next;
//			free(iter->content);
//			free(iter);
//			iter = prev->next;
//		}
//		else if ((*(t_s_f*)iter->content).fildes == fd)
//			return ((t_s_f*)iter->content);
//	new.fildes = fd;
//	ft_lstadd(&top.next, ft_lstnew(&new, sizeof(t_s_f)));
//	return ((t_s_f*)top.next->content);
//}

static t_s_f *get_fd_states(int fd)
{
	static t_s_f	array[A_LOT];
	size_t			i;

	if (fd >= 0)
	{
		array[fd].fildes = fd;
		return (array + fd);
	}
	else if (fd == CLOSE)
	{
		i = -1;
		while (++i < A_LOT)
			ft_bzero(array + i, sizeof(t_s_f));
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int		ret;
	t_s_f	*fd_state;
	size_t	i;

	ret = -1;
	if ((fd_state = get_fd_states(fd)) &&
		!(ret = short_message(&fd_state->old, line)) &&
		(ret = here_recursion(line, 0, fd_state)) != -1)
	{
		i = 0;
		while (i++ < fd_state->old.o_sz)
			*--(*line) = fd_state->old.over[OVER_SZ - i];
		fd_state->old = fd_state->new;
	}
	else if (ret == -1)
		*line = malloc(0);
	return (ret);
}
