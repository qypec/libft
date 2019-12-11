all: print
	make -C ../ all
	make -C src/ft_list/ all
	make -C src/ft_map/ all
	make -C lib/ all

print:
	@echo \*\*\* Compiling unit tests

fclean:
	@make -C src/ft_list/ fclean
	@make -C src/ft_map/ fclean
	@make -C lib/ fclean