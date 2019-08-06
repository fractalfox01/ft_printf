/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:11:04 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/05 21:37:46 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_isescape(unsigned char c)
{
	if (c == '\a' || c == '\b' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v' || c == '\\')
		return (1);
	if (c == '\'' || c == '\"' || c == '\?' || c == '\0')
		return (1);
	return (0);
}

size_t	handle_escape(t_glb *glb, char *fmt)
{
	int	i;

	i = 0;
	if (fmt && glb)
	{
		if (ft_isescape(*fmt))
		{
			
		}
	}
	return (0);
}

size_t	handle_str(t_glb *glb, char *fmt)
{
	//char	*tmp;
	char	*str;
	if (*fmt)
	{
		
		str = (char *)va_arg(glb->ap, char *);
		glb->arg = ft_strdup(str);
	}
	// if (glb && fmt && str)
	// {
	// 	tmp = ft_strdup(glb->ret);
	// 	free((void *)glb->ret);
	// 	glb->ret = ft_strjoin(tmp, str);
	// 	free((void *)tmp);
	// }
	return (0);
}

size_t	handle_wstr(t_glb *glb, char *fmt)
{
	if (glb && fmt)
	{
		return (1);
	}
	return (0);
}

size_t	handle_int(t_glb *glb, char *fmt)
{
	if (fmt && glb)
	{
		return (1);
	}
	return (0);
}

size_t	handle_long(t_glb *glb, char *fmt)
{
	if (fmt && glb)
	{
		return (1);
	}
	return (0);
}
