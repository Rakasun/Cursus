NAME = push_swap
NAME_BONUS = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -rf

LIBFT_PATH = includes/Libft
LIBFT_LIB_PATH = includes/Libft/libft.a

HEADERS	= -I $(LIBFT_PATH)/include/ -I ./include/push_swap.h

HEADERS_BONUS = -I $(LIBFT_PATH)/include/ -I ./include/push_swap_bonus.h

SRC =  src/push_swap.c\
	src/error.c\
	src/utils_basic.c\
	src/utils_check.c\
	src/utils_utils.c\
	src/utils_stack.c\
	src/utils_free.c\
	src/init.c\
	src/swap.c\
	src/push.c\
	src/rotate.c\
	src/rrotate.c\
	src/algorithm.c

SRC_BON =  src_bonus/checker_bonus.c\
	src_bonus/error_bonus.c\
	src_bonus/utils_basic_bonus.c\
	src_bonus/utils_check_bonus.c\
	src_bonus/utils_utils_bonus.c\
	src_bonus/utils_stack_bonus.c\
	src_bonus/utils_free_bonus.c\
	src_bonus/init_bonus.c\
	src_bonus/swap_bonus.c\
	src_bonus/push_bonus.c\
	src_bonus/rotate_bonus.c\
	src_bonus/rrotate_bonus.c\
	src_bonus/algorithm_bonus.c 

OBJ = $(SRC:src/%.c=obj/%.o)

OBJS_BONUS = ${SRC_BON:src_bonus/%.c=objs_bonus/%.o}

BLUE = \033[1;38;5;153m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

all: $(LIBFT_LIB_PATH) $(NAME)

all_bonus: $(LIBFT_LIB_PATH) $(NAME_BONUS)

.SILENT: all $(LIBFT_LIB_PATH) $(NAME) $(NAME_BONUS) $(OBJ) $(OBJS_BONUS) bonus clean fclean re clean_bonus fclean_bonus re_bonus

bonus: $(LIBFT_LIB_PATH) $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB_PATH) $(HEADERS) -lglfw -L "/Users/${USER}/.brew/opt/glfw/lib/" -o $@
	echo "\n$(BLUE)$(U_LINE)🥳🎊 $(NAME): Compiled 🥳🎊$(RESET) \n"

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(LIBFT_LIB_PATH) $(HEADERS_BONUS) -lglfw -L "/Users/${USER}/.brew/opt/glfw/lib/" -o $@
	echo "\n$(BLUE)$(U_LINE)🥳🎊 $(NAME_BONUS): Compiled 🥳🎊$(RESET) \n"

$(LIBFT_LIB_PATH):
	$(MAKE) -C $(LIBFT_PATH)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	echo "$(YELLOW)push_swap Compiling:$(RESET) $(notdir $<)"

objs_bonus/%.o: src_bonus/%.c
	mkdir -p objs_bonus
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS_BONUS)
	echo "$(YELLOW)checker Compiling:$(RESET) $(notdir $<)"

clean:
	$(REMOVE) obj
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(REMOVE) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

clean_bonus:
	$(REMOVE) objs_bonus
	$(MAKE) -C $(LIBFT_PATH) clean

fclean_bonus: clean_bonus
	$(REMOVE) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

re_bonus: fclean_bonus all_bonus

py3:	re
		python3 python_visualizer.py `ruby -e "puts (1..3).to_a.shuffle.join(' ')"`
py5:	re
		python3 python_visualizer.py `ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
py10:	re
		python3 python_visualizer.py `ruby -e "puts (1..10).to_a.shuffle.join(' ')"`
py100:	re
		python3 python_visualizer.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
py500:	re
		python3 python_visualizer.py `ruby -e "puts (1..500).to_a.shuffle.join(' ')"`

.PHONY: all all_bonus bonus clean fclean re clean_bonus fclean_bonus re_bonus $(LIBFT_LIB_PATH) py3 py5 py10 py100 py500