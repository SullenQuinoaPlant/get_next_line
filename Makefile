include make_vars.mk


#######
#CORE :

include Makefile.mk




include make_vars.mk

#######
#LIBS :

include libs/Makefile

########
#TESTS :

include unit-tests/Makefile



#########
#OUTPUT :

OUT = gnl
clean-gnl :
	if ! [ -d get_next_line ]; then mkdir $(OUT); fi
	cp auteur $(OUT)/
	git clone -b the_lib --single-branch https://github.com/SullenQuinoaPlant/Libft.git $(OUT)/libft
	cp $(SRC_DIR)/get_next_line.c $(OUT)/
	cp $(SRC_DIR)/get_next_line.h $(OUT)/
