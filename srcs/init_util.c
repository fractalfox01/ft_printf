/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:31:25 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/09 12:07:19 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	glb_init(t_glb *glb)
{
	glb->ret = 0;
	glb->ret_total = 0;
	glb->fmt = NULL;
	glb->total = 0;
	glb->buf = 0;
	glb->ncount = 0;
	glb->cont = 1;
	glb->err_type = 0;
	glb->argfun[0] = parse_string;
	glb->argfun[1] = parse_char;
	glb->argfun[2] = parse_int;
	glb->argfun[3] = parse_int;
	glb->argfun[4] = parse_oct;
	glb->argfun[5] = parse_unsigned;
	glb->argfun[6] = parse_hex;
	glb->argfun[7] = parse_hex;
	glb->argfun[8] = parse_float;
	glb->argfun[9] = parse_float;
	glb->argfun[10] = parse_ptr;
	glb->argfun[11] = percent_string;
	glb->argfun[12] = NULL;
	glb->argfun[13] = NULL;
	glb->argfun[14] = NULL;
	glb->args = new_list();
}

void	init_var(t_var *var, t_glb *glb)
{
	var->i = 0;
	var->stop = 0;
	var->start = 0;
	var->leftovers = NULL;
	var->tmp = NULL;
	var->arg = FMT_SPEC;
	var->fmt = glb->fmt;
}
