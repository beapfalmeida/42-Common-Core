CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = pipex
BONUS = pipex_bonus
DIR = mandatory
LIBFT_A = libft/libft.a
FT_PRINTF_A = ft_printf/ft_printf.a
SRC = mandatory/pipex.c mandatory/handle_errors.c mandatory/get_commands.c mandatory/children.c
BONUS_SRC = bonus/pipex_bonus.c bonus/handle_errors_bonus.c bonus/get_commands_bonus.c bonus/children_bonus.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(LIBFT_A):
	make -C libft

$(FT_PRINTF_A):
	make -C ft_printf

$(NAME): $(OBJ) $(LIBFT_A) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_A) $(FT_PRINTF_A)

bonus: $(BONUS) 

$(BONUS): $(BONUS_OBJ) $(LIBFT_A) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJ) $(LIBFT_A) $(FT_PRINTF_A)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME) $(BONUS)
	make fclean -C libft
	make fclean -C ft_printf 

re: fclean all
