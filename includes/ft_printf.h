/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:03:21 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/13 22:56:03 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char			*str;
	char			*arg;
}					t_info;

typedef struct		s_arg_list
{
	int						id;
	t_info					*info;
	struct s_arg_list		*next;
}					t_arg_lst;

typedef struct		s_ft_printf
{
	va_list			ap;
	int				(*argfun[12])(struct s_ft_printf *glb, t_arg_lst *arg, char *orig);
	char			*ret;
	size_t			ret_total;
	char			*fmt;
	int				total;
	int				buf;
	t_arg_lst		*args;
}					t_glb;

void				glb_init(t_glb *glb);
size_t				ft_printf(char *sfmt, ...);
int					parse_conversion_spec(t_glb *glb, char *fmt, char *orig);
int					parse_string(t_glb *glb, t_arg_lst *arg, char *orig);
int					parse_char(t_glb *glb, t_arg_lst *arg, char *orig);
int					parse_int(t_glb *glb, t_arg_lst *arg, char *orig);
int					parse_long(t_glb *glb, t_arg_lst *arg, char *orig);
int					parse_ptr(t_glb *glb, t_arg_lst *arg, char *orig);
int					parse_oct(t_glb *glb, t_arg_lst *arg, char *orig);
int					parse_unsigned(t_glb *glb, t_arg_lst *arg, char *orig);
int					parse_hex(t_glb *glb, t_arg_lst *arg, char *orig);
int					parse_bin(t_glb *glb, t_arg_lst *arg, char *orig);
int					parse_float(t_glb *glb, t_arg_lst *arg, char *orig);
int					parse_uint(t_glb *glb, t_arg_lst *arg, char *orig);
int					parse_conversion(t_glb *glb, char *fmt, char *orig);
t_arg_lst			*new_list(void);

#endif
