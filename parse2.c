/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:12:39 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/29 16:18:38 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

size_t	handle_ptr(char *fmt, va_list *args)
{
	if (fmt && args)
	{
		return (1);
	}
	return (0);
}

size_t  handle_oct(char *fmt, va_list *args)
{
	if (fmt && args)
	{
		return (1);
	}
	return (0);
}

size_t	handle_unsigned(char *fmt, va_list *args)
{
	if (fmt && args)
	{
		return (1);
	}
	return (0);
}

size_t	handle_hex(char *fmt, va_list *args)
{
	if (fmt && args)
	{
		return (1);
	}
	return (0);
}

size_t	handle_char(char *fmt, va_list *args)
{
	if (fmt && args)
	{
		return (1);
	}
	return (0);
}