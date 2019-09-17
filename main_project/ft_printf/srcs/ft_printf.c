/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/16 18:46:19 by tvandivi         ###   ########.fr       */
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

static void	free_all(t_glb *glb, t_alst *arg)
{
	t_alst	*tmp;
	t_info *inf;
	int		i;

	i = 0;
	tmp = arg;
	while (tmp)
	{
		inf = tmp->info;
		if (!(inf))
			break ;
		tmp->id = 0;
		if (tmp->info->arg)
			ft_strdel(&tmp->info->arg);
		if (!(!(tmp->info->str)))
			ft_strdel(&tmp->info->str);
		if (!(!(tmp->info->tmp1)))
			ft_strdel(&tmp->info->tmp1);
		if (!(!(tmp->info->tmp2)))
			ft_strdel(&tmp->info->tmp2);
		if (!(!(tmp->info->padded)))
			ft_strdel(&tmp->info->padded);
		free((void *)tmp);
		tmp = tmp->next;
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
		free_all(&glb, glb.args);
		free((void *)glb.fmt);
		// system("leaks ft_printf");
		return (glb.ncount);
	}
	return (0);
}
