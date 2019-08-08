/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:10:40 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/08 14:14:05 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		parse_string(t_glb *glb)
{
	int	ret;

	ret = 0;
	return (ret);
}

int		parse_char(t_glb *glb)
{
	int	ret;

	ret = 0;
	return (ret);
}

int		parse_int(t_glb *glb)
{
	int	ret;

	ret = 0;
	return (ret);
}

int		parse_long(t_glb *glb)
{
	int	ret;

	ret = 0;
	return (ret);
}

int		parse_ptr(t_glb *glb)
{
	int	ret;

	ret = 0;
	return (ret);
}

int		parse_oct(t_glb *glb)
{
	return (0);
}

int		parse_unsigned(t_glb *glb)
{
	return (0);
}

int		parse_hex(t_glb *glb)
{
	return (0);
}

int		parse_bin(t_glb *glb)
{
	return (0);
}

int		parse_float(t_glb *glb)
{
	return (0);
}

int		parse_uint(t_glb *glb)
{
	return (0);
}

int		parse_conversion(t_glb *glb, char *fmt)
{
	int	ret;
	int	cur;

	ret = 0;
	cur = 0;
	while (cur < 12)
	{
		if (*fmt == 's')
			// glb list = 's';
		// ...
		cur++; 
	}
}
