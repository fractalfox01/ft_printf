/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 10:58:09 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/02 10:58:37 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_isnotpadding(char c)
{
	if (c == '-' || c == '+' || c == ' ' || ft_isdigit(c) || c == '#')
		return (0);
	return (1);
}

void	flag_catcher(t_glb *glb, char *fmt)
{
	fmt++;
	while (ft_isnotpadding(*fmt) == 0)
	{
		if (*fmt == ' ')
			glb->info.hash_pad = 1;
		if (*fmt == '-')
			glb->info.minus_sign = 1;
		if (*fmt == '+')
			glb->info.plus_sign = 1;
		if (*fmt == '#')
			glb->info.hash_pad = 1;
		if (ft_isdigit(*fmt))
			glb->info.zero_pad = 1;
		fmt++;
	}
}