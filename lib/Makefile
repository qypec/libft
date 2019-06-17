# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 01:54:46 by yquaro            #+#    #+#              #
#    Updated: 2019/06/18 02:18:00 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all:
	@echo \*\*\* Reassemblage 
	@ar -x libft.a
	@ar -x liballoc.a
	@ar -x libctime.a
	@ar -x libhashtab.a
	@ar -x libmath.a
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@rm __.SYMDEF\ SORTED
	@mv $(NAME) ../../$(NAME)
	@echo \*\*\* COMPLETE!

fclean:
	@rm *.o