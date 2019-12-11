all: print
	make -C ../ all
	make -C src/ all
	make -C lib/ all

print:
	@echo \*\*\* Compiling unit tests

fclean:
	@make -C src/ fclean
	@make -C lib/ fclean