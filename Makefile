CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLX_PATH = ./mlx
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lX11 -lXext -lm

NAME1 = so_long.a
NAME2 = so_long_bonus.a

NAME_PROGRAM = so_long
NAME_PROGRAM_BONUS = so_long_bonus

SRCS = ./so_long_src/so_long.c ./so_long_src/map_render.c ./so_long_src/player_movement.c ./so_long_src/player_movement_utils.c ./so_long_src/get_next_line.c ./so_long_src/game_manager.c\
	   ./so_long_src/ft_split.c ./so_long_src/utils1.c ./so_long_src/utils2.c ./so_long_src/utils3.c ./so_long_src/so_long_utils.c ./so_long_src/path.c \
	   ./ft_printf/ft_printf.c  ./ft_printf/ft_putchar.c ./ft_printf/ft_copyhexa.c ./ft_printf/ft_putnbr.c ./ft_printf/ft_putstr.c ./ft_printf/ft_copyadd.c 

BONUS = ./so_long_src_bonus/so_long_bonus.c ./so_long_src_bonus/map_render_bonus.c ./so_long_src_bonus/player_movement_bonus.c ./so_long_src_bonus/get_next_line.c ./so_long_src_bonus/player_movement_utils_bonus.c \
     ./so_long_src_bonus/count_bonus.c ./so_long_src_bonus/enemy_bonus.c ./so_long_src_bonus/game_manager_bonus.c ./so_long_src_bonus/update_collectibles_bonus.c ./so_long_src_bonus/so_long_utils2_bonus.c \
	   ./so_long_src_bonus/ft_split.c ./so_long_src_bonus/utils1_bonus.c ./so_long_src_bonus/utils2_bonus.c ./so_long_src_bonus/utils3_bonus.c ./so_long_src_bonus/so_long_utils_bonus.c ./so_long_src_bonus/path_bonus.c \
	   ./ft_printf/ft_printf.c  ./ft_printf/ft_putchar.c ./ft_printf/ft_copyhexa.c ./ft_printf/ft_putnbr.c ./ft_printf/ft_putstr.c ./ft_printf/ft_copyadd.c 

OFILES = $(SRCS:.c=.o)
BOFILES = $(BONUS:.c=.o)

all: $(NAME_PROGRAM)

$(NAME1): $(OFILES)
	ar rcs $(NAME1) $(OFILES)

$(NAME_PROGRAM): $(NAME1)
	$(CC) -o $(NAME_PROGRAM) $(NAME1) $(MLX_FLAGS)
	rm -rf $(NAME1)

bonus: $(NAME_PROGRAM_BONUS)

$(NAME2): $(BOFILES)
	ar rcs $(NAME2) $(BOFILES)

$(NAME_PROGRAM_BONUS): $(NAME2)
	$(CC) -o $(NAME_PROGRAM_BONUS) $(NAME2) $(MLX_FLAGS)
	rm -rf $(NAME2)

./so_long_src/%.o: ./so_long_src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES) $(BOFILES)

fclean: clean
	rm -rf $(NAME1) $(NAME2) $(NAME_PROGRAM) $(NAME_PROGRAM_BONUS)

re: fclean all
