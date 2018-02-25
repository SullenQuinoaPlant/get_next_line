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
	if ! [ -d get_next_line ]; then mkdir $(GNL); fi
	cp auteur $(OUT)/
	git clone https://github.com/SullenQuinoaPlant/Libft.git $(GNL)/libft
	cp $(SRC_DIR)/get_next_line.c $(OUT)/
	cp $(SRC_DIR)/get_next_line.h $(OUT)/
