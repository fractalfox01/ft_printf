#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_info
{
	int		f_prefix;
	int		zero_pad;
	int		right_pad;
	int		f_sign;
	int		b_sign;
}			t_info;

struct    pf_table
{
     char *str;
     void(*function)();
};

typedef struct	s_fun
{
	size_t		(*parser_fun[15])(char *fmt, va_list *args);
}				t_ar;

typedef struct table_enty t_table;

typedef struct      s_ft_printf
{
	va_list			*ap;
	char			*ret;
	char			*fmt;
	struct s_info	*info;
}               	t_glb;

size_t	handle_escape(char *fmt, va_list *args);
size_t	handle_str(char *fmt, va_list *args);
size_t	handle_wstr(char *fmt, va_list *args);
size_t	handle_int(char *fmt, va_list *args);
size_t	handle_long(char *fmt, va_list *args);
size_t	handle_ptr(char *fmt, va_list *args);
size_t	handle_oct(char *fmt, va_list *args);
size_t	handle_unsigned(char *fmt, va_list *args);
size_t	handle_hex(char *fmt, va_list *args);
size_t	handle_char(char *fmt, va_list *args);
size_t	handle_ptr(char *fmt, va_list *args);
size_t	handle_oct(char *fmt, va_list *args);
size_t	handle_unsigned(char *fmt, va_list *args);
size_t	handle_hex(char *fmt, va_list *args);
size_t	handle_char(char *fmt, va_list *args);
size_t	handle_binary(char *fmt, va_list *args);
size_t	handle_float(char *fmt, va_list *args);
size_t	handle_uint(char *fmt, va_list *args);

#endif
