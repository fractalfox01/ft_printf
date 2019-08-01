/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:08:51 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/01 12:46:25 by tvandivi         ###   ########.fr       */
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

char	*parse_padding(t_glb *glb, char *fmt)
{
	char	*tmp;
	char	*zero;
	int		max;
	int		i;

	max = 0;
	i = 0;
	if (*fmt == '%' && glb && *(fmt + 1) != '\0')
	{
		fmt++;
		if (ft_isdigit(*fmt))
		{
			max = ft_atoi(fmt);
			tmp = ft_strdup(glb->ret);
			zero = ft_strnew(max);
			ft_memset((void *)zero, ' ', max);
			free((void *)glb->ret);
			free((void *)tmp);
			glb->ret = ft_strjoin(tmp, zero);
		}
		if (*fmt == '%')
		{
			tmp = ft_strdup(glb->ret);
			free((void *)glb->ret);
			glb->ret = ft_strjoin(tmp, "%");
			free((void *)tmp);
		}
		if (*fmt == '+')
		{}
		if (*fmt == '-')
	}
	return (fmt);
}