NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread
REMOVE = rm -rf


HEADERS	= -I./inc/

SRC =  src/philosophers.c\
	src/philosophers_utils.c\
	src/minilibft.c\
	src/init.c\
	src/rutine.c\
	src/msg.c\
	src/free.c

OBJT =		$(SRC:.c=.o)

BLUE = \033[1;38;5;153m
RED = \033[0;31m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

.c.o:
	@gcc ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)philosophers Compiling:$(RESET) $(notdir $<)"

all:		$(NAME)

$(NAME): ${OBJT}
	@gcc ${CFLAGS} ${OBJT} -o ${NAME}
	@echo "\n$(BLUE)$(U_LINE)🥳🎊 $(NAME): Compiled 🥳🎊$(RESET) \n"

clean:
	@rm -f ${OBJT}
	@echo "\n$(RED)$(U_LINE)$(NAME): Cleaned$(RESET) \n"

fclean: 	clean
	@rm -f ${NAME}

re: 		fclean all

.PHONY: all clean fclean re