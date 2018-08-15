#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define ERROR -1

# define BUFF_SIZE 5
# define OVER_SZ BUFF_SIZE - 1
# define EOL '\n'

typedef struct	s_buff_state {
	size_t	o_sz;
	char	over[OVER_SZ];
}				t_s_b;

# define CLOSE -1
# define STEM -2
typedef struct	s_fildes_state {
	int 		fildes;
	t_s_b		old;
	t_s_b		new;
}				t_s_f;

# define A_LOT 500

int		get_next_line(const int fd, char **line);

#endif
