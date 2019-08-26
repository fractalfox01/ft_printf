/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:10:40 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/26 16:08:30 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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

int		parse_bin(t_glb *glb, t_alst *arg, char *orig)
{
	int	ret;

	ret = 0;
	if (glb && arg && orig)
	{
		ft_putstr("binary parse\n");
	}
	return (ret);
}

int		parse_float(t_glb *glb, t_alst *arg, char *orig)
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
	// grab option type and store in info->opt_type;
	ft_strdel(&fmt_str);
	if (i < 10)
		return (glb->argfun[i](glb, get_arg(glb), orig));
	return (0);
}
