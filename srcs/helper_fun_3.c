/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:07:00 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/11 12:39:14 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** hex helper functions; parse_hex function contained in parse_1.c
*/

void    long_hex_helper(t_alst *arg, long c, int len)
{
	int		zero;
	char	*xtmp;
	char	*stmp;

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
		stmp = ft_strjoin(xtmp, arg->info->padded);
		ft_strdel(&arg->info->padded);
		arg->info->padded = ft_strdup(stmp);
		ft_strdel(&xtmp);
		ft_strdel(&stmp);
	}
}

char    *assign_x_buf(t_glb *glb, t_alst *arg, long long c)
{
	char *padded;

	padded = NULL;
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
	return (padded);
}

void	check_case(t_glb *glb, char **str)
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

void    hex_flag_find(t_alst *arg, int neg, char *orig)
{
	char	*tmp;

	if (arg->info->minus_flag == 1)
	{
		if (arg->info->plus_flag == 1 && neg == 0)
		{
			tmp = ft_strjoin("+", arg->info->padded);
			arg->info->arg = ft_strjoin(orig, pad_right(arg, tmp));
			ft_strdel(&tmp);
		}
		else
			arg->info->arg = ft_strjoin(orig, pad_right(arg, arg->info->padded));
	}
	else if (arg->info->plus_flag == 1 && neg == 0)
	{
		tmp = ft_strjoin("+", arg->info->padded);
		arg->info->arg = ft_strjoin(orig, pad_left(arg, tmp, 1));
		ft_strdel(&tmp);
	}
	else if (arg->info->blank)
		arg->info->arg = ft_strjoin(orig, "\0");
	else
		arg->info->arg = ft_strjoin(orig, pad_left(arg, arg->info->padded, 1));
}

void    hex_helper_2(t_glb *glb, t_alst *arg)
{
	if (glb->upcase == 1)
		arg->info->arg[1] = 'X';
	else
		arg->info->arg[1] = 'x';
}
