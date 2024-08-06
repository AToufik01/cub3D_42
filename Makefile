CC = cc
NAME = cub3D
MLX = libmlx42.a
CFLAGS = -g -fsanitize=address #-Wall -Wextra -Werror
LDFLAGS = -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib" -L. -lmlx42 -framework OpenGL -framework AppKit
RM = rm -f
OBJ_DIR = obj
SRC_DIR = src
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/ft_player.c $(SRC_DIR)/draw_env.c $(SRC_DIR)/update.env.c $(SRC_DIR)/ft_map.c $(SRC_DIR)/raycasting.c $(SRC_DIR)/projection3d.c  \
      $(SRC_DIR)/parse/first_parse.c $(SRC_DIR)/parse/check_map.c $(SRC_DIR)/parse/get_elements.c $(SRC_DIR)/parse/free_data.c $(SRC_DIR)/parse/utils.c \
      $(SRC_DIR)/get_next_line/get_next_line.c $(SRC_DIR)/get_next_line/get_next_line_utils.c $(SRC_DIR)/parse/linked_list.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:$(SRC_DIR)/%.c=%.o))
LIBFT = src/libft/libft.a

all: $(NAME) 

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(LIBFT)
$(LIBFT):
	@$(MAKE) -C src/libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)/subdirs
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	$(cd src/libft && make)
	
$(OBJ_DIR)/subdirs:
	@mkdir -p $(OBJ_DIR)/src/parse
	@mkdir -p $(OBJ_DIR)/src/get_next_line
clean:
	$(RM) -r $(OBJ_DIR)
	@(cd src/libft && make clean)

fclean: clean
	$(RM) $(NAME)
	@(cd src/libft && make fclean)

re: fclean all
