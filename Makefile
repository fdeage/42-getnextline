#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/20 13:20:39 by fdeage            #+#    #+#              #
#    Updated: 2015/02/05 11:56:58 by fdeage           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

BIN = get_next_line
FILE = $(GNL_$(V))

V = NEW
GNL_OLD = get_next_line$(OLD)
GNL_NEW = get_next_line
OLD = _old

STDFLAGS = -Wall -Wextra -Werror
EXTRAFLAGS = --analyze -pedantic -Weverything -Wno-missing-prototypes

CC = gcc

all: $(FILE)

$(FILE):
			make -C libft/ fclean
			make -C libft/
			$(CC) -g $(STDFLAGS) -I libft/includes/ -I. -c $(FILE).c
			$(CC) -g $(STDFLAGS) -I libft/includes/ -I. -c main.c
			$(CC) -g -o $(BIN) $(FILE).o tests/main.o -L libft/ -lft

leaks:
			leaks `ps | grep ./mult | head -n 1 | cut -d' ' -f1`

clean:
			/bin/rm *.o

fclean:		clean
			/bin/rm $(BIN)

re:			fclean all
