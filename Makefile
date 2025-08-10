# Configuration --------------------------------------------------- #

NAME = fractol

HEADER = h_fractol.h

MLX_PATH = minilibx-linux/

MLX = minilibx-linux/libmlx.a

# Flags ----------------------------------------------------------- #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

MAKE = make

# Files ----------------------------------------------------------- #

C_FILES = main.c draw.c utils.c init.c calculations.c events.c parse.c

O_DIR = objs

O_FILES = $(patsubst %.c, $(O_DIR)/%.o, $(C_FILES))

# Pattern Rule ---------------------------------------------------- #

all: verify_mlx $(MLX) $(NAME)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

$(NAME): $(O_FILES)
	@$(CC) $(CFLAGS) -std=gnu99 -I. $(O_FILES) -L -lmlx -lXext -lX11 minilibx-linux/libmlx_Linux.a -o $(NAME)
	@echo "Compiled Program"

$(O_DIR)/%.o: %.c $(HEADER) | $(O_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

verify_mlx:
	@if test ! -d $(MLX); then make $(MLX); fi 

# Directory Rule -------------------------------------------------- #

$(O_DIR):
	@mkdir -p $@

# Phonies --------------------------------------------------------- #

.PHONY: all clean fclean re norm

norm:
	@norminette -R CheckForbiddenSourceHeader $(C_FILES) $(HEADER)

clean:
	@rm -rf $(O_FILES) $(O_DIR)
	@echo "Cleaned object files"

fclean: clean
	@rm -rf $(NAME)
	@echo "Removed fractol"

re: fclean all
