# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qypec <qypec@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 19:26:56 by yquaro            #+#    #+#              #
#    Updated: 2019/06/12 09:38:24 by qypec            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# (ar rc)
# The c option makes you create a library if it is not available,
# and the r (replace) option replaces old object files with new versions.

# (ranlib)
# Adds a character index to the archive

CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror
SOURCES = ft_putstr.c ft_putendl.c ft_putchar.c ft_strlen.c ft_itoa.c \
			ft_memalloc.c ft_numblen.c ft_puterror.c ft_strdel.c ft_strdup.c \
			ft_strglue.c ft_memset.c
OBJECTS = ft_putstr.o ft_putendl.o ft_putchar.o ft_strlen.o ft_itoa.o \
			ft_memalloc.o ft_numblen.o ft_puterror.o ft_strdel.o ft_strdup.o \
			ft_strglue.o ft_memset.o

NAME = libft.a

all: $(SOURCES) print_echo $(NAME)

print_echo:
	@echo \*\*\* Compiling libft

.c.o:
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	@make -C ft_ctime/ all
	@make -C ft_alloc/ all
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@mv $(NAME) lib/$(NAME)


clean:
	@make -C ft_ctime/ fclean
	@make -C ft_alloc/ fclean
	@rm $(OBJECTS)

fclean: clean
	@rm lib/$(NAME)


# FLAGS = -Wall -Wextra -Werror
# SOURCE = ft_*.c
# OBJS = *.o
# OBJDIR = .obj
# NAME = libft.a

# all: $(NAME)
# $(NAME):
# 	gcc -g -c $(FLAGS) $(SOURCE)
# 	mkdir $(OBJDIR)
# 	mv $(OBJS) $(OBJDIR)
# 	make -C ft_ctime/ all
# 	ar rc $(NAME) $(OBJDIR)/$(OBJS)
# 	ranlib $(NAME)

# clean:
# 	rm -rf $(OBJDIR)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all
