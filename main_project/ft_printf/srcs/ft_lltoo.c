/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:56:05 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/13 12:35:40 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_lltoo(long long nbr)
{
	long long	oct;
	char		*str;
	char		*ret;
	int			i;

	i = 0;
	oct = 0;
	str = ft_strnew(30);
	ft_bzero(str, 30);
	while (nbr / 8 > 0)
	{
		if (nbr % 8 > 0)
			str[i] = (nbr % 8) + 48;
		else
			str[i] = '0';
		nbr /= 8;
		i++;
	}
	str[i] = (nbr + 48);
	ret = ft_strrev(str);
	oct = ft_atoll(ret);
	free((void *)str);
	return (oct);
}
