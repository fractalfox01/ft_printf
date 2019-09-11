/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:45:41 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/11 12:46:04 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse_string(t_glb *glb, t_alst *arg, char *orig)
{
	char		*buf_str;

	if (glb)
	{
		glb->total += 1;
		buf_str = va_arg(glb->ap, char *);
		if (!(buf_str) && arg->info->blank == 0 && arg->info->fieldwidth == 0)
			ps_helper_1(arg, orig);
		else if ((!(buf_str) || !(*buf_str) || *buf_str == 0) || arg->info->blank == 1)
			ps_helper_2(arg, orig, buf_str);
		else
			ps_helper_3(arg, orig, buf_str);
	}
	return (0);
}

static void	pf_putchar(t_glb *glb)
{
	glb->ncount++;
	write(1, "\0", 1);
}

static char *assign_buf(size_t buf_len)
{
	if (buf_len)
		return (ft_strnew(buf_len));
	else
		return (ft_strdup(" "));
}

int		parse_char(t_glb *glb, t_alst *arg, char *orig)
{
	int		c;
	size_t	buf_len;
	char	*padded;

	buf_len = 0;
	glb->total += 1;
	c = va_arg(glb->ap, int);
	if (c > 127 || c < 0)
		c = '?';
	if (c == 0)
		pf_putchar(glb);
	buf_len = (size_t)arg->info->fieldwidth;
	padded = assign_buf(buf_len);
	padded[0] = c;
	if (arg->info->plus_flag == 1)
		arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 0));
	if (arg->info->minus_flag == 1)
		arg->info->arg = ft_strjoin(orig, pad_right(arg, padded));
	else
		arg->info->arg = ft_strjoin(orig, pad_left(arg, padded, 0));
	arg->next = new_list();
	arg->next->id = (arg->id + 1);
	return (0);
}
