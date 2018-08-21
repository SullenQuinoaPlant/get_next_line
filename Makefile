ifndef ROOT
	ROOT := .
	include $(ROOT)/make_vars.mk
endif


#######
#CORE :

include Makefile.mk


#######
#LIBS :

include libs/Makefile

########
#TESTS :

include unit-tests/Makefile


########
#RELEASE
release:
	git clone\
		--depth 1 --single-branch\
		-b release\
		https://github.com/SullenQuinoaPlant/get_next_line.git\
		$(ROOT)/$@/
	cp $(ROOT)/auteur $(ROOT)/$@
	cp -rf $(ROOT)/sources/ $(ROOT)/$@
	cp $(ROOT)/Makefile.mk $(ROOT)/$@/Makefile
	cp $(ROOT)/make_vars_release.mk $(ROOT)/$@/make_vars.mk
	cp $(LIBS_I)/libft.h $(ROOT)/$@/
	cd $(ROOT)/$@ && git add * && git commit -m i && git push
