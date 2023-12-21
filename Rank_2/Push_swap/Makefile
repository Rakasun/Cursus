NAME = push_swap

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -rf

LIBFT_PATH = includes/Libft
LIBFT_LIB_PATH = includes/Libft/libft.a

HEADERS	= -I $(LIBFT_PATH)/include/ -I ./include

SRC =  src/push_swap.c\
	src/error.c\
	src/utils_check.c\
	src/utils_utils.c\
	src/utils_list.c
OBJ = $(SRC:src/%.c=obj/%.o)

BLUE = \033[1;38;5;153m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

all: $(LIBFT_LIB_PATH) $(NAME)

.SILENT: all $(LIBFT_LIB_PATH) $(NAME) $(OBJ) clean fclean re

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB_PATH) $(HEADERS) -lglfw -L "/Users/${USER}/.brew/opt/glfw/lib/" -o $@
	echo "\n$(BLUE)$(U_LINE)🥳🎊 $(NAME): Compiled 🥳🎊$(RESET) \n"

$(LIBFT_LIB_PATH):
	$(MAKE) -C $(LIBFT_PATH)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	echo "$(YELLOW)push_swap Compiling:$(RESET) $(notdir $<)"

clean:
	$(REMOVE) obj
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(REMOVE) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT_LIB_PATH)