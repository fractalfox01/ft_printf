/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:03:43 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/02 15:35:08 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pad_left(t_alst *tmp, char *str, int a)
{
	char	*stmp;
	int		len;
	int		y;
	int		x;
	size_t	i;

	i = 0;
	x = 0;
	y = 0;
	if (tmp && str)
	{
		len = ft_strlen(str);
		i = (size_t)tmp->info->fieldwidth;
		stmp = ft_strnew(i);
		if (tmp->info->zero_flag == 1 && a)
			ft_memset(stmp, '0', i);
		else
			ft_memset(stmp, ' ', i);
		if ((size_t)len > i)
			return (str);
		x = i - len;
		while (x < (int)i && str[y] != '\0')
			stmp[x++] = str[y++];
		return (stmp);
	}
	return (str);
}

char	*pad_right(t_alst *tmp, char *str)
{
	char	*stmp;
	int		len;
	int		y;
	int		x;
	size_t	i;

	i = 0;
	x = 0;
	y = 0;
	if (tmp && str)
	{
		len = ft_strlen(str);
		i = (size_t)tmp->info->fieldwidth;
		stmp = ft_strnew(i);
		ft_memset(stmp, ' ', i);
		if (tmp->info->minus_flag == 1)
		{
			if ((size_t)len > i)
				return (str);
			while (x <= (int)i && str[y] != '\0')
				stmp[x++] = str[y++];
			return (stmp);
		}
	}
	return (str);
}
