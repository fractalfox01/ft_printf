/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:38:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/11 14:28:49 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** ps_ functions are called from parse_string; Contained in parse_1.c
*/

void	ps_helper_1(t_alst *arg, char *orig)
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

void    ps_helper_2(t_alst *arg, char *orig, char *buf_str)
{
	char *nul;
	char *tmp;

	nul = ft_strdup("(null)");
	if (arg->info->minus_flag == 1 && !(buf_str) && arg->info->blank == 0)
		arg->info->arg = ft_strjoin(orig, pad_right(arg, nul));
	else if (arg->info->blank == 0 && !(buf_str))
		arg->info->arg = ft_strjoin(orig, pad_left(arg, nul, 0));
	else if (arg->info->minus_flag == 1 && arg->info->blank == 1 && !(buf_str) \
		&& arg->info->precision > 0)
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

void	ps_helper_3(t_alst *arg, char *orig, char *buf_str)
{
	size_t	buf_len;
	int		i;

	i = 0;
	buf_len = (size_t)arg->info->fieldwidth + ft_strlen(buf_str);
	if (arg->info->plus_flag == 1 || arg->info->hash_flag == 1 || \
		arg->info->blank_flag == 1)
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

char	*assign_u_buf(t_alst *arg, unsigned long long c)
{
	char *padded;

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
	return (padded);
}

void	assign_u_arg(t_alst *arg, char *padded, int neg, char *orig)
{
	char *tmp;
	
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
}
