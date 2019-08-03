# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/02 12:36:28 by yquaro            #+#    #+#              #
#    Updated: 2019/08/03 23:11:28 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include includes/libft.mk

all: print $(NAME)

print:
	@echo \*\*\* Compiling libft

$(NAME): $(OBJECTS)
	@make -C ft_list/ all
	@make -C ft_ctime/ all
	@make -C ft_alloc/ all
	@make -C ft_math/ all
	@make -C ft_map/ all
	@make -C ft_buffer/ all
	@make -C ft_matr/ all
	@make -C ft_string/ all
	@make -C src/ all
	@make -C lib/ all

clean:
	@make -C lib/ clean
	@make -C ft_list/ clean
	@make -C ft_ctime/ clean
	@make -C ft_alloc/ clean
	@make -C ft_math/ clean
	@make -C ft_map/ clean
	@make -C ft_buffer/ clean
	@make -C ft_matr/ clean
	@make -C ft_string/ clean
	@make -C src/ clean

fclean: clean
	@make -C lib/ fclean
	@make -C ft_list/ fclean
	@make -C ft_ctime/ fclean
	@make -C ft_alloc/ fclean
	@make -C ft_math/ fclean
	@make -C ft_map/ fclean
	@make -C ft_buffer/ fclean
	@make -C ft_matr/ fclean
	@make -C ft_string/ fclean
	@make -C src/ fclean
	@rm -f $(NAME)

re: fclean all
