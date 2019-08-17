/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:10:40 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/16 20:07:14 by tvandivi         ###   ########.fr       */
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

char	*pad_left(t_arg_lst *tmp, char *str)
{
	char	*stmp;
	int		len;
	int		y;
	int		x;
	size_t	i;

	i = 0;
	x = 0;
	y = 0;
	if (tmp && str)
	{
		len = ft_strlen(str);
		i = (size_t)tmp->info->fieldwidth;
		stmp = ft_strnew(i);
		ft_memset(stmp, ' ', i);
		if (tmp->info->plus_flag == 1)
		{
			if ((size_t)len > i)
				return (str);
			x = i - len;
			while (x <= (int)i && str[y] != '\0')
			{
				stmp[x++] = str[y++];
			}
			return (stmp);
		}
	}
	return (str);
}

char	*pad_right(t_arg_lst *tmp, char *str)
{
	char	*stmp;
	int		len;
	int		y;
	int		x;
	size_t	i;

	i = 0;
	x = 0;
	y = 0;
	if (tmp && str)
	{
		len = ft_strlen(str);
		i = (size_t)tmp->info->fieldwidth;
		stmp = ft_strnew(i);
		ft_memset(stmp, ' ', i);
		if (tmp->info->minus_flag == 1)
		{
			if ((size_t)len > i)
				return (str);
			while (x <= (int)i && str[y] != '\0')
			{
				stmp[x++] = str[y++];
			}
			return (stmp);
		}
	}
	return (str);
}

int		parse_string(t_glb *glb, t_arg_lst *arg, char *orig)
{
	size_t		buf_len;
	char		*buf_str;
	int			ret;
	int			i;

	ret = 0;
	i = 0;
	if (glb)
	{
		while (arg->id < glb->total)
		{
			arg = arg->next;
		}
		glb->total += 1;
		buf_str = va_arg(glb->ap, char *);
		buf_len = (size_t)arg->info->fieldwidth + ft_strlen(buf_str);
		if (arg->info->plus_flag == 1 || arg->info->hash_flag == 1)
			exit (0);
		if (arg->info->precision)
		{
			arg->info->str = ft_strnew((size_t)arg->info->precision);
			while (i < arg->info->precision && buf_str[i] != '\0')
			{
				arg->info->str[i] = buf_str[i];
				i++;
			}
			buf_str = ft_strdup(arg->info->str);
			ft_strdel(&(arg->info->str));
		}
		if (arg->info->minus_flag == 1)
			arg->info->arg = ft_strjoin(orig, pad_right(arg, buf_str));
		else
			arg->info->arg = ft_strjoin(orig, pad_left(arg, buf_str));
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (ret);
}

int		parse_char(t_glb *glb, t_arg_lst *arg, char *orig)
{
	int		ret;
	char	c;
	size_t	buf_len;
	char	*padded;

	ret = 0;
	buf_len = 0;
	if (glb && arg && orig)
	{
		while (arg->id < glb->total)
		{
			arg = arg->next;
		}
		glb->total += 1;
		c = va_arg(glb->ap, int);
		buf_len = (size_t)arg->info->fieldwidth;
		padded = ft_strnew(buf_len);
		padded[0] = c;
		if (arg->info->plus_flag == 1)
			exit (0);
		if (arg->info->minus_flag == 1)
			arg->info->arg = ft_strjoin(orig, pad_right(arg, padded));
		else
		{
			arg->info->arg = ft_strjoin(orig, pad_left(arg, padded));
		}
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (ret);
}

int		parse_int(t_glb *glb, t_arg_lst *arg, char *orig)
{
	int		ret;
	int		c;
	size_t	buf_len;
	char	*padded;
	char	*tmp;

	ret = 0;
	buf_len = 0;
	if (glb && arg && orig)
	{
		while (arg->id < glb->total)
		{
			arg = arg->next;
		}
		glb->total += 1;
		c = va_arg(glb->ap, int);
		buf_len = (size_t)arg->info->fieldwidth;
		padded = ft_itoa(c);
		if (arg->info->minus_flag == 1)
			arg->info->arg = ft_strjoin(orig, pad_right(arg, padded));
		else if (arg->info->plus_flag == 1)
		{
			tmp = ft_strjoin("+", padded);
			arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp));
			ft_strdel(&tmp);
		}
		else
			arg->info->arg = ft_strjoin(orig, pad_left(arg, padded));
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (ret);
}

int		parse_long(t_glb *glb, t_arg_lst *arg, char *orig)
{
	int	ret;

	ret = 0;
	if (glb && arg && orig)
	{
		ft_putstr("long parse\n");
	}
	return (ret);
}

int		parse_ptr(t_glb *glb, t_arg_lst *arg, char *orig)
{
	int	ret;

	ret = 0;
	if (glb && arg && orig)
	{
		ft_putstr("pointer parse\n");
	}
	return (ret);
}

int		parse_oct(t_glb *glb, t_arg_lst *arg, char *orig)
{
	int	ret;

	ret = 0;
	if (glb && arg && orig)
	{
		ft_putstr("octal parse\n");
	}
	return (ret);
}

int		parse_unsigned(t_glb *glb, t_arg_lst *arg, char *orig)
{
	int	ret;

	ret = 0;
	if (glb && arg && orig)
	{
		ft_putstr("unsigned parse\n");
	}
	return (ret);
}

int		parse_hex(t_glb *glb, t_arg_lst *arg, char *orig)
{
	int	ret;

	ret = 0;
	if (glb && arg && orig)
	{
		ft_putstr("hex parse\n");
	}
	return (ret);
}

int		parse_bin(t_glb *glb, t_arg_lst *arg, char *orig)
{
	int	ret;

	ret = 0;
	if (glb && arg && orig)
	{
		ft_putstr("binary parse\n");
	}
	return (ret);
}

int		parse_float(t_glb *glb, t_arg_lst *arg, char *orig)
{
	int	ret;

	ret = 0;
	if (glb && arg && orig)
	{
		ft_putstr("float parse\n");
	}
	return (ret);
}

int		parse_uint(t_glb *glb, t_arg_lst *arg, char *orig)
{
	int	ret;

	ret = 0;
	if (glb && arg && orig)
	{
		ft_putstr("unsigned int parse\n");
	}
	return (ret);
}

static t_arg_lst	*get_arg(t_glb *glb)
{
	t_arg_lst *arg;

	arg = glb->args;
	while (arg->id < (glb->total))
	{
		arg = arg->next;
	}
	return (arg);
}

int		parse_conversion(t_glb *glb, char *fmt, char *orig)
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
		return (glb->argfun[i](glb, get_arg(glb), orig));
	return (0);
}
