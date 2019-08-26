/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/25 13:59:25 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*get_sub_str(char *str, int	start, int end)
{
	char	*tmp;
	int		i;

	if (str)
	{
		tmp = (char *)malloc(sizeof(char) * (end - start) + 1);
		i = 0;
		while (start < end && str[start] != '\0')
		{
			tmp[i++] = str[start++];
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}

int			check_next(char *fmt)
{
	while (*fmt != '\0')
	{
		if (*fmt == '%')
			return (1);
		fmt++;
	}
	return (0);
}

void		add_remainder(t_glb *glb, char *lo)
{
	t_alst	*atmp;
	int			i;
	int			j;

	atmp = glb->args;
	i = 0;
	j = 0;
	while (atmp->id < glb->total)
		atmp = atmp->next;
	glb->total += 1;
	atmp->info->arg = ft_strdup(lo);
	atmp->next = (t_alst *)malloc(sizeof(t_alst) * 1);
	atmp = atmp->next;
	atmp->id = glb->total;
}

/*
** parse_conversion_spec returns number of characters to be skipped
** and saves flags, fieldwidth, precision, and length modifier.
*/

void		save_args(t_glb *glb)
{
	int		i;
	int		x;
	int		y;
	char	*leftovers;
	char	*tmp;
	char	*arg;
	char	*fmt;

	i = 0;
	x = 0;
	y = 0;
	fmt = glb->fmt;
	arg = ft_strdup("scdiouxXfp");
	leftovers = NULL;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			tmp = get_sub_str(glb->fmt, y, x);
			fmt += 1;
			if ((i = parse_conversion_spec(glb, fmt, tmp)) > 0)
			{
				fmt += i;
				x += i + 1;
			}
			else
				x++;
			ft_strdel(&tmp);
			y = x + 1;
			i = 0;
			if (check_next(fmt + 1) == 0)
			{
				leftovers = ft_strdup(fmt + 1);
			}
		}
		x++;
		fmt++;
	}
	add_remainder(glb, leftovers);
	ft_strdel(&leftovers);
	ft_strdel(&arg);
}

void		form_formatted(t_glb *glb)
{
	t_alst	*tmp;
	char		*fmt;
	int			i;

	tmp = glb->args;
	fmt = glb->fmt;
	i = 0;
	if (tmp)
	{
		while (tmp->id < glb->total)
		{
			ft_putstr(tmp->info->arg);
			tmp = tmp->next;
		}
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
