/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 03:15:44 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/15 11:17:21 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 1
# define EOL '\n'

# define GET_FD (void*)0
# define SET_FD -1

typedef struct s_fildes_state	t_s_fs;
struct							s_fildes_state
{
	int			fd;
	char		*buf;
	size_t		b_sz;
	char		*p_b;
	size_t		len;
	t_s_fs		*nxt;
};

int								get_next_line(const int fd, char **line);

#endif
