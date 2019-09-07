/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:08:10 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/06 19:04:29 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

static void	ps_helper_1(t_alst *arg, char *orig)
{
	char *tmp;
	
	tmp = ft_strdup("(null)");
	if (arg->info->precision > 0 && arg->info->precision < 6)
		tmp[arg->info->precision] = '\0';
	arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 0));
	ft_strdel(&tmp);
	arg->next = new_list();
	arg->next->id = (arg->id + 1);
}

static void ps_helper_2(t_alst *arg, char *orig, char *buf_str)
{
	char *nul;
	char *tmp;

	nul = ft_strdup("(null)");
	if (arg->info->minus_flag == 1 && !(buf_str) && arg->info->blank == 0)
		arg->info->arg = ft_strjoin(orig, pad_right(arg, nul));
	else if (arg->info->blank == 0 && !(buf_str))
		arg->info->arg = ft_strjoin(orig, pad_left(arg, nul, 0));
	else if (arg->info->minus_flag == 1 && arg->info->blank == 1 && !(buf_str) && arg->info->precision > 0)
	{
		tmp = ft_strnew(arg->info->precision);
		tmp = ft_strncpy(tmp, (const char *)nul, (size_t)arg->info->precision);
		arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 0));
		ft_strdel(&tmp);
	}
	else
		arg->info->arg = ft_strjoin(orig, pad_left(arg, "", 0));
	arg->next = new_list();
	arg->next->id = (arg->id + 1);
	ft_strdel(&nul);
}

static void	ps_helper_3(t_alst *arg, char *orig, char *buf_str)
{
	size_t	buf_len;
	int		i;

	i = 0;
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

int		parse_string(t_glb *glb, t_alst *arg, char *orig)
{
	size_t		buf_len;
	char		*buf_str;
	char 		*tmp;
	int			i;

	i = 0;
	if (glb)
	{
		glb->total += 1;
		buf_str = va_arg(glb->ap, char *);
		if (!(buf_str) && arg->info->blank == 0 && arg->info->fieldwidth == 0)
			ps_helper_1(arg, orig);
		else if ((!(buf_str) || *buf_str == 0) || arg->info->blank == 1)
			ps_helper_2(arg, orig, buf_str);
		else
			ps_helper_3(arg, orig, buf_str);
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
		{
			glb->ncount += 1;
			write(1, "\0", 1);
		}
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

// static void	u_helper(t_glb *glb, t_alst *arg, char *orig)
// {
// 	unsigned	c;
// 	char		*padded;
// 	int			neg;
// 	char		*tmp;

// 	neg = 0;
// 	glb->total += 1;
// 	c = va_arg(glb->ap, long);
// 	if (c == 0)
// 	{
// 		arg->info->arg = ft_strjoin(orig, "");
// 		arg->next = new_list();
// 		arg->next->id = (arg->id + 1);
// 	}
// 	if (arg->info->precision > arg->info->fieldwidth)
// 		arg->info->fieldwidth = arg->info->precision;
// 	padded = ft_ltoa(c);
// 	if (arg->info->precision > 0)
// 		padded = long_helper(arg, &*padded, c);
// 	if (arg->info->minus_flag == 1)
// 	{
// 		if (arg->info->plus_flag == 1 && neg == 0)
// 		{
// 			tmp = ft_strjoin("+", padded);
// 			arg->info->arg = ft_strjoin(orig, pad_right(arg, tmp));
// 			ft_strdel(&tmp);
// 		}
// 		else
// 			arg->info->arg = ft_strjoin(orig, pad_right(arg, padded));
// 	}
// 	else if (arg->info->plus_flag == 1 && neg == 0)
// 	{
// 		tmp = ft_strjoin("+", padded);
// 		arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 0));
// 		ft_strdel(&tmp);
// 	}
// 	else
// 		arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 0));
// 	arg->next = new_list();
// 	arg->next->id = arg->id + 1;
// }

// static void	ulong_helper(t_glb *glb, t_alst *arg, char *orig)
// {
// 	unsigned long	c;
// 	char			*padded;
// 	int				neg;
// 	char			*tmp;

// 	neg = 0;
// 	glb->total += 1;
// 	c = va_arg(glb->ap, unsigned long);
// 	if (c == 0)
// 	{
// 		arg->info->arg = ft_strjoin(orig, "");
// 		arg->next = new_list();
// 		arg->next->id = (arg->id + 1);
// 	}
// 	if (arg->info->precision > arg->info->fieldwidth)
// 		arg->info->fieldwidth = arg->info->precision;
// 	padded = ft_ltoa(c);
// 	if (arg->info->precision > 0)
// 		padded = long_helper(arg, &*padded, c);
// 	if (arg->info->minus_flag == 1)
// 	{
// 		if (arg->info->plus_flag == 1 && neg == 0)
// 		{
// 			tmp = ft_strjoin("+", padded);
// 			arg->info->arg = ft_strjoin(orig, pad_right(arg, tmp));
// 			ft_strdel(&tmp);
// 		}
// 		else
// 			arg->info->arg = ft_strjoin(orig, pad_right(arg, padded));
// 	}
// 	else if (arg->info->plus_flag == 1 && neg == 0)
// 	{
// 		tmp = ft_strjoin("+", padded);
// 		arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 0));
// 		ft_strdel(&tmp);
// 	}
// 	else
// 		arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 0));
// 	arg->next = new_list();
// 	arg->next->id = arg->id + 1;
// }

int		parse_unsigned(t_glb *glb, t_alst *arg, char *orig)
{
	unsigned long long	c;
	char				*padded;
	int					neg;
	char				*tmp;

	if (glb && arg && orig)
	{
		glb->total += 1;
		c = va_arg(glb->ap, unsigned long long);
		if (c == 0)
		{
			arg->info->arg = ft_strjoin(orig, "");
			arg->next = new_list();
			arg->next->id = (arg->id + 1);
		}
		if (arg->info->precision > arg->info->fieldwidth)
			arg->info->fieldwidth = arg->info->precision;
		else if (arg->info->lenmod[0] == 'l' || arg->info->lenmod[0] == 'z')
		{
			if (arg->info->lenmod[1] == 'l' || arg->info->lenmod[0] == 'z')
				padded = ft_ulltoa(c);
			else
				padded = ft_ultoa((unsigned long)c);
		}
		else if (arg->info->lenmod[0] == 'h')
		{
			if (arg->info->lenmod[1] == 'h')
				padded = ft_uctoa((unsigned char)c);
			else
				padded = ft_ustoa((unsigned short)c);
		}
		else
			padded = ft_uitoa((unsigned int)c);
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
			arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 0));
			ft_strdel(&tmp);
		}
		else
			arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 0));
		arg->next = new_list();
		arg->next->id = arg->id + 1;
	}
	return (0);
}

static void	check_case(t_glb *glb, char **str)
{
	int j;

	j = 0;
	if (glb->upcase == 1)
	{
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
	long long	c;
	char	*padded;
	char	*tmp;
	int		neg;

	neg = 0;
	glb->total += 1;
	if (glb && arg && orig)
	{
		c = va_arg(glb->ap, long long);
		if (c < 0)
			neg = 1;
		if (arg->info->lenmod[0] == 'h')
		{
			if (arg->info->lenmod[1] == 'h')
				padded = ft_ctoh((char)c);
			else
				padded = ft_itoh((unsigned short)c);
		}
		else if (arg->info->lenmod[0] == 'l')
		{
			if (arg->info->lenmod[1] == 'l')
				padded = ft_lltoh(c);
			else
				padded = ft_ltoh((long)c);
		}
		else
			padded = ft_itoh((long)c);
		check_case(glb, &padded);
		if (arg->info->hash_flag == 1 && arg->info->zero_flag == 0)
		{
			if (c != 0)
			{
				tmp = ft_strjoin("0x", padded);
				ft_strdel(&padded);
				padded = ft_strdup(tmp);
				ft_strdel(&tmp);
			}
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
			arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 1));
			ft_strdel(&tmp);
		}
		else if (arg->info->blank)
			arg->info->arg = ft_strjoin(orig, "\0");
		else
			arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 1));
		if (arg->info->hash_flag == 1 && c > 0)
		{
			if (glb->upcase == 1)
			{
				glb->upcase = 0;
				arg->info->arg[1] = 'X';
			}
			else
				arg->info->arg[1] = 'x';
		}
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
		ft_strdel(&padded);
	}
	return (0);
}
