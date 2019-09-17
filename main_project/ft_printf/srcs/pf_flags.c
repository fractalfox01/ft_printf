/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:03:33 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/13 20:01:45 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// the four flag checks need to be broken up into seperate static functions







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
		fmt += ret;
		ret = 0;
	}
	ret = parse_fieldwidth(get_arg(glb), fmt);
	if (ret > track)
	{
		tot += ret;
		fmt += ret;
		ret = 0;
	}
	ret = parse_precision(get_arg(glb), fmt);
	if (ret > track)
	{
		tot += ret;
		fmt += ret;
		ret = 0;
	}
	ret = parse_lengthmod(get_arg(glb), fmt);
	if (ret > track)
	{
		tot += ret;
		fmt += ret;
		ret = 0;
	}
	tot += parse_conversion(glb, fmt, orig);
	return (tot);
}
