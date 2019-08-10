/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:03:33 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/10 13:56:50 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		parse_flags(t_arg_lst *arglst, char *fmt)
{
	int	ret;

	ret = 0;
	if (*fmt == ' ' || *fmt == '#' || *fmt == '-' || *fmt == '+')
	{
		// glb flag = *fmt;
		arglst->info->flag = *fmt;
		return (1);
	}
	else
		arglst->info->flag = '\0';
	return (0);
}

int		parse_fieldwidth(t_arg_lst *arglst, char *fmt)
{
	int ret;

	ret = 0;
	if (ft_isdigit(*fmt))
	{
		// glb fieldwidth = ft_atoi(fmt);
		arglst->info->fieldwidth = ft_atoi(fmt);
		while (ft_isdigit(*fmt) && *fmt != '\0')
		{
			fmt++;
			ret++;
		}
		return (ret);
	}
	else
		arglst->info->fieldwidth = 0;
	return (0);
}

int		parse_precision(t_arg_lst *arglst, char *fmt)
{
	int	ret;

	ret = 0;
	if (*fmt == '.')
	{
		fmt++;
		ret++;
		// glb precision = ft_atoi(fmt);
		arglst->info->precision = ft_atoi(fmt);
		while (ft_isdigit(*fmt))
		{
			ret++;
			fmt++;
		}
	}
	else
		arglst->info->precision = 0;
	return (ret);
}

int		parse_lengthmod(t_arg_lst *arglst, char *fmt)
{
	int	ret;

	ret = 0;
	// checks for ll hh l h
	if (*fmt == 'l' || *fmt == 'h' || *fmt == 'L')
	{
		ret++;
		if (*fmt == 'l')
		{
			fmt++;
			arglst->info->lenmod[0] = 'l';
			if (*fmt == 'l')
			{// glb lengthmod = long long;
				arglst->info->lenmod[1] = 'l';
				ret++;
			}
		}
		else if (*fmt == 'h')
		{
			fmt++;
			arglst->info->lenmod[0] = 'h';
			if (*fmt == 'h')
			{// glb lengthmod = signed char / unsigned char
				arglst->info->lenmod[1] = 'h';
				ret++;
			}
		}
		else
		{// long double
			arglst->info->lenmod[0] = 'L';
		}
		return (ret);
	}
	else
		arglst->info->lenmod[0] = '\0';
	return (0);
}

int		parse_conversion_spec(t_glb *glb, t_arg_lst *arglst, char *fmt)
{
	// data for new formatted strings are assigned here
	// and allocated.
	int ret;

	ret = 1;
	ret += parse_flags(arglst, fmt);
	ret += parse_fieldwidth(arglst, fmt);
	ret += parse_lengthmod(arglst, fmt);
	ret += parse_conversion(glb, fmt);
	return (ret);
}
