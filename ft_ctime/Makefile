# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 17:26:14 by yquaro            #+#    #+#              #
#    Updated: 2019/05/03 21:57:57 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# (ar rc)
# The c option makes you create a library if it is not available,
# and the r (replace) option replaces old object files with new versions.

# (ranlib)
# adds a character index to the archive

FLAGS = -Wall -Wextra -Werror
SOURCE = ft_uctime.c getdata.c get_temporarydata.c
OBJS = ft_uctime.o getdata.o get_temporarydata.o
OBJDIR = ../.obj

all: 
	gcc -g -c $(SOURCE) # не забыть флаги!!!
	mv $(OBJS) $(OBJDIR)


# 	gcc $(FLAGS) $(SOURCE)
# 	mkdir obj
# 	mv $(OBJS) obj/$(OBJS)
# 	ar rc libftctime.a obj/$(OBJS)
# 	ranlib libftctime.a
# 	mv libftctime.a obj/