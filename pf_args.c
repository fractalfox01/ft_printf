/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:10:40 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/24 15:30:17 by tvandivi         ###   ########.fr       */
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
		if ((size_t)len > i)
			return (str);
		x = i - len;
		while (x < (int)i && str[y] != '\0')
			stmp[x++] = str[y++];
		return (stmp);
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
				stmp[x++] = str[y++];
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

void	int_helper(t_arg_lst *arg, char *padded, int c)
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

int		parse_int(t_glb *glb, t_arg_lst *arg, char *orig)
{
	int		ret;
	int		c;
	//int		len;
	int		zero;
	//char	*xtmp;
	//char	*stmp;
	size_t	buf_len;
	char	*padded;
	char	*tmp;

	ret = 0;
	zero = 0;
	buf_len = 0;
	if (glb && arg && orig)
	{
		if (arg->info->lenmod[0] == 'l')
		{
			parse_long(glb, arg, orig);
		}
		else
		{
			glb->total += 1;
			c = va_arg(glb->ap, int);
			if (arg->info->precision > arg->info->fieldwidth)
				arg->info->fieldwidth = arg->info->precision;
			buf_len = (size_t)arg->info->fieldwidth;
			padded = ft_itoa(c);
			if (arg->info->precision > 0)
			{
				int_helper(arg, &*padded, c);
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
	}
	return (ret);
}

int		parse_long(t_glb *glb, t_arg_lst *arg, char *orig)
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

static char	*find_va(char *ptr, unsigned long nbr, long len, int b)
{
	unsigned long	rem;
    unsigned long    a;
    int			     i;
    char    		*hex;
	unsigned long	testing;

	rem = 1;
    a = 0;
    i = 0;
    hex = ft_strdup("0123456789abcdef");
	while (len-- > 1)
	{
        a = ft_power(len, 16);
		testing = (nbr / a);
		if (testing <= 16)
			ptr[b++] = hex[(nbr / a)];
		nbr -= a * (nbr / a);
	}
	return (ptr);
}

char		*fp_pointer(unsigned long n)
{
	unsigned long	nbr;
	char			*ptr;
	long			len;
	int				b;
	unsigned long	tmp;

	len = 1;
	b = 0;
	nbr = n;
	tmp = nbr;
	while (tmp >= 10)
		tmp = (nbr / ft_power(len++, 16));
	ptr = ft_strnew(len + 1);
	if (!ptr)
		return (NULL);
	if (nbr == 0 && (ptr[b] = '0'))
		return (ptr);
	return (find_va(ptr, nbr, len, b));
}

int		parse_ptr(t_glb *glb, t_arg_lst *arg, char *orig)
{
	int				ret;
	unsigned long	n;
	char			*tmp;

	ret = 0;
	if (glb && arg && orig)
	{
		n = va_arg(glb->ap, unsigned long);
		tmp = ft_strjoin("0x", fp_pointer(n));
		arg->info->arg = ft_strjoin(orig, tmp);
		ft_strdel(&tmp);
		glb->total += 1;
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (ret);
}

int		parse_oct(t_glb *glb, t_arg_lst *arg, char *orig)
{
	int	ret;
	int n;

	ret = 0;
	n = 0;
	if (glb && arg && orig)
	{
		n = va_arg(glb->ap, int);
		arg->info->arg = ft_strjoin(orig, ft_itoo(n));
		glb->total += 1;
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (ret);
}

int		parse_unsigned(t_glb *glb, t_arg_lst *arg, char *orig)
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

char		*fp_ltoh(long n)
{
	char	*tmp;
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
		tmp[i] = hex[n];
	return (ft_strrev(tmp));
}

int		parse_hex(t_glb *glb, t_arg_lst *arg, char *orig)
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
			str = fp_ltoh(l);
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
	int		ret;
	double	n;
	int		b;

	ret = 0;
	n = 0;
	b = 0;
	if (glb && arg && orig)
	{
		n = va_arg(glb->ap, double);
		b = arg->info->precision;
		if (b == 0)
			b = 6;
		arg->info->arg = ft_strjoin(orig, ft_ftoa(n, b));
		glb->total += 1;
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
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
