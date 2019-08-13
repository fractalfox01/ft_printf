/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:10:40 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/12 21:17:23 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_arg_lst	*new_list(void)
{
	t_arg_lst	*list;
	t_info		*info;

	list = (t_arg_lst *)malloc(sizeof(t_arg_lst) * 1);
	info = (t_info *)malloc(sizeof(t_info) * 1);
	list->id = 0;
	list->info = info;
	list->info->fieldwidth = 0;
	list->info->precision = 0;
	list->next = NULL;
	return (list);
}

char	*pad_arg(t_arg_lst *tmp, char *s2)
{
	// char	*n_str;
	char	*stmp;
	int		len;
	int		y;
	int		x;
	size_t	i;

	i = 0;
	x = 0;
	y = 0;
	if (tmp && s2)
	{
		len = ft_strlen(s2);
		i = (size_t)tmp->info->fieldwidth;
		stmp = ft_strnew(i);
		ft_memset(stmp, ' ', i);
		if (tmp->info->flag == '\0')
		{
			if ((size_t)len > i)
				return (s2);
			x = i - len - 1;
			while (x <= (int)i && s2[y] != '\0')
			{
				stmp[x++] = s2[y++];
			}
			return (stmp);
		}
	}
	return (s2);
}

int		parse_string(t_glb *glb, t_arg_lst *arg)
{
	size_t		buf_len;
	char		*buf_str;
	int			ret;

	ret = 0;
	if (glb)
	{
		while (arg->id < glb->total)
		{
			arg = arg->next;
		}
		glb->total += 1;
		buf_str = va_arg(glb->ap, char *);
		buf_len = (size_t)arg->info->fieldwidth + ft_strlen(buf_str);
		if (arg->info->flag == '+' || arg->info->flag == '#')
			exit (0);
		arg->info->arg = ft_strdup(pad_arg(arg, buf_str));
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (ret);
}

int		parse_char(t_glb *glb, t_arg_lst *arg)
{
	int	ret;

	ret = 0;
	if (glb && arg)
	{
		
	}
	return (ret);
}

int		parse_int(t_glb *glb, t_arg_lst *arg)
{
	int	ret;

	ret = 0;
	if (glb && arg)
	{
		
	}
	return (ret);
}

int		parse_long(t_glb *glb, t_arg_lst *arg)
{
	int	ret;

	ret = 0;
	if (glb && arg)
	{
		
	}
	return (ret);
}

int		parse_ptr(t_glb *glb, t_arg_lst *arg)
{
	int	ret;

	ret = 0;
	if (glb && arg)
	{
		
	}
	return (ret);
}

int		parse_oct(t_glb *glb, t_arg_lst *arg)
{
	int	ret;

	ret = 0;
	if (glb && arg)
	{
		
	}
	return (ret);
}

int		parse_unsigned(t_glb *glb, t_arg_lst *arg)
{
	int	ret;

	ret = 0;
	if (glb && arg)
	{
		
	}
	return (ret);
}

int		parse_hex(t_glb *glb, t_arg_lst *arg)
{
	int	ret;

	ret = 0;
	if (glb && arg)
	{
		
	}
	return (ret);
}

int		parse_bin(t_glb *glb, t_arg_lst *arg)
{
	int	ret;

	ret = 0;
	if (glb && arg)
	{
		
	}
	return (ret);
}

int		parse_float(t_glb *glb, t_arg_lst *arg)
{
	int	ret;

	ret = 0;
	if (glb && arg)
	{
		
	}
	return (ret);
}

int		parse_uint(t_glb *glb, t_arg_lst *arg)
{
	int	ret;

	ret = 0;
	if (glb && arg)
	{
		
	}
	return (ret);
}

static t_arg_lst	*get_arg(t_glb *glb)
{
	t_arg_lst *arg;

	arg = glb->args;
	while (arg->id < (glb->total - 1))
	{
		arg = arg->next;
	}
	return (arg);
}

int		parse_conversion(t_glb *glb, char *fmt)
{
	int		i;
	char	*fmt_str;
	
	i = 0;
	fmt_str = ft_strdup("scdiouxXfp");
	if (*fmt == '%')
		fmt += 1;
	while (*fmt != fmt_str[i])
		i++;
	ft_strdel(&fmt_str);
	if (i < 10)
		return (glb->argfun[i](glb, get_arg(glb)));
	return (0);
}
