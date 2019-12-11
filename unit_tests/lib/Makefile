include ../includes/unit_test.mk

CFLAGS = -g
LIBNAME = ../../libft.a

all:
	$(COMPILING) ../src/main.c *.o $(LIBNAME) -o unit_test
	@echo \*\*\* UNIT TESTS COMPILED!

clean:
	@rm -f *.o
	@rm -rf *.dSYM

fclean: clean
	@rm -f ../unit_test
	