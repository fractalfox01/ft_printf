/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/08 18:36:32 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	init_argfun(t_glb *glb)
{
	t_argfun fun;

	glb->funs = &fun;
	fun.argfun[0] = parse_string;
	fun.argfun[1] = parse_char;
	fun.argfun[2] = parse_int;
}

t_arg_lst	*new_list(void)
{
	t_arg_lst	*list;
	t_info		info;

	list = (t_arg_lst *)malloc(sizeof(t_arg_lst) * 1);
	list->id = 0;
	list->info = &info;
	list->next = NULL;
	return (list);
}

void	save_args(t_glb *glb)
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
			// parse_conversion_spec returns number of characters to be skipped
			// and saves flags, fieldwidth, precision, and length modifier.
			if ((i = parse_conversion_spec(glb, fmt)) > 0)
				fmt += i;
			i = 0;
			while (arg[i] != '\0')
			{
				if (arg[i] == *fmt)
				{
					// pre-allocated space already ready; argument is converted here using data already obtained.
					// need dispatch table :(
					// ex. argfun[i](glb)
				}
			}
		}
		fmt++;
	}
	ft_strdel(&arg);
}

size_t		ft_printf(char *fmt, ...)
{
	static t_glb	glb;

	glb_init(&glb);
	va_start(glb.ap, fmt);
	if (has_args(fmt) == 0)
	{
		ft_putstr(fmt);
		return (ft_strlen(fmt));
	}
	else
	{
		save_args(&glb);
		return (glb.total);
	}
	return (0);
}