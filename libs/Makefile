ifndef ROOT
	ROOT = ..
	include $(ROOT)/make_vars.mk
endif


.PHONY : libft
libft :
	-git clone\
		--single-branch -b the_lib\
		--depth 1\
		https://github.com/SullenQuinoaPlant/Libft.git\
		$(LIB_DIR)/$@
	$(MAKE) -C $(LIB_DIR)/$@
	cp $(LIB_DIR)/$@/includes/libft.h $(LIBS_I)/
	cp $(LIB_DIR)/$@/libft.a $(LIBS_L)


.PHONY : clean-libft
clean-libft :
	-rm libft
	-rm $(LIBS_I)/libft.h
	-rm $(LIBS_L)/libft.a
