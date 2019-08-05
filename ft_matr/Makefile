# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 13:11:11 by qypec             #+#    #+#              #
#    Updated: 2019/08/05 19:35:46 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/libft.mk

SOURCES = ft_matrdel.c ft_matrdup.c ft_matrmemalloc.c ft_matrnew.c ft_matrlen.c
OBJECTS = ft_matrdel.o ft_matrdup.o ft_matrmemalloc.o ft_matrnew.o ft_matrlen.o

NAME = libmatr.a

all: print $(SOURCES) $(NAME)
	
print:
	@echo \*\*\* Compiling ft_matr

.c.o:
	$(COMPILING) $< -o $@

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@mv $(NAME) ../lib/$(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f ../lib/$(NAME)
	