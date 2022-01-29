NAME = so_long

SRC = mandatory/check_map.c\
	mandatory/ft_split.c\
	mandatory/help_def.c\
	mandatory/main.c\
	mandatory/gnl.c\
	mandatory/hooks.c\
	mandatory/pic_inizilization.c\

SRC_BONUS = so_long_bonus/ft_itoa.c\
	so_long_bonus/gnl_bonus.c\
	so_long_bonus/hooks_bonus.c\
	so_long_bonus/pic_inizilization_bonus.c\
	so_long_bonus/check_map_bonus.c\
	so_long_bonus/ft_split_bonus.c\
	so_long_bonus/help_def_bonus.c\
	so_long_bonus/main_bonus.c\

HDRS = mandatory/so_long.h

HDRS_BONUS = so_long_bonus/so_long_bonus.h

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L mlx -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(HDRS)
		make -C mlx
		$(CC) $(FLAGS) $(MLX_FLAGS) -I mlx $(OBJ) -I. -o $(NAME)

bonus: $(OBJ_BONUS) $(HDRS_BONUS)
		make -C mlx
		$(CC) $(FLAGS) $(MLX_FLAGS) -I mlx $(OBJ_BONUS) -I. -o $(NAME)

clean:
		make clean -C mlx
		rm -f $(OBJ_BONUS)
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME_BONUS)
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean