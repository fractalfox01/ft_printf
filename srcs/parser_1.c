/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:08:10 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/11 14:29:17 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse_oct(t_glb *glb, t_alst *arg, char *orig)
{
	long long	c;

	glb->total += 1;
	c = va_arg(glb->ap, long long);
	if (c < 0)
		arg->info->neg = 1;
	if (arg->info->precision > arg->info->fieldwidth)
		arg->info->fieldwidth = arg->info->precision;
	if (arg->info->hash_flag == 1)
		arg->info->padded = ft_strjoin("0", ft_lltoa(ft_lltoo(c)));
	else
		arg->info->padded = ft_lltoa(ft_lltoo(c));
	if (arg->info->precision > 0)
		lnglng_oct_helper(arg, c, ft_strlen(arg->info->padded));
	if (arg->info->minus_flag == 1)
		octal_assign_1(arg, arg->info->padded, orig, arg->info->neg);
	else if (arg->info->plus_flag == 1 && arg->info->neg == 0)
		octal_assign_2(arg, arg->info->padded, orig);
	else
		arg->info->arg = ft_strjoin(orig, pad_left(arg, arg->info->padded, 0));
	arg->next = new_list();
	arg->next->id = (arg->id + 1);
	return (0);
}

int		parse_unsigned(t_glb *glb, t_alst *arg, char *orig)
{
	unsigned long long	c;
	char				*padded;
	int					neg;
	char				*tmp;

	if (glb && arg && orig)
	{
		glb->total += 1;
		c = va_arg(glb->ap, unsigned long long);
		if (c == 0)
		{
			arg->info->arg = ft_strjoin(orig, "");
			arg->next = new_list();
			arg->next->id = (arg->id + 1);
		}
		padded = assign_u_buf(arg, c);
		assign_u_arg(arg, padded, neg, orig);
		arg->next = new_list();
		arg->next->id = arg->id + 1;
	}
	return (0);
}

int		parse_hex(t_glb *glb, t_alst *arg, char *orig)
{
	long long	c;
	char	*tmp;
	int		neg;

	neg = 0;
	glb->total += 1;
	c = va_arg(glb->ap, long long);
	if (c < 0)
		neg = 1;
	arg->info->padded = assign_x_buf(glb, arg, c);
	check_case(glb, &arg->info->padded);
	if (arg->info->hash_flag == 1 && arg->info->zero_flag == 0 && c != 0)
		hex_helper_1(arg);
	if (arg->info->precision > 0)
		long_hex_helper(arg, c, ft_strlen(arg->info->padded));
	hex_flag_find(arg, neg, orig);
	if (arg->info->hash_flag == 1 && c > 0)
		hex_helper_2(glb, arg);
	glb->upcase = 0;
	arg->next = new_list();
	arg->next->id = (arg->id + 1);
	ft_strdel(&(arg->info->padded));
	return (0);
}
