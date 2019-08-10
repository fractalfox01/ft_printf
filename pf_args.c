/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:10:40 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/10 14:27:08 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_arg_lst	*new_list(void)
{
	t_arg_lst	*list;
	t_info		*info;

	list = (t_arg_lst *)malloc(sizeof(t_arg_lst) * 1);
	info = (t_info *)malloc(sizeof(t_info) * 1);
	list->id = 0;
	list->info = info;
	list->info->fieldwidth = 0;
	list->info->precision = 0;
	list->next = NULL;
	return (list);
}

int		parse_string(t_glb *glb)
{
	t_arg_lst	*tmp;
	int			ret;

	ret = 0;
	if (glb)
	{
		tmp = glb->args;
		while (tmp->id < glb->total)
		{
			tmp = tmp->next;
		}
		glb->total += 1;
		tmp->info->arg = va_arg(glb->ap, char *);
		tmp->next = new_list();
		tmp->next->id = (tmp->id + 1);
	}
	return (ret);
}

int		parse_char(t_glb *glb)
{
	int	ret;

	ret = 0;
	if (glb)
	{
		
	}
	return (ret);
}

int		parse_int(t_glb *glb)
{
	int	ret;

	ret = 0;
	if (glb)
	{
		
	}
	return (ret);
}

int		parse_long(t_glb *glb)
{
	int	ret;

	ret = 0;
	if (glb)
	{
		
	}
	return (ret);
}

int		parse_ptr(t_glb *glb)
{
	int	ret;

	ret = 0;
	if (glb)
	{
		
	}
	return (ret);
}

int		parse_oct(t_glb *glb)
{
	int	ret;

	ret = 0;
	if (glb)
	{
		
	}
	return (ret);
}

int		parse_unsigned(t_glb *glb)
{
	int	ret;

	ret = 0;
	if (glb)
	{
		
	}
	return (ret);
}

int		parse_hex(t_glb *glb)
{
	int	ret;

	ret = 0;
	if (glb)
	{
		
	}
	return (ret);
}

int		parse_bin(t_glb *glb)
{
	int	ret;

	ret = 0;
	if (glb)
	{
		
	}
	return (ret);
}

int		parse_float(t_glb *glb)
{
	int	ret;

	ret = 0;
	if (glb)
	{
		
	}
	return (ret);
}

int		parse_uint(t_glb *glb)
{
	int	ret;

	ret = 0;
	if (glb)
	{
		
	}
	return (ret);
}

int		parse_conversion(t_glb *glb, char *fmt)
{
	int	ret;
	int	cur;

	ret = 0;
	cur = 0;
	while (glb && cur < 10)
	{
		if (*fmt == 's')
		{
			
		}
		// glb list = 's';
		// ...
		cur++; 
	}
	return (ret);
}
