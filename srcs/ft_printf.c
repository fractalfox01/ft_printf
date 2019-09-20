/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/20 12:39:19 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		add_remainder(t_glb *glb, char *lo)
{
	t_alst	*arg;
	int		i;
	int		j;

	arg = glb->args;
	i = 0;
	j = 0;
	while (CUR_ID < T_COUNT)
		arg = arg->next;
	T_COUNT += 1;
	ARG = ft_strdup(lo);
	arg->next = (t_alst *)malloc(sizeof(t_alst) * 1);
	arg = arg->next;
	CUR_ID = T_COUNT;
}

void		form_formatted(t_glb *glb)
{
	t_alst	*tmp;
	char	*fmt;

	tmp = glb->args;
	fmt = glb->fmt;
	if (tmp)
	{
		while (tmp->id < T_COUNT)
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

static void	free_all(t_glb *glb)
{
	t_alst	*arg;
	t_info	*inf;
	int		i;

	i = 0;
	arg = glb->args;
	while (CUR_ID < T_COUNT)
	{
		inf = arg->info;
		if (!(inf))
			break ;
		if (ARG)
			ft_strdel(&ARG);
		if (STR)
			ft_strdel(&STR);
		if (TMP1)
			ft_strdel(&TMP1);
		if (TMP2)
			ft_strdel(&TMP2);
		if (PADDED)
			ft_strdel(&PADDED);
		free((void *)arg);
		arg = arg->next;
	}
	ft_strdel(&glb->fmt);
}

int			ft_printf(char *fmt, ...)
{
	t_glb	*glb;

	glb = glb_init(glb);
	va_start(glb->ap, fmt);
	if (has_args(fmt) == 0)
	{
		ft_putstr(fmt);
		return (ft_strlen(fmt));
	}
	else
	{
		glb->fmt = ft_strdup(fmt);
		save_args(glb);
		form_formatted(glb);
		free_all(glb);
		return (glb->ncount);
	}
	return (0);
}
