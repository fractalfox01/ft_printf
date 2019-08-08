/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:03:33 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/08 14:14:05 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		parse_flags(t_glb *glb, char *fmt)
{
	int	ret;

	ret = 0;
	if (*fmt == ' ' || *fmt == '#' || *fmt == '-' || *fmt == '+')
	{
		// glb flag = *fmt;
		return (1);
	}
	return (0);
}

int		parse_fieldwidth(t_glb *glb, char *fmt)
{
	int ret;

	ret = 0;
	if (ft_isdigit(*fmt))
	{
		// glb fieldwidth = ft_atoi(fmt);
		while (ft_isdigit(*fmt) && *fmt != '\0')
		{
			fmt++;
			ret++;
		}
		return (ret);
	}
	return (0);
}

int		parse_precision(t_glb *glb, char *fmt)
{
	int	ret;

	ret = 0;
	if (*fmt == '.')
	{
		fmt++;
		ret++;
		// glb precision = ft_atoi(fmt);
		while (ft_isdigit(*fmt))
		{
			ret++;
			fmt++;
		}
	}
	return (ret);
}

int		parse_lengthmod(t_glb *glb, char *fmt)
{
	// checks for ll hh l h
	return (0);
}

int		parse_conversion_spec(t_glb *glb, char *fmt)
{
	// data for new formatted strings are assigned here
	// and allocated.
	int ret;

	ret = 0;
	ret += parse_flags(glb, fmt);
	ret += parse_fieldwidth(glb, fmt);
	ret += parse_lengthmod(glb, fmt);
	ret += parse_conversion(glb, fmt);
	return (ret);
}
