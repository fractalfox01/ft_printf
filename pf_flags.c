/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:03:33 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/16 16:32:32 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

/*
**	TODO:
**	
**	Create get_arg function to return the info link to the next list in line.
**  using glb->total to obtain appropriate list id
**
*/

t_arg_lst	*get_arg(t_glb *glb)
{
	t_arg_lst *arg;

	arg = glb->args;
	while (arg->id < (glb->total))
	{
		arg = arg->next;
	}
	return (arg);
}

int		parse_flags(t_arg_lst *arglst, char *fmt)
{
	int	ret;

	ret = 0;
	arglst->info->flag = 0;
	while (*fmt == ' ' || *fmt == '#' || *fmt == '-' || *fmt == '+')
	{
		arglst->info->flag += 1;
		fmt++;
	}
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

/*
**	checks for ll hh l h
*/

int		parse_lengthmod(t_arg_lst *arglst, char *fmt)
{
	int	ret;

	ret = 0;
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

/*
**	data for new formatted strings are assigned here
**	and allocated.
*/

int		parse_conversion_spec(t_glb *glb, char *fmt, char *orig)
{
	int ret;
	int	track;
	int	tot;

	tot = 0;
	ret = 0;
	track = 0;
	ret = parse_flags(get_arg(glb), fmt);
	if (ret > track)
	{
		tot += ret;
		track = ret;
		fmt += ret;
		ret = 0;
	}
	ret = parse_fieldwidth(get_arg(glb), fmt);
	if (ret > track)
	{
		tot += ret;
		track = ret;
		fmt += ret;
		ret = 0;
	}
	ret = parse_lengthmod(get_arg(glb), fmt);
	if (ret > track)
	{
		tot += ret;
		track = ret;
		fmt += ret;
		ret = 0;
	}
	parse_conversion(glb, fmt, orig);
	return (tot);
}
