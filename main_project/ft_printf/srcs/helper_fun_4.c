/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:01:10 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/14 19:01:42 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	set_h(char *fmt, t_alst *arg)
{
	fmt++;
	arg->info->lenmod[0] = 'h';
	if (*fmt == 'h')
	{
		arg->info->lenmod[1] = 'h';
		return (2);
	}
	return (1);
}

int	set_l(char *fmt, t_alst *arg)
{
	fmt++;
	arg->info->lenmod[0] = 'l';
	if (*fmt == 'l')
	{
		arg->info->lenmod[1] = 'l';
		return (2);
	}
	return (1);
}

int	set_z(char *fmt, t_alst *arg)
{
	arg->info->lenmod[0] = 'z';
	return (1);
}
