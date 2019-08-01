/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:08:51 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/29 16:09:33 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

size_t	handle_binary(char *fmt, va_list *args)
{
	if (fmt && args)
	{
		return (1);
	}
	return (0);
}

size_t	handle_float(char *fmt, va_list *args)
{
	if (fmt && args)
	{
		return (1);
	}
	return (0);
}

size_t	handle_uint(char *fmt, va_list *args)
{
	if (fmt && args)
	{
		return (1);
	}
	return (0);
}
