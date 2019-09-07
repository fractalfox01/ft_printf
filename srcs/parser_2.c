/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:12:11 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/06 18:12:07 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*fp_pointer(long long n)
{
	char	        *tmp;
	char	        *ret;
	long long	i;
	long long	nbr;
    char        *hex;
	
    hex = ft_strdup("0123456789abcdef");
	tmp = ft_strnew(21);
	i = 0;
	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	while (nbr / 16 > 0)
	{
		tmp[i++] = hex[(nbr % 16)];
		nbr /= 16;
	}
	tmp[i++] = hex[nbr];
	if (n < 0)
		tmp[i++] = '-';
	tmp[i] = '\0';
	ret = ft_strrev(tmp);
	ft_strdel(&tmp);
	return (ret);
}

int		parse_ptr(t_glb *glb, t_alst *arg, char *orig)
{
	long long	n;
	char		*tmp;

	if (glb && arg && orig)
	{
		n = va_arg(glb->ap, long long);
		tmp = ft_strjoin("0x", fp_pointer(n));
		arg->info->arg = ft_strjoin(orig, tmp);
		ft_strdel(&tmp);
		glb->total += 1;
		arg->next = new_list();
		arg->next->id = (arg->id + 1);
	}
	return (0);
}
