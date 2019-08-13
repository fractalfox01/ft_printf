/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/12 21:16:47 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		save_args(t_glb *glb)
{
	int		i;
	char	*arg;
	char	*fmt;

	i = 0;
	fmt = glb->fmt;
	arg = ft_strdup("scdiouxXfp");
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			/*
			** parse_conversion_spec returns number of characters to be skipped
			** and saves flags, fieldwidth, precision, and length modifier.
			*/
			fmt += 1;
			if ((i = parse_conversion_spec(glb, fmt)) > 0)
				fmt += i;
			i = 0;
		}
		fmt++;
	}
	ft_strdel(&arg);
}

void		form_formatted(t_glb *glb)
{
	if (glb)
	{
		
	}
}

int			has_args(char *fmt)
{
	while (*fmt != '\0')
	{
		if (*fmt == '%')
			return (1);
		fmt++;
	}
	return (0);
}

size_t		ft_printf(char *fmt, ...)
{
	t_glb	glb;

	glb_init(&glb);
	va_start(glb.ap, fmt);
	if (has_args(fmt) == 0)
	{
		ft_putstr(fmt);
		return (ft_strlen(fmt));
	}
	else
	{
		glb.fmt = ft_strdup(fmt);
		save_args(&glb);
		form_formatted(&glb);
		return (glb.total);
	}
	return (0);
}