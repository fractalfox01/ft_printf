/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:11:39 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/02 13:42:23 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static long	fp_pow(long n, long base)
{
	long	i;
	long	nbr;

	i = 1;
	nbr = 1;
	if (n == 1)
		return (1);
	if (n > 1)
	{
		while (i++ < n)
			nbr *= base;
	}
	else
		return (-1);
	return (nbr);
}

char	*ft_ftoa(long double flt, int afterpoint)
{
	long long		n;
	char			*int_part;
	char			*stmp;
	long double		d;
	char			*ret;
	int				dir;

	dir = 1;
	n = (long long)flt;
	int_part = ft_strjoin(ft_lltoa(n), ".");
	d = flt - (long long)n;
	n = 0;
	if (d < 0)
	{
		dir *= -1;
		d *= dir;
	}
	while (d >= 0 && d < 1 && n++ < afterpoint)
	{
		d = d * fp_pow(2, 10);
		stmp = ft_lltoa((int)d);
		d = d - (int)d;
		ret = ft_strjoin(int_part, stmp);
		ft_strdel(&int_part);
		int_part = ft_strdup(ret);
		ft_strdel(&stmp);
	}
	// if (n < afterpoint && n != 0)
	// 	ret = fp_hlper(ret, int_part, afterpoint - n);
	ft_strdel(&int_part);
	return (ret);
}
