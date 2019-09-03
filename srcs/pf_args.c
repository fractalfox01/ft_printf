/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:10:40 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/03 13:18:34 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_alst	*new_list(void)
{
	t_alst	*list;
	t_info		*info;

	list = (t_alst *)malloc(sizeof(t_alst) * 1);
	info = (t_info *)malloc(sizeof(t_info) * 1);
	list->id = 0;
	list->info = info;
	list->info->fieldwidth = 0;
	list->info->precision = 0;
	list->next = NULL;
	return (list);
}

char		*fp_ltoh(long n)
{
	char	*tmp;
	char	*ret;
	char	*hex;
	int		i;

	tmp = ft_strnew(17);
	hex = ft_strdup("0123456789abcdef");
	i = 0;
	ft_memset(tmp, 0, 17);
	while (n / 16 > 0 && i < 17)
	{
		tmp[i++] = hex[(n % 16)];
		n = n / 16;
	}
	if (n > 0)
		tmp[i++] = hex[(n % 16)];
	tmp[i] = '\0';
	ret = ft_strrev(tmp);
	ft_strdel(&tmp);
	ft_strdel(&hex);
	return (ret);
}



static long	fp_lpow(long n, long base)
{
	long	i;
	long	nbr;

	i = 1;
	nbr = 1;
	if (n == 1)
		return (1);
	if (n > 1)
	{
		while (i++ < n)
			nbr *= base;
	}
	else
		return (-1);
	return (nbr);
}

static char	*fp_lhlper(char *ret, char *ip, int ap)
{
	char	*stmp;

	stmp = ft_strnew(ap);
	ft_memset(stmp, '0', ap);
	ip = ft_strdup(ret);
	ft_strdel(&ret);
	ret = ft_strjoin(ip, stmp);
	ft_strdel(&stmp);
	return (ret);
}

char	*fp_lftoa(long double flt, int afterpoint)
{
	long long	n;
	char		*int_part;
	char        *stmp;
	long double	d;
	char    	*ret;
	int			dir;

	dir = 1;
	n = (long long)flt;
	int_part = ft_strjoin(ft_lltoa(n), ".");
	d = flt - n;
	n = 0;
	if (d < 0)
	{
		dir *= -1;
		d *= dir;
	}
	while (d > 0 && n++ < afterpoint)
	{
		d = d * fp_lpow(2, 10);
		stmp = ft_itoa((int)d);
		d = d - (int)d;
		ret = ft_strjoin(int_part, stmp);
		ft_strdel(&int_part);
		int_part = ft_strdup(ret);
		ft_strdel(&stmp);
	}
	if (n < afterpoint && n != 0)
		ret = fp_lhlper(ret, int_part, afterpoint - n);
	ft_strdel(&int_part);
	return (ret);
}



int		parse_bin(t_glb *glb, t_alst *arg, char *orig)
{
	if (glb && arg && orig)
	{
		ft_putstr("binary parse\n");
	}
	return (0);
}

int		parse_long_float(t_glb *glb, t_alst *arg, char *orig)
{
	char		*padded;
	char		*tmp;
	long double	n;
	int			b;
	int			neg;

	neg = 0;
	n = 0;
	b = 0;
	if (glb && arg && orig)
	{
		n = va_arg(glb->ap, long double);
		b = arg->info->precision;
		if (b == 0)
			b = 6;
		if (n < 0)
			neg = 1;
		padded = fp_lftoa(n, b);
		if (arg->info->minus_flag == 1)
		{
			if (arg->info->plus_flag == 1 && neg == 0)
			{
				tmp = ft_strjoin("+", padded);
				arg->info->arg = ft_strjoin(orig, pad_right(arg, tmp));
				ft_strdel(&tmp);
			}
			else
				arg->info->arg = ft_strjoin(orig, pad_right(arg, padded));
		}
		else if (arg->info->plus_flag == 1 && neg == 0)
		{
			tmp = ft_strjoin("+", padded);
			arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 0));
			ft_strdel(&tmp);
		}
		else
			arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 0));
		glb->total += 1;
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (0);
}

int		parse_norm_float(t_glb *glb, t_alst *arg, char *orig)
{
	char		*padded;
	char		*tmp;
	double	n;
	int			b;
	int			neg;

	neg = 0;
	n = 0;
	b = 0;
	if (glb && arg && orig)
	{
		n = va_arg(glb->ap, double);
		b = arg->info->precision;
		if (b == 0)
			b = 6;
		if (n < 0)
			neg = 1;
		padded = ft_ftoa(n, b);
		if (arg->info->minus_flag == 1)
		{
			if (arg->info->plus_flag == 1 && neg == 0)
			{
				tmp = ft_strjoin("+", padded);
				arg->info->arg = ft_strjoin(orig, pad_right(arg, tmp));
				ft_strdel(&tmp);
			}
			else
				arg->info->arg = ft_strjoin(orig, pad_right(arg, padded));
		}
		else if (arg->info->plus_flag == 1 && neg == 0)
		{
			tmp = ft_strjoin("+", padded);
			arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 0));
			ft_strdel(&tmp);
		}
		else
			arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 0));
		glb->total += 1;
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (0);
}

int		parse_float(t_glb *glb, t_alst *arg, char *orig)
{
	double	n;
	int			b;

	n = 0;
	b = 0;
	if (glb && arg && orig)
	{
		if (arg->info->lenmod[0] == 'L' || arg->info->lenmod[0] == 'l')
			parse_long_float(glb, arg, orig);
		else if (arg->info->lenmod[0] == '\0')
			parse_norm_float(glb, arg, orig);	
	}
	return (0);
}

static t_alst	*get_arg(t_glb *glb)
{
	t_alst *arg;

	arg = glb->args;
	while (arg->id < (glb->total))
	{
		arg = arg->next;
	}
	return (arg);
}

int		null_string(t_glb *glb, t_alst *arg, char *orig)
{
	char	*padded;
	char	*tmp;
	
	glb->total += 1;
	if (glb && arg && orig)
	{
		padded = ft_strdup("%");
		if (arg->info->minus_flag == 1)
		{
			if (arg->info->plus_flag == 1)
			{
				arg->info->arg = ft_strjoin(orig, pad_right(arg, padded));
				ft_strdel(&tmp);
			}
			else
				arg->info->arg = ft_strjoin(orig, pad_right(arg, padded));
		}
		else if (arg->info->plus_flag == 1)
		{
			arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 0));
			ft_strdel(&tmp);
		}
		else
			arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 0));
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (0);
}

static void	error_handler(t_glb *glb)
{
	glb->cont = 0;
	glb->err_type = 1;
}

int		parse_conversion(t_glb *glb, char *fmt, char *orig)
{
	int		i;
	int		len;
	char	*fmt_str;
	
	i = 0;
	fmt_str = ft_strdup("scdiouxXfFp%");
	len = ft_strlen(fmt_str);
	while (*fmt != fmt_str[i] && i < len)
		i++;
	if (i == 7 || i == 9)
		glb->upcase = 1;
	if (i < len)
		glb->argfun[i](glb, get_arg(glb), orig);
	else
		error_handler(glb);
	ft_strdel(&fmt_str);
	return (0);
}
