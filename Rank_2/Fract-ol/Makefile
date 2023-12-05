NAME = fractol

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
REMOVE = rm -rf

MLX_PATH = includes/MLX42
MLX_LIB_PATH = includes/MLX42/libmlx42.a

LIBFT_PATH = includes/Libft
LIBFT_LIB_PATH = includes/Libft/libft.a

HEADERS	= -I $(MLX_PATH)/include/MLX42 -I $(LIBFT_PATH)/include/ -I ./include

SRC =  src/fractol.c\
	src/utils.c\
	src/utils_utils.c\
	src/errors.c\
	src/hook.c\
	src/fractals.c\
	src/utils_color.c
OBJ = $(SRC:src/%.c=obj/%.o)

BLUE = \033[1;38;5;153m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

all: $(MLX_LIB_PATH) $(LIBFT_LIB_PATH) $(NAME)

.SILENT: all $(MLX_LIB_PATH) $(LIBFT_LIB_PATH) $(NAME) $(OBJ) clean fclean re

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB_PATH) $(MLX_LIB_PATH) $(HEADERS) -lglfw -L "/Users/${USER}/.brew/opt/glfw/lib/" -o $@
	echo "\n$(BLUE)$(U_LINE)🥳🎊 $(NAME): Compiled 🥳🎊$(RESET) \n"

$(MLX_LIB_PATH):
	$(MAKE) -C $(MLX_PATH)

$(LIBFT_LIB_PATH):
	$(MAKE) -C $(LIBFT_PATH)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	echo "$(YELLOW)fractol Compiling:$(RESET) $(notdir $<)"

clean:
	$(REMOVE) obj
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(REMOVE) $(NAME)
	$(MAKE) -C $(MLX_PATH) fclean
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re $(MLX_LIB_PATH) $(LIBFT_LIB_PATH)