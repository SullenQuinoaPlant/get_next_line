ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
endif

.PHONY : build_dependencies
build_dependencies : $(DEPENDENCIES)

.PHONY : libft
libft :
	-git clone\
		--single-branch -b release\
		--depth 1\
		https://github.com/SullenQuinoaPlant/Libft.git\
		$(LIB_DIR)/$@
	$(MAKE) -C $(LIB_DIR)/$@
	cp $(LIB_DIR)/$@/includes/libft.h $(LIBS_I)/
	cp $(LIB_DIR)/$@/libft.a $(LIBS_L)


.PHONY : clean-lib*
clean-lib% :
	-rm -rf $(LIB_DIR)/lib$*
	-rm $(LIBS_I)/lib$*.h
	-rm $(LIBS_L)/lib$*.a
