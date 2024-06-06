CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex
LIBFT_A = libft/libft.a
FT_PRINTF_A = ft_printf/ft_printf.a
SRC = pipex.c handle_errors.c get_commands.c children.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_A):
	make -C libft

$(FT_PRINTF_A):
	make -C ft_printf

$(NAME): $(OBJ) $(LIBFT_A) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_A) $(FT_PRINTF_A)

clean:
	rm -f $(OBJ)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make fclean -C ft_printf 

re: fclean all