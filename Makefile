# Configuration --------------------------------------------------- #

NAME = fractol

HEADER = h_fractol.h

# Flags ----------------------------------------------------------- #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

#LFLAGS = -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm

# Files ----------------------------------------------------------- #

C_FILES = fractol.c draw.c utils.c init.c calculations.c events.c parse.c

O_DIR = objs

O_FILES = $(patsubst %.c, $(O_DIR)/%.o, $(C_FILES))

# Pattern Rule ---------------------------------------------------- #

$(NAME): $(O_FILES)
	@$(CC) $(CFLAGS) -std=gnu99 -I. $(O_FILES) -L -lmlx -lXext -lX11 minilibx-linux/libmlx_Linux.a -o $(NAME)
	@echo "Compiled Program"

$(O_DIR)/%.o: %.c $(HEADER) | $(O_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Directory Rule -------------------------------------------------- #

$(O_DIR):
	@mkdir -p $@

# Phonies --------------------------------------------------------- #

.PHONY: all clean fclean re

all: $(NAME)

norm:
	@norminette -R CheckForbiddenSourceHeader $(C_FILES) $(HEADER)

clean:
	@rm -rf $(O_FILES) $(O_DIR)
	@echo "Cleaned object files"

fclean: clean
	@rm -rf $(NAME)
	@echo "Removed fractol"

re: fclean all
