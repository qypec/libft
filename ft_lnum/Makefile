# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 16:32:24 by yquaro            #+#    #+#              #
#    Updated: 2019/06/12 16:33:34 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror
SOURCES = 
OBJECTS = 

NAME = liblnum.a

all: $(SOURCES) print_echo $(NAME)
	
print_echo:
	@echo \*\*\* Compiling ft_lnum

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