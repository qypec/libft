# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/03 22:38:11 by yquaro            #+#    #+#              #
#    Updated: 2019/08/03 23:12:27 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../includes/libft.mk
include ../includes/ft_string.mk

SOURCES = ft_stringnew.c
OBJECTS = ft_stringnew.o

all: $(SOURCES) $(NAME)

.c.o:
	$(COMPILING) $< -o $@

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@mv $(NAME) ../../lib/$(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f ../$(NAME)