include make_vars.mk


#######
#CORE :

include Makefile.mk




########
#TESTS :


.PHONY : unit-tests ut
unit-tests ut :
	make -C unit-tests

.PHONY : all_unit-tests aut
all_unit-tests aut :
	make -C unit-tests all


#########
#OUTPUT :

OUT = gnl
clean-gnl :
	if ! [ -d get_next_line ]; then mkdir $(GNL); fi
	cp auteur $(OUT)/
	cp $(LIBS_DIR)/libft $(OUT)/
	cp $(SRC_DIR)/get_next_line.c $(OUT)/
	cp $(SRC_DIR)/get_next_line.h $(OUT)/
