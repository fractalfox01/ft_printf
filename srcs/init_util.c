/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:31:25 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/20 12:38:14 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_alst	*get_arg(t_glb *glb)
{
	t_alst *arg;

	arg = glb->args;
	while (CUR_ID < T_COUNT)
	{
		arg = arg->next;
	}
	return (arg);
}

static void	new_info(t_alst *arg)
{
	arg->info = (t_info *)malloc(sizeof(t_info) * 1);
	arg->info->blank_flag = 0;
	arg->info->hash_flag = 0;
	arg->info->minus_flag = 0;
	arg->info->plus_flag = 0;
	arg->info->zero_flag = 0;
	arg->info->fieldwidth = 0;
	arg->info->precision = 0;
	arg->info->blank = 0;
	arg->info->neg = 0;
	arg->info->str = PF_NULL;
	arg->info->padded = PF_NULL;
	arg->info->tmp1 = PF_NULL;
	arg->info->tmp2 = PF_NULL;
	arg->info->arg = PF_NULL;
}

t_alst	*new_list(void)
{
	t_alst	*list;

	list = (t_alst *)malloc(sizeof(t_alst) * 1);
	list->id = 0;
	new_info(list);
	list->next = NULL;
	return (list);
}

void	new_glb_list(t_glb *glb)
{
	glb->args = (t_alst *)malloc(sizeof(t_alst) * 1);
	glb->args->id = 0;
	new_info(glb->args);
	glb->args->next = NULL;
}

t_glb *glb_init(t_glb *glb)
{
	glb = (t_glb *)malloc(sizeof(t_glb) * 1);
	glb->ret = 0;
	glb->ret_total = 0;
	glb->fmt = PF_NULL;
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
	new_glb_list(glb);
	return (glb);
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
