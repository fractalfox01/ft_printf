/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:11:30 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/21 21:57:01 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_value(char *ptr, int nbr, int len, int b)
{
	int 	rem;
    int     a;
    int     i;
    char    *hex;

	rem = 1;
    a = 0;
    i = 0;
    hex = ft_strdup("0123456789abcdef");
	while (len-- > 1)
	{
        a = ft_power(len, 16);
		ptr[b++] = hex[(nbr / a)];
		nbr -= a * (nbr / a);
	}
	return (ptr);
}

char		*ft_itoh(int n)
{
	int     nbr;
	char	*ptr;
	int 	len;
	int 	b;
	int 	tmp;

	len = 1;
	b = 0;
	nbr = n;
	tmp = nbr;
	while (tmp >= 10)
		tmp = (nbr / ft_power(len++, 16));
	if (len != 1)
		len--;
	ptr = ft_strnew(len + 1);
	if (!ptr)
		return (NULL);
	if (n < 0)
		ptr[b++] = '-';
	if (nbr == 0 && (ptr[b] = '0'))
		return (ptr);
	return (find_value(ptr, nbr, len, b));
}
