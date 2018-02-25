NAME =
TARGETS =

OBJ = ./objects
SRC = ./sources

OBJS := $(patsubst %,$(OBJ)/%.o,$(TARGETS))

ifndef ROOT
	LIB_DIR = ./libs/objects
	LIB_H_DIR  = ./libs/includes
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS_MORE =

#nothing to make
all : libft
	@:

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(CFLAGS_MORE)\
		-o $(NAME) $(OBJS)

clean :
	-rm $(OBJS)

fclean : clean
	-rm $(NAME)

re : fclean all

.PHONY : re fclean clean all
