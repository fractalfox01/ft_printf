/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/01 12:46:25 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>

void	print_error(void)
{
	ft_putstr("Error...\n");
}

void	cut_and_paste(t_glb *glb, char *fmt)
{
	int i;
	int	a;

	i = 0;
	a = ft_strxlen((const char *)fmt, '%');
	parse_padding(glb, fmt);
	if (handle_escape(ft_strchr(fmt, '%'), glb->ap) == 0)
	{

	}
}

void	chomp(t_glb *glb, char *fmt)
{
	int		a;
	size_t	i;
	int		j;
	char	*tmp;

	a = ft_strxlen((const char *)fmt, '%');
	i = 0;
	j = 0;
	tmp = NULL;
	if (!(glb->ret))
	{
		glb->ret = ft_strnew(a);
		glb->ret = ft_strncpy(glb->ret, (const char *)fmt, (size_t)a);
		fmt = ft_strchr(fmt, '%');
		parse_padding(glb, fmt);
	}
	else
	{
		tmp = ft_strdup(glb->ret);
		ft_strdel((char **)&glb->ret);
		glb->ret = ft_strnew(ft_strlen(tmp) + a);
		ft_strcpy(glb->ret, tmp);
		fmt = ft_strchr(fmt, '%');
		parse_padding(glb, fmt);
	}
}

int	has_args(char *fmt)
{
	int i;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i + 1] != '\0')
		{
			if (fmt[i] == '%' && fmt[i + 1] != '%')
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_printf(char *sfmt, ...)
{
	//int				ret;
	t_glb			glb;
	t_ar			ar;

	ar_init(&ar);
	glb_init(&glb);
	va_start(*glb.ap, sfmt);
	//ret = ft_parser(&ap, sfmt);
	if (has_args(sfmt) == 0)
		ft_putstr(sfmt);
	while ((ft_strchr(sfmt, '%')))
	{
		chomp(&glb, sfmt);
		sfmt = ft_strchr(sfmt, '%');
		sfmt++;
		ft_putstr(glb.fmt);
	}
	ft_putchar('\n');
}

int		main(void)
{
	void	*d2[3];
	d2[0] = (void *)42;
	d2[1] = (void*)"Hello World";
	d2[2] = (void *)(-1);

	ft_printf("string: %5s\tchar: %c\tpointer: %p\n", "Hello", 'G', d2);
	ft_printf("single line - no arguments...%");
	return (0);
}
