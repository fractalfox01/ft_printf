/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:13:22 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/14 20:01:43 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** TODO:
**
** Create get_arg function to return the info link to the next list in line.
** using glb->total to obtain appropriate list id
*/

int		parse_flags(t_alst *arglst, char *fmt)
{
	int	ret;

	ret = 0;
	arglst->info->blank_flag = 0;
	arglst->info->hash_flag = 0;
	arglst->info->minus_flag = 0;
	arglst->info->plus_flag = 0;
	while (*fmt == ' ' || *fmt == '#' || *fmt == '-' || *fmt == '+')
	{
		if (*fmt == ' ')
			arglst->info->blank_flag = 1;
		if (*fmt == '#')
			arglst->info->hash_flag = 1;
		if (*fmt == '-')
			arglst->info->minus_flag = 1;
		if (*fmt == '+')
			arglst->info->plus_flag = 1;
		while (*fmt == ' ' || *fmt == '#' || *fmt == '-' || *fmt == '+')
		{
			fmt++;
			ret++;
		}
	}
	return (ret);
}

int		parse_fieldwidth(t_alst *arglst, char *fmt)
{
	int ret;

	ret = 0;
	if (ft_isdigit(*fmt))
	{
		if (fmt[0] == '0')
			arglst->info->zero_flag = 1;
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

void	pp_helpr(t_alst *arglst, char **fmt, int *ret)
{
	if (ft_isdigit(*fmt[0]))
	{
		if (*fmt[0] == '0')
			arglst->info->blank = 1;
		arglst->info->precision = ft_atoi(*fmt);
		while (ft_isdigit(*fmt[0]))
		{
			*ret += 1;
			(*fmt)++;
		}
	}
	else
	{
		arglst->info->precision = 0;
		arglst->info->blank = 1;
	}
}

int		parse_precision(t_alst *arglst, char *fmt)
{
	int	ret;

	ret = 0;
	if (*fmt == '.')
	{
		fmt++;
		ret++;
		pp_helpr(arglst, &fmt, &ret);
	}
	else
		arglst->info->precision = 0;
	return (ret);
}

/*
**	checks for ll hh l h
*/

int		parse_lengthmod(t_alst *arglst, char *fmt)
{
	int	ret;

	ret = 0;
	if (*fmt == 'l' || *fmt == 'h' || *fmt == 'L' || *fmt == 'z')
	{
			ret++;
		if (*fmt == 'z')
		{
			fmt++;
			arglst->info->lenmod[0] = 'z';
		}
		else if (*fmt == 'l')
		{
			fmt++;
			arglst->info->lenmod[0] = 'l';
			if (*fmt == 'l')
			{
				arglst->info->lenmod[1] = 'l';
				ret++;
			}
		}
		else if (*fmt == 'h')
		{
			fmt++;
			arglst->info->lenmod[0] = 'h';
			if (*fmt == 'h')
			{
				arglst->info->lenmod[1] = 'h';
				ret++;
			}
		}
		else
			arglst->info->lenmod[0] = 'L';
		return (ret);

	}
	else
		arglst->info->lenmod[0] = '\0';
	return (0);
}
