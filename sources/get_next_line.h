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
	size_t	over_sz;
	char	leftover[BUFF_SIZE - 1];
}				t_s_b;

typedef struct	s_fildes_state {
	int const	fildes;
	t_s_b		old;
	t_s_b		new;
}				t_s_f;

static int	here_recursion(const int fd, char **line, int rank, t_s_b *s);

#endif
