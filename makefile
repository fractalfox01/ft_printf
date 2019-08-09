NAME= ft_printf

LIB= libft/libft.a

FLAGS= -Werror -Wextra -Wall

SRC= $(addsuffix .c, main ft_printf init_util pf_flags pf_args)

$(NAME):
	make -C libft all
	$(CC) $(FLAGS) $(SRC) $(LIB) -o ft_printf

all: $(NAME)

clean:
	make -C libft clean
	rm main.o
	rm ft_printf.o
	rm init_util.o
	rm pf_flags.o
	rm pf_args.o

fclean:
	make -C libft fclean

re: fclean all
