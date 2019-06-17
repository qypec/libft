# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/14 13:54:33 by yquaro            #+#    #+#              #
#    Updated: 2019/06/18 00:18:35 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror
SOURCES = ft_hashfunc.c ft_htabadd.c ft_htabnew.c ft_puthtab.c ht_list.c ft_htabdelone.c ft_htabfree.c
OBJECTS = ft_hashfunc.o ft_htabadd.o ft_htabnew.o ft_puthtab.o ht_list.o ft_htabdelone.o ft_htabfree.o

NAME = libhashtab.a

all: $(SOURCES) print_echo $(NAME)
	
print_echo:
	@echo \*\*\* Compiling ft_hashtab

.c.o:
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@mv $(NAME) ../lib/$(NAME)

clean:
	@rm $(OBJECTS)

fclean: clean
	@rm ../lib/$(NAME)