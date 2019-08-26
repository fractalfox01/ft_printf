/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:06:18 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/26 16:54:05 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char    *ft_lltoa(long long n)
{
    char	    *tmp;
	char	    *ret;
	long long	i;
	long long	nbr;
	
	tmp = ft_strnew(21);
	i = 0;
	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	while (nbr / 10 > 0)
	{
		tmp[i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	tmp[i++] = nbr + 48;
	if (n < 0)
		tmp[i++] = '-';
	tmp[i] = '\0';
	ret = ft_strrev(tmp);
	ft_strdel(&tmp);
	return (ret);
}

char    *ft_stoa(short n)
{
    char	    *tmp;
	char	    *ret;
	short   	i;
	short   	nbr;
	
	tmp = ft_strnew(21);
	i = 0;
	nbr = (short)n;
	if (nbr < 0)
		nbr *= -1;
	while (nbr / 10 > 0)
	{
		tmp[i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	tmp[i++] = nbr + 48;
	if (n < 0)
		tmp[i++] = '-';
	tmp[i] = '\0';
	ret = ft_strrev(tmp);
	ft_strdel(&tmp);
	return (ret);
}

static void	int_helper(t_alst *arg, char *padded, int c)
{
	int		len;
	int		zero;
	char	*xtmp;
	char	*stmp;
	
	len = ft_strlen(padded);
	if (c < 0)
		len--;
	zero = arg->info->precision - len;
	if (zero >= 0)
	{
		if (c < 0)
			zero++;
		xtmp = ft_strnew(zero);
		ft_memset(xtmp, '0', zero);
		if (c < 0)
		{
			xtmp[0] = '-';
			c = ft_abs(c);
		}
		stmp = ft_strjoin(xtmp, ft_itoa(c));
		ft_strdel(&padded);
		padded = ft_strdup(stmp);
		ft_strdel(&xtmp);
		ft_strdel(&stmp);
	}
}

static void lnglng_helper(t_alst *arg, char *padded, long long c)
{
    int		len;
	int		zero;
	char	*xtmp;
	char	*stmp;
	
	len = ft_strlen(padded);
	if (c < 0)
		len--;
	zero = arg->info->precision - len;
	if (zero >= 0)
	{
		if (c < 0)
			zero++;
		xtmp = ft_strnew(zero);
		ft_memset(xtmp, '0', zero);
		if (c < 0)
		{
			xtmp[0] = '-';
			c *= -1;
		}
		stmp = ft_strjoin(xtmp, ft_lltoa(c));
		ft_strdel(&padded);
		padded = ft_strdup(stmp);
		ft_strdel(&xtmp);
		ft_strdel(&stmp);
	}
}

int		parse_int_normal(t_glb *glb, t_alst *arg, char *orig, int ret)
{
	int		c;
	char	*padded;
	char	*tmp;

	glb->total += 1;
	c = va_arg(glb->ap, int);
	if (arg->info->precision > arg->info->fieldwidth)
		arg->info->fieldwidth = arg->info->precision;
	padded = ft_itoa(c);
	if (arg->info->precision > 0)
		int_helper(arg, &*padded, c);
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
	return (ret);
}

int		parse_int(t_glb *glb, t_alst *arg, char *orig)
{
	int		ret;
	
	ret = 0;
	if (glb && arg && orig)
	{
		if (arg->info->lenmod[0] == 'l' && arg->info->lenmod[1] == '\0')
			ret = parse_long(glb, arg, orig);
		else if (arg->info->lenmod[0] == 'l' && arg->info->lenmod[1] == 'l')
			ret = parse_longlong(glb, arg, orig);
		else if (arg->info->lenmod[0] == 'h' && arg->info->lenmod[1] == '\0')
			ret = parse_short(glb, arg, orig);
		else if (arg->info->lenmod[0] == 'h' && arg->info->lenmod[1] == 'h')
			ret = parse_char(glb, arg, orig);
		else
			ret = parse_int_normal(glb, arg, orig, ret);
	}
	return (ret);
}

int		parse_longlong(t_glb *glb, t_alst *arg, char *orig)
{
    int         ret;
    long long	c;
	char        *padded;
	char	    *tmp;

    ret = 0;
	glb->total += 1;
	c = va_arg(glb->ap, long long);
	if (arg->info->precision > arg->info->fieldwidth)
		arg->info->fieldwidth = arg->info->precision;
	padded = ft_lltoa(c);
	if (arg->info->precision > 0)
		lnglng_helper(arg, &*padded, c);
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
	return (ret);
}

int		parse_short(t_glb *glb, t_alst *arg, char *orig)
{
	int     ret;
    int   n;

	ret = 0;
    n = 0;
	if (glb && arg && orig)
	{
        n = va_arg(glb->ap, int);
        arg->info->arg = ft_strjoin(orig, ft_stoa(n));
        glb->total += 1;
        arg->next = new_list();
        arg->next->id = (arg->id + 1);
    }
	return (ret);
}

int		parse_long(t_glb *glb, t_alst *arg, char *orig)
{
	int		ret;
	long	c;
	int		len;
	int		zero;
	char	*xtmp;
	char	*stmp;
	size_t	buf_len;
	char	*padded;
	char	*tmp;

	ret = 0;
	zero = 0;
	buf_len = 0;
	if (glb && arg && orig)
	{
		glb->total += 1;
		c = va_arg(glb->ap, long);
		if (arg->info->precision > arg->info->fieldwidth)
			arg->info->fieldwidth = arg->info->precision;
		buf_len = (size_t)arg->info->fieldwidth;
		padded = ft_ltoa(c);
		if (arg->info->precision > 0)
		{
			len = ft_strlen(padded);
			if (c < 0)
				len--;
			zero = arg->info->precision - len;
			if (zero >= 0)
			{
				if (c < 0)
					zero++;
				xtmp = ft_strnew(zero);
				ft_memset(xtmp, '0', zero);
				if (c < 0)
				{
					xtmp[0] = '-';
					c = ft_abs(c);
				}
				stmp = ft_strjoin(xtmp, ft_ltoa(c));
				ft_strdel(&padded);
				padded = ft_strdup(stmp);
				ft_strdel(&xtmp);
				ft_strdel(&stmp);
			}
		}
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