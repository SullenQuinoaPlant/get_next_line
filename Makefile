ifndef ROOT
	ROOT := .
endif
include $(ROOT)/make_vars.mk


#######
#CORE :
include core.mk

#######
#LIBS :
include libs/Makefile

########
#TESTS :
include unit-tests/Makefile


########
#RELEASE
.PHONY : release
release:
	git clone\
		--depth 1 --single-branch\
		-b release\
		https://github.com/SullenQuinoaPlant/get_next_line.git\
		$(ROOT)/$@/
	cd $(ROOT)/$@ && git rm -rf *
	cp $(ROOT)/auteur $(ROOT)/$@
	cp $(ROOT)/make_vars_release.mk $(ROOT)/$@/Makefile
	cat $(ROOT)/core.mk >> $(ROOT)/$@/Makefile
	cp -r $(ROOT)/sources/ $(ROOT)/$@
	cp -r $(ROOT)/includes/ $(ROOT)/$@
	cp $(LIBS_I)/libft.h $(ROOT)/$@/includes/
	cd $(ROOT)/$@ && git add * && git commit -m i && git push
