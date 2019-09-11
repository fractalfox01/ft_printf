NAME= libftprintf.a

LIB= libft/libft.a

FLAGSD= -Werror -Wextra -Wall

# SRCT=	$(addsuffix .c, main \
# 		test_a \
# 		test_c \
# 		test_d \
# 		test_e \
# 		test_f \
# 		test_g \
# 		test_hhhllljz \
# 		test_i \
# 		test_l \
# 		test_lc \
# 		test_ls \
# 		test_minus \
# 		test_mix \
# 		test_n \
# 		test_o \
# 		test_p \
# 		test_plus \
# 		test_precision \
# 		test_s \
# 		test_sharp \
# 		test_space \
# 		test_star \
# 		test_u \
# 		test_x \
# 		test_ld \
# 		test_mix2 \
# 		test_zero)

# SRCTO=	$(addsuffix .o, main \
# 		test_a \
# 		test_c \
# 		test_d \
# 		test_e \
# 		test_f \
# 		test_g \
# 		test_hhhllljz \
# 		test_i \
# 		test_l \
# 		test_lc \
# 		test_ls \
# 		test_minus \
# 		test_mix \
# 		test_n \
# 		test_o \
# 		test_p \
# 		test_plus \
# 		test_precision \
# 		test_s \
# 		test_sharp \
# 		test_space \
# 		test_star \
# 		test_u \
# 		test_x \
# 		test_ld \
# 		test_mix2 \
# 		test_zero)

SRC= $(addsuffix .c, srcs/pad_util srcs/parser_1 srcs/parser_2 srcs/parser_3 srcs/parser_4 srcs/ft_printf srcs/init_util srcs/pf_utils srcs/pf_flags srcs/pf_args srcs/ft_lftoa \
	srcs/ft_lltoo srcs/ft_atoll srcs/ft_lltoa srcs/ft_strrev srcs/ft_itoh srcs/ft_ftoa srcs/ft_otoi srcs/ft_itoo srcs/ft_ltoo srcs/ft_ltoh srcs/ft_ltoa \
	srcs/ft_numlen srcs/ft_abs srcs/ft_strbuild srcs/ft_power srcs/ft_itoa srcs/ft_strjoin srcs/ft_strdel srcs/ft_strnew srcs/ft_atoi srcs/ft_memcpy \
	srcs/ft_memalloc srcs/ft_strncpy srcs/ft_memset srcs/ft_strcat srcs/ft_strdup srcs/ft_bzero srcs/ft_isdigit srcs/ft_putchar srcs/ft_putnbr \
	srcs/ft_strcmp srcs/ft_strlen srcs/ft_isalpha srcs/ft_putstr srcs/ft_toupper srcs/ft_strxlen srcs/ft_isascii srcs/ft_lltoh srcs/ft_ctoh srcs/ft_ustoh \
	srcs/ft_uctoa srcs/ft_ustoa srcs/ft_uitoa srcs/ft_ultoa srcs/ft_ulltoa srcs/helper_fun_1 srcs/helper_fun_2 srcs/helper_fun_3)

OBJ= $(addsuffix .o, pad_util parser_1 parser_2 parser_3 parser_4 ft_printf init_util pf_utils pf_flags pf_args ft_lftoa ft_lltoo \
	ft_atoll ft_lltoa ft_strrev ft_itoh ft_ftoa ft_otoi ft_itoo ft_ltoo ft_ltoh ft_ltoa ft_numlen \
	ft_abs ft_strbuild ft_power ft_itoa ft_strjoin ft_strdel ft_strnew ft_atoi ft_memcpy ft_memalloc ft_strncpy \
	ft_memset ft_strcat ft_strdup ft_bzero ft_isdigit ft_putchar ft_putnbr ft_strcmp ft_strlen ft_putstr ft_ctoh ft_ustoh\
	ft_toupper ft_strxlen ft_isalpha ft_isascii ft_lltoh ft_uctoa ft_ustoa ft_uitoa ft_ultoa ft_ulltoa helper_fun_1 \
	helper_fun_2 helper_fun_3)

$(NAME):
	@echo "\033[0;32mBuilding ft_printf..."
	@$(CC) -c $(SRC) $(SRCT)
	@ar rc libftprintf.a $(OBJ) $(SRCTO)
	@mv $(OBJ) $(SRCTO) obj/
	@$(CC) $(FLAGS) libftprintf.a srcs/main.c -o ft_printf

all: $(NAME)

clean:
	@echo "\033[1;32mCleaning"
	@rm main.o 2>/dev/null || 2>/dev/null
	@for f in $(OBJ) ; do \
		rm obj/$$f 2>/dev/null && echo "\033[0;36mSuccessfully Removed $$f" || 2>/dev/null ; \
	done
	@for f in $(SRCTO) ; do \
		rm obj/$$f 2>/dev/null && echo "\033[0;36mSuccessfully Removed $$f" || 2>/dev/null ; \
	done

fclean: clean
	@echo "\033[1;32mFull Cleaning"
	@rm libftprintf.a 2>/dev/null && echo "\033[0;36mSuccessfully Removed libftprintf.a" || 2>/dev/null
	@rm ft_printf 2>/dev/null && echo "\033[0;36mSuccessfully Removed ft_printf" || 2>/dev/null
	@rm -r ft_printf.dSYM 2>/dev/null && echo "\033[0;36mSuccessfully Removed ft_printf.dSYM" || 2>/dev/null

fc: fclean

debug: fc
	#ar rc libftprintf.a $(OBJ)
	$(CC) -g $(FLAGS) $(SRC) $(SRCT) srcs/main.c -o ft_printf

re: fclean all
