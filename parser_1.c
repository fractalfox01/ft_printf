/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:08:10 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/26 10:42:59 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		parse_string(t_glb *glb, t_alst *arg, char *orig)
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
		if (!(buf_str))
		{
			arg->info->arg = ft_strjoin(orig, "");
			arg->next = new_list();
			arg->next->id = (arg->id + 1);
		}
		else
		{
			buf_len = (size_t)arg->info->fieldwidth + ft_strlen(buf_str);
			if (arg->info->plus_flag == 1 || arg->info->hash_flag == 1 || arg->info->blank_flag == 1)
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
	}
	return (ret);
}

int		parse_char(t_glb *glb, t_alst *arg, char *orig)
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
			arg = arg->next;
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
			arg->info->arg = ft_strjoin(orig, pad_left(arg, padded));
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (ret);
}

int		parse_oct(t_glb *glb, t_alst *arg, char *orig)
{
	int	ret;
	long n;

	ret = 0;
	n = 0;
	if (glb && arg && orig)
	{
		n = va_arg(glb->ap, long);
		arg->info->arg = ft_strjoin(orig, ft_itoa(ft_ltoo(n)));
		glb->total += 1;
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (ret);
}

int		parse_unsigned(t_glb *glb, t_alst *arg, char *orig)
{
	int				ret;
	unsigned		n;
	unsigned long	l;

	ret = 0;
	n = 0;
	l = 0;
	if (glb && arg && orig)
	{
		if (arg->info->lenmod[0] == 'l')
		{
			l = va_arg(glb->ap, unsigned long);
			arg->info->arg = ft_strjoin(orig, ft_ltoa(l));
			glb->total += 1;
			arg->next = new_list();
			arg->next->id = arg->id + 1;
		}
		else
		{
			n = va_arg(glb->ap, unsigned);
			arg->info->arg = ft_strjoin(orig, ft_ltoa(n));
			glb->total += 1;
			arg->next = new_list();
			arg->next->id = (arg->id + 1);
		}
	}
	return (ret);
}

int		parse_hex(t_glb *glb, t_alst *arg, char *orig)
{
	int				ret;
	int				i;
	long	l;
	char			*str;

	ret = 0;
	i = 0;
	l = 0;
	if (glb && arg && orig)
	{
		if (arg->info->lenmod[0] == 'l')
		{
			l = va_arg(glb->ap, long);
			str = ft_ltoh(l);
			arg->info->arg = ft_strjoin(orig, str);
			glb->total += 1;
			arg->next = new_list();
			arg->next->id = arg->id + 1;
		}
		else
		{
			i = va_arg(glb->ap, int);
			arg->info->arg = ft_strjoin(orig, ft_itoh(i));
			glb->total += 1;
			arg->next = new_list();
			arg->next->id = arg->id + 1;
		}
	}
	return (ret);
}
