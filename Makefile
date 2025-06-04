NAME = so_long

NAME_BONUS = so_long_bonus

SOLONG = so_long.a

SOLONGBONUS = so_long_bonus.a

CC = cc

LIB_SYS = -ldl -lglfw -pthread -lm

FLAGS = -Wall -Werror -Wextra -I Libft/includes -I MLX42/include/MLX42

LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX42_PATH = ./MLX42/build
MLX42 = $(MLX42_PATH)/libmlx42.a

SRC = src

SRCB = srcb

FILES = $(SRC)/check_map.c\
$(SRC)/utils.c\
$(SRC)/init_struct.c\
$(SRC)/moves.c\
$(SRC)/open_game.c\
$(SRC)/read_map.c\
$(SRC)/so_long.c

FILES_BONUS = $(SRCB)/check_map_bonus.c\
$(SRCB)/enemy_bonus.c\
$(SRCB)/utils_bonus.c\
$(SRCB)/init_struct_bonus.c\
$(SRCB)/moves_bonus.c\
$(SRCB)/open_game_bonus.c\
$(SRCB)/read_map_bonus.c\
$(SRCB)/so_long_bonus.c

OBJECTS = $(FILES:.c=.o)

OBJECTS_BONUS = $(FILES_BONUS:.c=.o)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX42)
	$(CC) $(FLAGS) $(OBJECTS) $(MLX42) $(LIBFT) $(LIB_SYS) -o $(NAME)

$(OBJECTS):	src/%.o : src/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -s -C $(LIBFT_PATH)

$(MLX42):
	make -s -C $(MLX42_PATH)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJECTS_BONUS) $(LIBFT) $(MLX42)
	cc $(FLAGS) $(OBJECTS_BONUS) $(LIBFT) $(MLX42) $(LIB_SYS) -o $(NAME_BONUS)

$(OBJECTS_BONUS):	srcb/%.o : srcb/%.c
	cc $(FLAGS) -c $< -o $@

clean:
	@ rm -rf $(OBJECTS) $(OBJECTS_BONUS)
	@ make clean -s -C $(MLX42_PATH)
	@ make clean -s -C $(LIBFT_PATH)

fclean: clean
	@ rm -rf $(NAME_BONUS) $(NAME) $(LIBFT) $(MLX42)
	@ make fclean -s -C ./Libft

re: fclean all

.PHONY: all re clean fclean bonus