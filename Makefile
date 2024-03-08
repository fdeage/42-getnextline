NAME=gnl
CC=gcc
FLAGS=-Wall -Wextra -Werror
EXTRAFLAGS=-pedantic -Weverything -Wno-missing-prototypes
LIBFT=libft.a
SRC=get_next_line.c main.c
OBJ=$(SRC:.c=.o)

COL_B=\033[1;34m
COL_G=\033[1;32m
COL_RES=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

lib: $(OBJ)
	@ar rc lib$(NAME) $^
	@ranlib lib$(NAME)
	@chmod +x lib$(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I. -c $< -o $@

clean:
	-@rm $(OBJ)

fclean : clean
	@rm $(NAME)
	@rm lib$(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
