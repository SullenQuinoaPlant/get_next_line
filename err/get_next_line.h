/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 03:15:44 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/09 09:34:23 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define ERROR ~((size_t)0)

# define BUFF_SIZE 100000000
# define OVER_SZ BUFF_SIZE - 1
# define EOL '\n'
# define BIGBIGADR ~((size_t)0)
# define UNALLOCATED (char*)0 + BIGBIGADR

typedef struct	s_buff_state {
	size_t	o_sz;
	char	over[OVER_SZ];
}				t_s_b;

typedef struct	s_fildes_state {
	int			fildes;
	t_s_b		old;
	t_s_b		new;
}				t_s_f;

# define A_LOT 500

int				get_next_line(const int fd, char **line);

#endif
