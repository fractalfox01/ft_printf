/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:11:39 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/21 20:58:06 by tvandivi         ###   ########.fr       */
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

static char	*fp_hlper(char *ret, char *ip, int ap)
{
	char	*stmp;

	stmp = ft_strnew(ap);
	ft_memset(stmp, '0', ap);
	ip = ft_strdup(ret);
	ft_strdel(&ret);
	ret = ft_strjoin(ip, stmp);
	ft_strdel(&stmp);
	return (ret);
}

char	*ft_ftoa(double flt, int afterpoint)
{
	int		n;
	char	*int_part;
	char	*stmp;
	double	d;
	char	*ret;

	n = (int)flt;
	int_part = ft_strjoin(ft_itoa(n), ".");
	d = flt - n;
	n = 0;
	while (d > 0 && n++ < afterpoint)
	{
		d = d * fp_pow(2, 10);
		stmp = ft_itoa((int)d);
		d = d - (int)d;
		ret = ft_strjoin(int_part, stmp);
		ft_strdel(&int_part);
		int_part = ft_strdup(ret);
		ft_strdel(&stmp);
	}
	if (n < afterpoint)
		ret = fp_hlper(ret, int_part, afterpoint - n);
	ft_strdel(&int_part);
	return (ret);
}
