NAME = fractol

CFLAGS = -Wall -Werror -Wextra
CFLAGS	+= -I includes -I libft/includes
LDFLAGS	+= -L libft/ -lft -L libmlx/ -lmlx -framework OpenGL -framework AppKit

LIBFT	:= libft/libft.a
LIBMLX	:= libmlx/libmlx.a

FRACDR = main.c \
        fractol.c \
		key_commands.c \

SRC = $(addprefix src/, $(FRACDR))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C libft

$(LIBMLX):
	@make -C libmlx

$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@make -C libmlx clean
	@echo "\033[31m -- Object Files Removed --\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "\033[31m   -- libftfdf.a Removed --\033[0m"

re: fclean all
