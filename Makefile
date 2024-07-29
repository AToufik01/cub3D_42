CC=cc
NAME=cub3D
MLX=libmlx42.a
CFLAGS= -g -fsanitize=address #-Wall -Wextra -Werror
LDFLAGS= -Iinclude -lglfw -L/Users/ataoufik/.brew/opt/glfw/lib/ -L. -lmlx42 -framework OpenGL -framework AppKit
RM=rm -f
OBJ_DIR=obj
SRC=main.c initialize_data.c ft_player.c draw_env.c update.env.c ft_map.c raycasting.c projection3d.c 
OBJ=$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all