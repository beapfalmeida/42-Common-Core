CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = pipex
BONUS = pipex_bonus
DIR = mandatory
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = libft/ft_printf
FT_PRINTF_A = $(FT_PRINTF_DIR)/ft_printf.a
SRC = mandatory/pipex.c mandatory/handle_errors.c mandatory/get_commands.c mandatory/children.c
BONUS_SRC = bonus/pipex_bonus.c bonus/handle_errors_bonus.c bonus/get_commands_bonus.c bonus/children_bonus.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: libft $(NAME)

libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
	git clone git@github.com:beapfalmeida/libft.git $(LIBFT_DIR); \
	fi

$(LIBFT_A): libft
	$(MAKE) -C $(LIBFT_DIR) bonus

$(FT_PRINTF_A): libft
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJ) $(LIBFT_A) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_A) $(FT_PRINTF_A)

bonus: libft $(BONUS)

$(BONUS): $(BONUS_OBJ) $(LIBFT_A) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJ) $(LIBFT_A) $(FT_PRINTF_A)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

## adicionar ifs para se nao existir libft dar para deletar o executavel e object files
fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

libclean:
	rm -rf 	$(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus libft