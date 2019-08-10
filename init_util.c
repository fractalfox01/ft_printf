/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:31:25 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/10 14:20:23 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	glb_init(t_glb *glb)
{
	glb->ret = NULL;
	glb->ret_total = 0;
	glb->fmt = NULL;
	glb->total = 0;
	glb->buf = 0;
	glb->argfun[0] = parse_string;
	glb->argfun[1] = parse_char;
	glb->argfun[2] = parse_int;
	glb->argfun[3] = parse_long;
	glb->argfun[4] = parse_ptr;
	glb->argfun[5] = parse_oct;
	glb->argfun[6] = parse_unsigned;
	glb->argfun[7] = parse_hex;
	glb->argfun[8] = parse_bin;
	glb->argfun[9] = parse_float;
	glb->argfun[10] = parse_uint;
	glb->argfun[11] = NULL;
	glb->args = new_list();
}
