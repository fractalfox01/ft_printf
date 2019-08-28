/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:03:21 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/27 19:58:51 by tvandivi         ###   ########.fr       */
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
	void			(*argfun[12])(struct s_ftpf *g, t_alst *a, char *o);
	int				*ret;
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
void				parse_string(t_glb *glb, t_alst *arg, char *orig);
void				parse_char(t_glb *glb, t_alst *arg, char *orig);
void				parse_short(t_glb *glb, t_alst *arg, char *orig);
void				parse_int(t_glb *glb, t_alst *arg, char *orig);
void				parse_long(t_glb *glb, t_alst *arg, char *orig);
void				parse_longlong(t_glb *glb, t_alst *arg, char *orig);
void				parse_ptr(t_glb *glb, t_alst *arg, char *orig);
void				parse_oct(t_glb *glb, t_alst *arg, char *orig);
void				parse_unsigned(t_glb *glb, t_alst *arg, char *orig);
void				parse_hex(t_glb *glb, t_alst *arg, char *orig);
void				parse_bin(t_glb *glb, t_alst *arg, char *orig);
void				parse_float(t_glb *glb, t_alst *arg, char *orig);
void				parse_uint(t_glb *glb, t_alst *arg, char *orig);
void				null_string(t_glb *glb, t_alst *arg, char *orig);
int					parse_conversion(t_glb *glb, char *fmt, char *orig);
t_alst				*new_list(void);

#endif
