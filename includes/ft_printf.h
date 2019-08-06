#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct		s_info
{
	int				hash_pad;
	int				zero_pad;
	int				plus_sign;
	int				minus_sign;
	int				space;
}					t_info;

struct    			pf_table
{
     char 			*str;
     void(*function)();
};

typedef struct		s_fun
{
	size_t			(*parser_fun[15])();
}					t_ar;

typedef struct table_enty t_table;

typedef struct      s_ft_printf
{
	va_list			ap;
	char			*ret;
	char			*fmt;
	size_t			pad_size;
	char			*arg;
	t_info			info;
}               	t_glb;

void				ar_init(t_ar *ar);
void				glb_init(t_glb *glb);
char				*parse_padding(t_glb *glb, char *fmt);
int					ft_isnotpadding(char c);
void				flag_catcher(t_glb *glb, char *fmt);
size_t				handle_escape(t_glb *glb, char *fmt);
size_t				handle_str(t_glb *glb, char *fmt);
size_t				handle_wstr(t_glb *glb, char *fmt);
size_t				handle_int(t_glb *glb, char *fmt);
size_t				handle_long(t_glb *glb, char *fmt);
size_t				handle_ptr(t_glb *glb, char *fmt);
size_t				handle_oct(t_glb *glb, char *fmt);
size_t				handle_unsigned(t_glb *glb, char *fmt);
size_t				handle_hex(t_glb *glb, char *fmt);
size_t				handle_char(t_glb *glb, char *fmt);
size_t				handle_binary(t_glb *glb, char *fmt);
size_t				handle_float(t_glb *glb, char *fmt);
size_t				handle_uint(t_glb *glb, char *fmt);
void				flag_catcher(t_glb *glb, char *fmt);
void				parser(t_glb *glb, char *fmt);

#endif
