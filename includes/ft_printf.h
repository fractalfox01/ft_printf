/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:03:21 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/20 12:38:27 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "../srcs/libft.h"

# define PF_NULL		(void *)0
# define FMT_SPEC		"scdiouxXfp"
# define IS_UPPERCASE	glb->upcase
# define OUTPUT			tmp->info->arg
# define PADDED			arg->info->padded
# define BLANK			arg->info->blank
# define FIELDWIDTH		arg->info->fieldwidth
# define PRECISION		arg->info->precision
# define LENMOD			arg->info->lenmod
# define MINUS_FLAG		arg->info->minus_flag
# define PLUS_FLAG		arg->info->plus_flag
# define HASH_FLAG		arg->info->hash_flag
# define BLANK_FLAG		arg->info->blank_flag
# define ZERO_FLAG		arg->info->zero_flag
# define NEGATIVE		arg->info->neg
# define ARG			arg->info->arg
# define STR			arg->info->str
# define TMP1			arg->info->tmp1
# define TMP2			arg->info->tmp2
# define CUR_ID			arg->id
# define NEXT_ID		arg->next->id
# define T_COUNT		glb->total

typedef struct		s_var
{
	int				i;
	int				stop;
	int				start;
	char			*leftovers;
	char			*tmp;
	char			*arg;
	char			*fmt;
}					t_var;

typedef struct		s_info
{
	int				blank_flag:2;
	int				hash_flag:2;
	int				minus_flag:2;
	int				plus_flag:2;
	int				zero_flag:2;
	int				fieldwidth;
	int				precision;
	int				blank;
	char			lenmod[3];
	int				neg;
	char			*padded;
	char			*tmp1;
	char			*tmp2;
	char			*str;
	char			*arg;
}					t_info;

typedef struct		s_alist
{
	int				id;
	t_info			*info;
	struct s_alist	*next;
}					t_alst;

typedef struct		s_ftpf
{
	va_list			ap;
	int				(*argfun[15])(struct s_ftpf *g, t_alst *a, char *o);
	int				*ret;
	int				ncount;
	size_t			ret_total;
	char			*fmt;
	int				total;
	int				buf;
	int				upcase;
	int				cont;
	int				err_type;
	t_alst			*args;
}					t_glb;

int					ft_printf(char *format, ...);
t_glb				*glb_init(t_glb *glb);
int					has_args(char *fmt);
void				save_args(t_glb *glb);
void				init_var(t_var *var, t_glb *glb);
void				add_remainder(t_glb *glb, char *lo);
int					parse_flags(t_alst *arglst, char *fmt);
t_alst				*get_arg(t_glb *glb);
int					parse_fieldwidth(t_alst *arglst, char *fmt);
int					parse_precision(t_alst *arglst, char *fmt);
int					parse_lengthmod(t_alst *arglst, char *fmt);
char				*pad_left(t_alst *tmp, char *str, int a);
char				*pad_right(t_alst *tmp, char *str);
int					parse_conversion_spec(t_glb *glb, char *fmt, char *orig);
int					parse_string(t_glb *glb, t_alst *arg, char *orig);
int					parse_char(t_glb *glb, t_alst *arg, char *orig);
int					parse_s_short(t_glb *glb, t_alst *arg, char *orig);
int					parse_short(t_glb *glb, t_alst *arg, char *orig);
int					parse_int(t_glb *glb, t_alst *arg, char *orig);
int					parse_int_normal(t_glb *glb, t_alst *arg, char *orig);
int					parse_long(t_glb *glb, t_alst *arg, char *orig);
int					parse_longlong(t_glb *glb, t_alst *arg, char *orig);
int					parse_ptr(t_glb *glb, t_alst *arg, char *orig);
int					parse_oct(t_glb *glb, t_alst *arg, char *orig);
int					parse_unsigned(t_glb *glb, t_alst *arg, char *orig);
int					parse_hex(t_glb *glb, t_alst *arg, char *orig);
int					parse_bin(t_glb *glb, t_alst *arg, char *orig);
int					parse_float(t_glb *glb, t_alst *arg, char *orig);
int					parse_uint(t_glb *glb, t_alst *arg, char *orig);
int					percent_string(t_glb *glb, t_alst *arg, char *orig);
int					bad_percent(t_glb *glb, t_alst *arg, char *orig, char *fmt);
int					parse_conversion(t_glb *glb, char *fmt, char *orig);
char				*int_helper(t_alst *arg, char *padded, int c);
char				*short_helper(t_alst *arg, char *padded, short c);
int					int_norm_helper_1(t_alst *arg, char *orig, int c);
void				int_norm_helper_2(t_alst *arg, char *orig, char *padded);
char				*long_helper(t_alst *arg, char *padded, long c);
void				ps_helper_1(t_alst *arg, char *orig);
void				ps_helper_2(t_alst *arg, char *orig, char *buf_str);
void				ps_helper_3(t_alst *arg, char *orig, char *buf_str);
void				lnglng_oct_helper(t_alst *arg, long long c, int len);
void				long_hex_helper(t_alst *arg, long c, int len);
char				*assign_x_buf(t_glb *glb, t_alst *arg, long long c);
void				check_case(t_glb *glb, char **str);
void				hex_flag_find(t_alst *arg, int neg, char *orig);
void				hex_helper_1(t_alst *arg, int a);
void				hex_helper_2(t_glb *glb, t_alst *arg);
void				octal_assign_1(t_alst *arg, char *pad, char *orig, int neg);
void				octal_assign_2(t_alst *arg, char *padded, char *orig);
char				*assign_u_buf(t_alst *arg, unsigned long long c);
void				assign_u_arg(t_alst *arg, char *pad, int neg, char *orig);
char				*blank_helper(t_alst *arg, char *padded);
t_alst				*new_list(void);

#endif
