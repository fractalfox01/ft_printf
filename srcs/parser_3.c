/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:06:18 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/11 14:29:31 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

static char	*int_helper(t_alst *arg, char *padded, int c)
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
	return (padded);
}

static char *blank_helper(t_alst *arg, char *padded)
{
	char	*tmp;

	tmp = ft_strjoin(" ", padded);
	ft_strdel(&padded);
	return (tmp);
}

static char	*lnglng_helper(t_alst *arg, char *padded, long long c)
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
	return (padded);
}

static char	*short_helper(t_alst *arg, char *padded, short c)
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
		stmp = ft_strjoin(xtmp, ft_stoa(c));
		ft_strdel(&padded);
		padded = ft_strdup(stmp);
		ft_strdel(&xtmp);
		ft_strdel(&stmp);
	}
	return (padded);
}

char	*long_helper(t_alst *arg, char *padded, long c)
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
		stmp = ft_strjoin(xtmp, ft_ltoa(c));
		ft_strdel(&padded);
		padded = ft_strdup(stmp);
		ft_strdel(&xtmp);
		ft_strdel(&stmp);
	}
	return (padded);
}

int		parse_int_normal(t_glb *glb, t_alst *arg, char *orig)
{
	int		c;
	char	*padded;
	char	*tmp;
	int		neg;

	neg = 0;
	glb->total += 1;
	c = va_arg(glb->ap, int);
	if (c < 0)
		neg = 1;
	if (c == 0 && arg->info->blank == 1)
	{
		arg->info->arg = ft_strjoin(orig, "");
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
		return (0);
	}
	if (c == 0 && arg->info->fieldwidth == 0 && arg->info->fieldwidth == 0)
	{
		arg->info->arg = ft_strjoin(orig, "0");
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
		return (0);
	}
	tmp = NULL;
	if (arg->info->precision > arg->info->fieldwidth)
		arg->info->fieldwidth = arg->info->precision;
	padded = ft_itoa(c);
	if (arg->info->precision > 0)
		padded = int_helper(arg, &*padded, c);
	if (arg->info->blank_flag)
		padded = blank_helper(arg, &*padded);
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
		arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 1));
		ft_strdel(&tmp);
	}
	else
		arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 1));
	arg->next = new_list();
	arg->next->id = (arg->id + 1);
	return (0);
}

int		parse_int(t_glb *glb, t_alst *arg, char *orig)
{
	if (glb && arg && orig)
	{
		if (arg->info->lenmod[0] == 'l' && arg->info->lenmod[1] == '\0')
			parse_long(glb, arg, orig);
		else if (arg->info->lenmod[0] == 'l' && arg->info->lenmod[1] == 'l')
			parse_longlong(glb, arg, orig);
		else if (arg->info->lenmod[0] == 'h' && arg->info->lenmod[1] == '\0')
			parse_short(glb, arg, orig);
		else if (arg->info->lenmod[0] == 'h' && arg->info->lenmod[1] == 'h')
			parse_s_short(glb, arg, orig);
		else
			parse_int_normal(glb, arg, orig);
	}
	return (0);
}

int		parse_longlong(t_glb *glb, t_alst *arg, char *orig)
{
    long long	c;
	char        *padded;
	char	    *tmp;
	int			neg;

	neg = 0;
	glb->total += 1;
	c = va_arg(glb->ap, long long);
	if (c < 0)
		neg = 1;
	if (c == 0 && arg->info->blank == 1)
	{
		arg->info->arg = ft_strjoin(orig, "");
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
		return (0);
	}
	if (c == 0 && arg->info->fieldwidth == 0 && arg->info->fieldwidth == 0)
	{
		arg->info->arg = ft_strjoin(orig, "0");
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
		return (0);
	}
	if (arg->info->precision > arg->info->fieldwidth)
		arg->info->fieldwidth = arg->info->precision;
	padded = ft_lltoa(c);
	if (arg->info->precision > 0)
		padded = lnglng_helper(arg, &*padded, c);
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
		arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 1));
		ft_strdel(&tmp);
	}
	else
		arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 1));
	arg->next = new_list();
	arg->next->id = (arg->id + 1);
	return (0);
}

int		parse_s_short(t_glb *glb, t_alst *arg, char *orig)
{
	char	c;
	char    *padded;
	char	*tmp;
	int		neg;

	neg = 0;
	glb->total += 1;
	c = (char)va_arg(glb->ap, unsigned int);
	if (c == 0 && arg->info->blank == 1)
	{
		arg->info->arg = ft_strjoin(orig, "");
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
		return (0);
	}
	if (c == 0 && arg->info->fieldwidth == 0 && arg->info->fieldwidth == 0)
	{
		arg->info->arg = ft_strjoin(orig, "0");
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
		return (0);
	}
	if (arg->info->precision > arg->info->fieldwidth)
		arg->info->fieldwidth = arg->info->precision;
	padded = ft_stoa(c);
	if (arg->info->precision > 0)
		padded = short_helper(arg, &*padded, c);
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
		arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 1));
		ft_strdel(&tmp);
	}
	else
		arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 1));
	arg->next = new_list();
	arg->next->id = (arg->id + 1);
	return (0);
}

int		parse_short(t_glb *glb, t_alst *arg, char *orig)
{
    long long	c;
	char        *padded;
	char	    *tmp;
	int			neg;

	neg = 0;
	glb->total += 1;
	c = va_arg(glb->ap, int);
	if (c < 0)
		neg = 1;
	if (c == 0 && arg->info->blank == 1)
	{
		arg->info->arg = ft_strjoin(orig, "");
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
		return (0);
	}
	if (c == 0 && arg->info->fieldwidth == 0 && arg->info->fieldwidth == 0)
	{
		arg->info->arg = ft_strjoin(orig, "0");
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
		return (0);
	}
	if (arg->info->precision > arg->info->fieldwidth)
		arg->info->fieldwidth = arg->info->precision;
	padded = ft_stoa(c);
	if (arg->info->precision > 0)
		padded = short_helper(arg, &*padded, c);
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
		arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 1));
		ft_strdel(&tmp);
	}
	else
		arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 1));
	arg->next = new_list();
	arg->next->id = (arg->id + 1);
	return (0);
}

int		parse_long(t_glb *glb, t_alst *arg, char *orig)
{
	long	c;
	char	*padded;
	char	*tmp;
	int		neg;

	neg = 0;
	glb->total += 1;
	c = va_arg(glb->ap, long);
	if (c < 0)
		neg = 1;
	if (c == 0 && arg->info->blank == 1)
	{
		arg->info->arg = ft_strjoin(orig, "");
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
		return (0);
	}
	if (c == 0)
	{
		padded = ft_strdup(" ");
		if (arg->info->precision > arg->info->fieldwidth)
			arg->info->fieldwidth = arg->info->precision;
		if (arg->info->plus_flag == 1)
		{
			if (arg->info->precision > 0)
				padded = long_helper(arg, &*padded, c);
			arg->info->arg = ft_strjoin(orig, pad_left(arg, ft_strjoin("+", padded), 1));
		}
		else if (arg->info->minus_flag == 1)
		{
			if (arg->info->precision > 0)
				padded = long_helper(arg, &*padded, c);
			arg->info->arg = ft_strjoin(orig, pad_right(arg, ft_strjoin("-", padded)));
		}
		else
			arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 1));
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
		ft_strdel(&padded);
		return (0);
	}
	if (arg->info->precision > arg->info->fieldwidth)
		arg->info->fieldwidth = arg->info->precision;
	padded = ft_ltoa(c);
	if (arg->info->precision > 0)
		padded = long_helper(arg, &*padded, c);
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
		arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 1));
		ft_strdel(&tmp);
	}
	else
		arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 1));
	arg->next = new_list();
	arg->next->id = (arg->id + 1);
	return (0);
}