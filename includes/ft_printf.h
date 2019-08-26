/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:03:21 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/26 10:20:42 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_info
{
	int				blank_flag:2;
	int				hash_flag:2;
	int				minus_flag:2;
	int				plus_flag:2;
	int				fieldwidth;
	int				precision;
	char			lenmod[3];
	int				opt_type; // storing option type as int; signifies option being called 'x' = 120 etc..
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
	int				(*argfun[12])(struct s_ftpf *g, t_alst *a, char *o);
	char			*ret;
	size_t			ret_total;
	char			*fmt;
	int				total;
	int				buf;
	t_alst			*args;
}					t_glb;

void				glb_init(t_glb *glb);
size_t				ft_printf(char *sfmt, ...);
char				*pad_left(t_alst *tmp, char *str);
char				*pad_right(t_alst *tmp, char *str);
int					parse_conversion_spec(t_glb *glb, char *fmt, char *orig);
int					parse_string(t_glb *glb, t_alst *arg, char *orig);
int					parse_char(t_glb *glb, t_alst *arg, char *orig);
int					parse_short(t_glb *glb, t_alst *arg, char *orig);
int					parse_int(t_glb *glb, t_alst *arg, char *orig);
int					parse_long(t_glb *glb, t_alst *arg, char *orig);
int					parse_longlong(t_glb *glb, t_alst *arg, char *orig);
int					parse_ptr(t_glb *glb, t_alst *arg, char *orig);
int					parse_oct(t_glb *glb, t_alst *arg, char *orig);
int					parse_unsigned(t_glb *glb, t_alst *arg, char *orig);
int					parse_hex(t_glb *glb, t_alst *arg, char *orig);
int					parse_bin(t_glb *glb, t_alst *arg, char *orig);
int					parse_float(t_glb *glb, t_alst *arg, char *orig);
int					parse_uint(t_glb *glb, t_alst *arg, char *orig);
int					parse_conversion(t_glb *glb, char *fmt, char *orig);
t_alst				*new_list(void);

#endif
