/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:31:25 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/05 14:57:34 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ar_init(t_ar *ar)
{
	if (ar)
	{
		ar->parser_fun[0] = handle_binary;
		ar->parser_fun[1] = handle_char;
		ar->parser_fun[2] = handle_escape;
		ar->parser_fun[3] = handle_float;
		ar->parser_fun[4] = handle_hex;
		ar->parser_fun[5] = handle_int;
		ar->parser_fun[6] = handle_long;
		ar->parser_fun[7] = handle_oct;
		ar->parser_fun[8] = handle_ptr;
		ar->parser_fun[9] = handle_str;
		ar->parser_fun[10] = handle_uint;
		ar->parser_fun[11] = handle_unsigned;
		ar->parser_fun[12] = handle_wstr;
	}
}

void	glb_init(t_glb *glb)
{
	t_info	info;

	glb->ret = NULL;
	glb->fmt = NULL;
	glb->pad_size = 0;
	glb->info = *&info;
}
