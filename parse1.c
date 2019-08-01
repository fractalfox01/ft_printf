/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:11:04 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/31 20:11:35 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

size_t	handle_escape(char *fmt, va_list *args)
{
	int	i;

	i = 0;
	if (fmt && args)
	{
		if (*fmt == ' ')
		{}
	}
	return (0);
}

size_t	handle_str(char *fmt, va_list *args)
{
	if (fmt && args)
	{
		return (1);
	}
	return (0);
}

size_t	handle_wstr(char *fmt, va_list *args)
{
	if (fmt && args)
	{
		return (1);
	}
	return (0);
}

size_t	handle_int(char *fmt, va_list *args)
{
	if (fmt && args)
	{
		return (1);
	}
	return (0);
}

size_t	handle_long(char *fmt, va_list *args)
{
	if (fmt && args)
	{
		return (1);
	}
	return (0);
}
