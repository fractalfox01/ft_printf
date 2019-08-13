NAME= ft_printf

LIB= libft/libft.a

FLAGS= -Werror -Wextra -Wall

SRC= $(addsuffix .c, main ft_printf init_util pf_flags pf_args)

$(NAME):
	make -C libft all
	$(CC) $(FLAGS) $(SRC) $(LIB) -o ft_printf

all: $(NAME)

clean:
	make -C libft clean || echo 'Complete'
	rm main.o || echo 'Complete'
	rm ft_printf.o || echo 'Complete'
	rm init_util.o || echo 'Complete'
	rm pf_flags.o || echo 'Complete'
	rm pf_args.o || echo 'Complete'
	rm -rf ft_printf.dSYM || echo 'Complete'

fclean: clean
	make -C libft fclean || echo 'Complete'
	rm ft_printf || echo 'Complete'

fc: fclean

debug:
	make -C libft all
	$(CC) -g $(FLAGS) $(SRC) $(LIB) -o ft_printf

re: fclean all
