include make_vars.mk


#######
#CORE :

include Makefile.mk




include make_vars.mk

########
#TESTS :

include unit-tests/Makefile



#########
#OUTPUT :

OUT = gnl
clean-gnl :
	if ! [ -d get_next_line ]; then mkdir $(GNL); fi
	cp auteur $(OUT)/
	cp $(LIBS_DIR)/libft $(OUT)/
	cp $(SRC_DIR)/get_next_line.c $(OUT)/
	cp $(SRC_DIR)/get_next_line.h $(OUT)/
