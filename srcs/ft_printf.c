/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/09 12:37:03 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		add_remainder(t_glb *glb, char *lo)
{
	t_alst	*atmp;
	int		i;
	int		j;

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

void		form_formatted(t_glb *glb)
{
	t_alst	*tmp;
	char	*fmt;

	tmp = glb->args;
	fmt = glb->fmt;
	if (tmp)
	{
		while (tmp->id < glb->total)
		{
			glb->ncount += ft_strlen(OUTPUT);
			ft_putstr(OUTPUT);
			tmp = tmp->next;
		}
	}
	else
	{
		if (glb->err_type == 1)
			ft_printf("");
	}
}

int			ft_printf(char *fmt, ...)
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
		return (glb.ncount);
	}
	return (0);
}
