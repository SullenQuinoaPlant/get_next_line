ifndef ROOT
 ROOT = ..
 include $(ROOT)/make_vars.mk
endif

TEST_SRCS := $(wildcard $(UTEST_DIR)/*.test.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)
BUILD_STAMPS := $(TEST_OBJS:.o=.build.stamp)
EXECUTION_STAMPS := $(TEST_OBJS:.o=.execution.stamp)

CTESTFLAGS = -I $(LIBS_I) -I $(INC_DIR) -L $(LIBS_L) -fno-builtin
CTESTFLAGS += $(CFLAGS_MORE)


.PHONY : unit-tests ut
unit-tests ut : list_tests build_tests run_tests


###########
#STANDALONE
.PHONY : alone
alone :
	$(CC) -I ../includes -I ../libs/includes -L ../libs/objects\
		test.c -lgetnextline -lft -g

############
#BUILD TESTS

.PHONY : build_tests
build_tests : cmocka $(TEST_OBJS)

.PHONY : cmocka
cmocka : 
	if $(CC) $(CTESTFLAGS)\
	 	$(UTEST_DIR)/boilerplate.c\
		 -lcmocka_shared -o test.o; then\
			rm test.o;\
			echo "cmocka already installed";\
	else\
		$(MAKE) -C $(UTEST_DIR)/cmocka/;\
		mv $(UTEST_DIR)/cmocka/libcmocka* $(LIBS_L)/;\
		mv $(UTEST_DIR)/cmocka/cmocka.h $(LIBS_I)/;\
	fi

$(UTEST_DIR)/%.test.o : $(UTEST_DIR)/%.test.c $(SRC_DIR)/%.c
	$(CC) $(CTESTFLAGS)\
		-I $(SRC_DIR)\
		-D main=testee_main\
		$<\
		-L $(LIBS_L)\
		-lcmocka_shared -lgetnextline -lft\
		-o $@\
		-Wl,-rpath="$(LIBS_L)";\
		touch $(UTEST_DIR)/$*.test.build.stamp

%.test.o : %.test.c
	$(CC) $(CTESTFLAGS)\
		-I $(SRC_DIR)\
		$<\
		-lcmocka -lgetnextline -lft\
		-o $@\
		-Wl,-rpath "$(LIBS_L)";\
		touch $(UTEST_DIR)/$(*F).test.build.stamp

test.o : test.c
	gcc -g -I ../sources -I ../libs/includes -L ../libs/objects\
		test.c\
		-lft\
		-o $@

test_simple.o : test_simple.c
	gcc -g -I ../sources -I ../libs/includes -L ../libs/objects\
		$<\
		-lft\
		-o $@
test_bigline.o : test_bigline.c
	gcc -g -I ../sources -I ../libs/includes -L ../libs/objects\
		$<\
		-lft\
		-o $@
test_devrand.o : test_devrand.c
	gcc -g -I ../sources -I ../libs/includes -L ../libs/objects\
		$<\
		-lft\
		-o $@
test_smalllines.o : test_smalllines.c
	gcc -g -I ../sources -I ../libs/includes -L ../libs/objects\
		$<\
		-lft\
		-o $@


############
#RUN TESTS :

.PHONY : run_tests
run_tests : $(EXECUTION_STAMPS)

%.execution.stamp : %.build.stamp
	./$*.o "$$(readlink -e $(UTEST_DIR))" < $(UTEST_DIR)/use_this_for_input
	touch $@

%.build.stamp :
	@:

###############
#MISCELLANEOUS:

.PHONY : all_unit_tests aut
all_unit_tests aut : clean-tests test



.PHONY : clean-tests
clean-tests :
	-rm $(UTEST_DIR)/*.o
	-rm $(UTEST_DIR)/*.stamp



.PHONY : list_tests
list_tests :
	@echo "source dir is : $(SRC_DIR)"
	@echo "list of test sources:"
	@echo $(TEST_SRCS)
	@echo "list of test objects:"
	@echo $(TEST_OBJS)
