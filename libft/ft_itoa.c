/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:38:18 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/25 14:44:38 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*tmp;
	char	*ret;
	long	i;
	long	nbr;
	
	tmp = ft_strnew(12);
	i = 0;
	nbr = (long)n;
	if (nbr < 0)
		nbr *= -1;
	while (nbr / 10 > 0)
	{
		tmp[i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	tmp[i++] = nbr + 48;
	if (n < 0)
		tmp[i++] = '-';
	tmp[i] = '\0';
	ret = ft_strrev(tmp);
	ft_strdel(&tmp);
	return (ret);
}
