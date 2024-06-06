CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex
LIBFT_A = libft/libft.a
FT_PRINTF_A = ft_printf/ft_printf.a
SRC = pipex.c handle_errors.c children.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_A):
	$(MAKE) -C libft

$(FT_PRINTF_A):
	$(MAKE) -C ft_printf

$(NAME): $(OBJ) $(LIBFT_A) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_A) $(FT_PRINTF_A)

clean: $(NAME)
	rm -f $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean

re: fclean all