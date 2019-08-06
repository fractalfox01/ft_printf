/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:12:39 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/04 18:58:09 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

size_t	handle_ptr(t_glb *glb, char *fmt)
{
	if (fmt && glb)
	{
		return (1);
	}
	return (0);
}

size_t  handle_oct(t_glb *glb, char *fmt)
{
	char	*tmp;
	char	*octs;
	int		n;
	int		oct;

	n = 0;
	oct = 0;
	if(*fmt)
	{
		n = va_arg(glb->ap, int);
		oct = ft_dec_to_oct(n);
		octs = ft_itoa(oct);
		tmp = ft_strdup(glb->ret);
		free((void *)glb->ret);
		glb->ret = ft_strjoin(tmp, octs);
		free((void *)octs);
		free((void *)tmp);
		return (1);
	}
	return (0);
}

size_t	handle_unsigned(t_glb *glb, char *fmt)
{
	if (fmt && glb)
	{
		return (1);
	}
	return (0);
}

size_t	handle_hex(t_glb *glb, char *fmt)
{
	if (fmt && glb)
	{
		return (1);
	}
	return (0);
}

size_t	handle_char(t_glb *glb, char *fmt)
{
	if (fmt && glb)
	{
		return (1);
	}
	return (0);
}