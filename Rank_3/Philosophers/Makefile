NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -rf


HEADERS	= -I ./include/philosophers.h

SRC =  src/philosophers.c\
	src/philosophers_utils.c\
	src/minilibft.c\
	src/init.c\
	src/rutine.c\
	src/msg.c

OBJ = $(SRC:src/%.c=obj/%.o)


BLUE = \033[1;38;5;153m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

all: $(NAME)

.SILENT: all $(NAME) $(OBJ) clean fclean re

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(HEADERS) -o $@
	@echo "\n$(BLUE)$(U_LINE)🥳🎊 $(NAME): Compiled 🥳🎊$(RESET) \n"

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@echo "$(YELLOW)philosophers Compiling:$(RESET) $(notdir $<)"

clean:
	$(REMOVE) obj

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re