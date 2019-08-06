NAME= ft_printf

LIBFLAG= libft/libft.a

FLAGS= -Wall -Wextra -Werror

SRC= $(addsuffix .c, ft_printf parse1 parse2 parse3 init_util pf_utils)

DEBUG= -g

$(NAME):
	make -C libft all
	$(CC) $(FLAGS) $(LIBFLAG) $(SRC) -o ft_printf

all: $(NAME)

debug:
	make -C libft all
	$(CC) $(DEBUG) $(FLAGS) $(SRC) $(LIBFLAG) -o ft_printf

clean:
	make -C libft clean
	@printf "nothing to clean...\n"

fc: fclean

fclean: clean
	make -C libft fclean
	@rm $(NAME) || printf "\033[0;36mThese are not the droids you seek...\n\033[0;31m"
	@rm -rf ft_printf.dSYM

re: fclean all
.PHONY: ft_printf clean fclean re
