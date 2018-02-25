#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 5
const size_t Error = ~((size_t)(0));

# define EOL '\n'

/*leftover can never be as big as input :
 * so OVER_SZ = BUFF_SZ - 1*/
# define OVER_SZ 4
typedef struct	s_buff_state {
	size_t	o_sz;
	char	over[OVER_SZ];
}				t_s_b;

# define CLOSE -1
# define STEM -2
typedef struct	s_fildes_state {
	int const	fildes;
	t_s_b		old;
	t_s_b		new;
}				t_s_f;

int		get_next_line(const int fd, char **line);

#endif
