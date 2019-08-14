/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/13 22:57:45 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*get_sub_str(char *str, int	start, int end)
{
	char	*tmp;
	int		i;

	if (str)
	{
		tmp = (char *)malloc(sizeof(char) * (end - start));
		i = 0;
		while (start < end && str[start] != '\0')
		{
			tmp[i++] = str[start++];
		}
		return (tmp);
	}
	return (NULL);
}

void		save_args(t_glb *glb)
{
	int		i;
	int		x;
	int		y;
	char	*tmp;
	char	*arg;
	char	*fmt;

	i = 0;
	x = 0;
	y = 0;
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
			tmp = get_sub_str(glb->fmt, y, x);
			fmt += 1;
			if ((i = parse_conversion_spec(glb, fmt, tmp)) > 0)
				fmt += i;
			y = x + 1 + i;
			i = 0;
		}
		x++;
		fmt++;
	}
	ft_strdel(&arg);
}

void		form_formatted(t_glb *glb)
{
	t_arg_lst	*tmp;
	char		*fmt;
	int			i;

	tmp = glb->args;
	fmt = glb->fmt;
	i = 0;
	if (tmp)
	{
		// while (tmp)
		// {
		// 	while ()
		// }
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
		//form_formatted(&glb);
		return (glb.total);
	}
	return (0);
}