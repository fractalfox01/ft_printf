/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:49:19 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/12 12:05:29 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** function here are all called from parse_oct function; Contained in parse_1.c
*/

void    octal_assign_1(t_alst *arg, char *padded, char *orig, int neg)
{
	char *tmp;
	
	if (arg->info->plus_flag == 1 && neg == 0)
	{
		tmp = ft_strjoin("+", padded);
		arg->info->arg = ft_strjoin(orig, pad_right(arg, tmp));
		ft_strdel(&tmp);
	}
	else
		arg->info->arg = ft_strjoin(orig, pad_right(arg, padded));
}

void    octal_assign_2(t_alst *arg, char *padded, char *orig)
{
	char	*tmp;

	tmp = ft_strjoin("+", padded);
	arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 0));
	ft_strdel(&tmp);
}

void    lnglng_oct_helper(t_alst *arg, long long c, int len)
{
	int		zero;
	char	*xtmp;
	char	*stmp;

	len = ft_strlen(arg->info->padded);
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
			xtmp[0] = '-';
		if (arg->info->hash_flag == 1)
			stmp = ft_strjoin(xtmp, ft_strjoin( "0" , ft_lltoa(ft_lltoo(ft_abs(c)))));
		else
			stmp = ft_strjoin(xtmp, ft_lltoa(ft_lltoo(ft_abs(c))));
		ft_strdel(&(arg->info->padded));
		arg->info->padded = ft_strdup(stmp);
		ft_strdel(&xtmp);
		ft_strdel(&stmp);
	}
}

/*
** helper function for parse_hex function; Contained in parser_1.c
*/

void	hex_helper_1(t_alst *arg)
{
	char	*tmp;

	tmp = ft_strjoin("0x", arg->info->padded);
	ft_strdel(&(arg->info->padded));
	arg->info->padded = ft_strdup(tmp);
	ft_strdel(&tmp);
}

char *blank_helper(t_alst *arg, char *padded)
{
	char	*tmp;

	tmp = ft_strjoin(" ", padded);
	ft_strdel(&padded);
	return (tmp);
}
