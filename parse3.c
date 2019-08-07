/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:08:51 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/06 17:53:54 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

size_t	handle_binary(t_glb *glb, char *fmt)
{
	if (fmt && glb)
	{
		return (1);
	}
	return (0);
}

size_t	handle_float(t_glb *glb, char *fmt)
{
	if (fmt && glb)
	{
		return (1);
	}
	return (0);
}

size_t	handle_uint(t_glb *glb, char *fmt)
{
	if (fmt && glb)
	{
		return (1);
	}
	return (0);
}

/*
** A - overrides a 0 if both are given.
** A + overrides a space if both are used.
*/

int pf_isflag(char c)
{
	if (c == '-' || c == '+' || c == '.' || c == '#')
		return (1);
	return (0);
}

char	*parse_padding(t_glb *glb, char *fmt)
{
	char	*tmp;
	char	*zero;
	int		max;
	int		i;
	int		j;
	int		a;

	a = 0;
	max = 0;
	i = 0;
	j = 0;
	tmp = NULL;
	zero = NULL;
	flag_catcher(glb, fmt);
	if (*fmt == '%')
			fmt++;
	if (glb->info.hash_pad)
		glb->info.hash_pad = 0;
	if (glb->info.minus_sign)
	{
		glb->info.minus_sign = 1;
		//glb->info.zero_pad = 0;
	}
	if (glb->info.plus_sign)
	{
		glb->info.plus_sign = 0;
		glb->info.space = 0;
	}
	if (glb->info.space)
		glb->info.space = 0;
	if (glb->info.zero_pad)
	{
		while (pf_isflag(*fmt))
			fmt++;
		max = ft_atoi(fmt);
		while (ft_isdigit(*fmt))
			fmt++;
		parser(glb, fmt);
		tmp = ft_strdup(glb->ret);
		if ((int)ft_strlen(glb->arg) >= max)
		{
			free((void *)glb->ret);
			glb->ret = ft_strjoin(tmp, glb->arg);
			ft_strdel(&tmp);
		}
		else
		{
			zero = ft_strnew(max + 1);
			ft_memset((void *)zero, ' ', max);
			ft_strdel(&glb->ret);
			i = max - ft_strlen(glb->arg);
			a = ft_strlen(glb->arg) ;
			if (glb->info.minus_sign)
			{
				glb->info.minus_sign = 0;
				i = 0;
				while (i < max && glb->arg[j] != '\0')
					zero[i++] = glb->arg[j++];
				glb->ret = ft_strjoin(tmp, zero);
				ft_strdel(&tmp);
				ft_strdel(&zero);
			}
			else
			{
				while (i < max && glb->arg[j] != '\0')
					zero[i++] = glb->arg[j++];
				glb->ret = ft_strjoin(tmp, zero);
				ft_strdel(&tmp);
				ft_strdel(&zero);
			}
			glb->info.zero_pad = 0;
		}
	}
	return (fmt);
}