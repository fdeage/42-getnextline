#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/20 13:20:39 by fdeage            #+#    #+#              #
#    Updated: 2015/05/06 19:31:00 by fdeage           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

BIN = get_next_line

SRC = get_next_line.c	main.c
OBJ = $(SRC:.c=.o)

INC = -I.
FLAGS = -Wall -Wextra -Werror
EXTRAFLAGS = -pedantic -Weverything -Wno-missing-prototypes

CC = clang

all: $(BIN)

$(BIN):		$(OBJ)
			$(CC) -g -o $(BIN) $(OBJ) libft.a

leaks:
			leaks `ps | grep ./mult | head -n 1 | cut -d' ' -f1`

clean:
			/bin/rm *.o

fclean:		clean
			/bin/rm $(BIN)

re:			fclean all

extra:		FLAGS += $(EXTRAFLAGS)
extra:		re

%.o:		%.c
			$(CC) -g $(FLAGS) $(INC) -c $< -o $@
