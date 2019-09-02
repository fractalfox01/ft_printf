/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:08:10 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/02 15:38:59 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

int		parse_string(t_glb *glb, t_alst *arg, char *orig)
{
	size_t		buf_len;
	char		*buf_str;
	int			i;

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
				arg->info->arg = ft_strjoin(orig, pad_left(arg, buf_str, 0));
			arg->next = new_list();
			arg->next->id = (arg->id + 1);
		}
	}
	return (0);
}

int		parse_char(t_glb *glb, t_alst *arg, char *orig)
{
	int		c;
	size_t	buf_len;
	char	*padded;

	buf_len = 0;
	if (glb && arg && orig)
	{
		glb->total += 1;
		c = va_arg(glb->ap, int);
		if (c > 127 || c < 0)
			c = '?';
		if (c == 0)
			write(1, "\0", 1);
		buf_len = (size_t)arg->info->fieldwidth;
		if (buf_len)
			padded = ft_strnew(buf_len);
		else
			padded = ft_strdup(" ");	
		padded[0] = c;
		if (arg->info->plus_flag == 1)
			exit (0);
		if (arg->info->minus_flag == 1)
			arg->info->arg = ft_strjoin(orig, pad_right(arg, padded));
		else
			arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 0));
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (0);
}

static void lnglng_oct_helper(t_alst *arg, char *padded, long long c, int len)
{
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

static void long_hex_helper(t_alst *arg, char *padded, long c, int len)
{
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
		stmp = ft_strjoin(xtmp, ft_ltoh(c));
		ft_strdel(&padded);
		padded = ft_strdup(stmp);
		ft_strdel(&xtmp);
		ft_strdel(&stmp);
	}
}

int		parse_oct(t_glb *glb, t_alst *arg, char *orig)
{
	long long	c;
	char		*padded;
	char		*tmp;
	int			neg;

	neg = 0;
	glb->total += 1;
	if (glb && arg && orig)
	{
		c = va_arg(glb->ap, long long);
		if (c < 0)
			neg = 1;
		if (arg->info->precision > arg->info->fieldwidth)
			arg->info->fieldwidth = arg->info->precision;
		padded = ft_lltoa(ft_lltoo(c));
		if (arg->info->precision > 0)
			lnglng_oct_helper(arg, &*padded, c, 0);
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
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (0);
}

int		parse_unsigned(t_glb *glb, t_alst *arg, char *orig)
{
	unsigned		n;
	unsigned long	l;

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
	return (0);
}

static void	check_case(t_glb *glb, char **str)
{
	int j;

	j = 0;
	if (glb->upcase == 1)
	{
		glb->upcase = 0;
		while (str[0][j] != '\0')
		{
			if (ft_isalpha(str[0][j]))
				str[0][j] = str[0][j] - 32;
			j++;
		}		
	}
}

int		parse_hex(t_glb *glb, t_alst *arg, char *orig)
{
	long	c;
	char	*padded;
	char	*tmp;
	int		neg;

	neg = 0;
	glb->total += 1;
	if (glb && arg && orig)
	{
		c = va_arg(glb->ap, long);
		if (c < 0)
			neg = 1;
		if (arg->info->precision > arg->info->fieldwidth)
			arg->info->fieldwidth = arg->info->precision;
		padded = ft_ltoh(c);
		check_case(glb, &padded);
		if (arg->info->hash_flag == 1)
		{
			tmp = ft_strjoin("0x", padded);
			ft_strdel(&padded);
			padded = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		if (arg->info->precision > 0)
			long_hex_helper(arg, &*padded, c, 0);
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
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
		ft_strdel(&padded);
	}
	return (0);
}
