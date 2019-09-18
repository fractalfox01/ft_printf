/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:57:48 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/18 08:59:33 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		int_norm_helper_1(t_alst *arg, char *orig, int c)
{
	if (c == 0)
	{
		if (BLANK == 1)
		{
			ARG = ft_strjoin(orig, "");
			arg->next = new_list();
			NEXT_ID = (CUR_ID + 1);
			return (1);
		}
		if (FIELDWIDTH == 0)
		{
			ARG = ft_strjoin(orig, "0");
			arg->next = new_list();
			NEXT_ID = (CUR_ID + 1);
			return (1);
		}
	}
	return (0);
}

void	int_norm_helper_2(t_alst *arg, char *orig, char *padded)
{
	char *tmp;

	if (MINUS_FLAG == 1)
	{
		if (PLUS_FLAG == 1 && NEGATIVE == 0)
		{
			tmp = ft_strjoin("+", padded);
			ARG = ft_strjoin(orig, pad_right(arg, tmp));
			ft_strdel(&tmp);
		}
		else
			ARG = ft_strjoin(orig, pad_right(arg, padded));
	}
	else if (PLUS_FLAG == 1 && NEGATIVE == 0)
	{
		tmp = ft_strjoin("+", padded);
		ARG = ft_strjoin(orig, pad_left(arg, tmp, 1));
		ft_strdel(&tmp);
	}
	else
		ARG = ft_strjoin(orig, pad_left(arg, padded, 1));
}

int		parse_int_normal(t_glb *glb, t_alst *arg, char *orig)
{
	int		c;
	char	*padded;
	char	*tmp;

	T_COUNT += 1;
	c = va_arg(glb->ap, int);
	if (c < 0)
		NEGATIVE = 1;
	if (int_norm_helper_1(arg, orig, c))
		return (0);
	tmp = NULL;
	if (PRECISION > FIELDWIDTH)
		FIELDWIDTH = PRECISION;
	padded = ft_itoa(c);
	if (PRECISION > 0)
		padded = int_helper(arg, &*padded, c);
	if (BLANK_FLAG)
		padded = blank_helper(arg, &*padded);
	int_norm_helper_2(arg, orig, padded);
	arg->next = new_list();
	NEXT_ID = (CUR_ID + 1);
	return (0);
}
