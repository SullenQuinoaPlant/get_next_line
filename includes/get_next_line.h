/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 03:15:44 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/10 15:13:32 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define ERROR ~((size_t)0)

# define BUFF_SIZE 1000
# define EOL '\n'
# define BIGBIGADR ~((size_t)0)
# define UNALLOCATED (char*)0 + BIGBIGADR

typedef struct	s_buff_state {
	char	*buffer;
	size_t	b_sz;
	char	*p_b;
}				t_s_b;

typedef struct s_fildes_state	t_s_fs;
struct							s_fildes_state {
	int			fd;
	t_s_b		old;
	t_s_fs		*nxt;
};

int								get_next_line(const int fd, char **line);

#endif
