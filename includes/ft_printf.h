#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_info
{
	char			flag;
	int				fieldwidth;
	int				precision;
	char			lenmod[3];
	char			*arg;
}					t_info;

typedef struct		s_arg_list
{
	int				id;
	t_info			*info;
	t_arg_lst		*next;
}					t_arg_lst;

typedef int			func(t_glb *glb);

typedef struct		s_argfun
{
	func			*argfun[12];
}					t_argfun;

typedef struct      s_ft_printf
{
	va_list			ap;
	char			*ret;
	char			*fmt;
	size_t			total;
	int				buf;
	t_info			*info;
	t_argfun		*funs;
}               	t_glb;

size_t				ft_printf(char *sfmt, ...);
int					parse_conversion_spec(t_arg_lst *arglst, char *fmt);
int					parse_string(t_glb *glb);
int					parse_char(t_glb *glb);
int					parse_int(t_glb *glb);
int					parse_long(t_glb *glb);
int					parse_ptr(t_glb *glb);
int					parse_oct(t_glb *glb);
int					parse_unsigned(t_glb *glb);
int					parse_hex(t_glb *glb);
int					parse_bin(t_glb *glb);
int					parse_float(t_glb *glb);
int					parse_uint(t_glb *glb);
int					parse_conversion(t_glb *glb, char *fmt);

#endif
