/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/05 22:15:00 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>

void	print_error(void)
{
	ft_putstr("Error...\n");
}

// void	cut_and_paste(t_glb *glb, char *fmt)
// {
// 	int i;
// 	int	a;

// 	i = 0;
// 	a = ft_strxlen((const char *)fmt, '%');
// 	parse_padding(glb, fmt);
// 	if (handle_escape(ft_strchr(fmt, '%'), glb->ap) == 0)
// 	{

// 	}
// }

void	parser(t_glb *glb, char *fmt)
{
	if (*fmt == '%')
	{
		fmt++;
		while (*fmt == '#' || *fmt == ' ' || *fmt == '-' || *fmt == '+' || ft_isdigit(*fmt))
			fmt++;
	}
	if (*fmt == 's')
		handle_str(glb, fmt);
	if (*fmt == 'c')
		handle_char(glb, fmt);
	if (*fmt == 'd' || *fmt == 'i')
		handle_int(glb, fmt);
	if (*fmt == 'o')
		handle_oct(glb, fmt);
	if (*fmt == 'x' || *fmt == 'X')
		handle_hex(glb, fmt);
	if (*fmt == 'l')
		handle_long(glb, fmt);
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
		glb->fmt = ft_strnew(a);
		ft_strncpy(glb->fmt, fmt, (size_t)a);
		glb->ret = ft_strjoin(tmp, glb->fmt);
		free((void *)glb->fmt);
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

void	cookie_monster(t_glb *glb)
{
	if (glb->arg)
		ft_strdel(&glb->arg);
	if (glb->ret)
		ft_strdel(&glb->ret);
	if (glb->fmt)
		ft_strdel(&glb->fmt);
}

int	ft_printf(char *sfmt, ...)
{
	//int				ret;
	t_glb			glb;
	t_ar			ar;

	ar_init(&ar);
	glb_init(&glb);
	va_start(glb.ap, sfmt);
	//ret = ft_parser(&ap, sfmt);
	if (has_args(sfmt) == 0)
	{
		ft_putstr(sfmt);
		return (ft_strlen(sfmt));
	}
	while ((ft_strchr(sfmt, '%')))
	{
		chomp(&glb, sfmt);
		sfmt = ft_strchr(sfmt, '%');
		if (*sfmt == '%')
			sfmt++;
		while (*sfmt == '-' || *sfmt == '+' || *sfmt == '#' || ft_isdigit(*sfmt))
			sfmt++;
		if (*sfmt == 's' || *sfmt == 'd' || *sfmt == 'i' || *sfmt == 'x' \
			|| *sfmt == 'X' || *sfmt == 'o' || *sfmt == 'u' || *sfmt == 'f')
			sfmt++;
	}
	if (*sfmt != '\0')
	{
		glb.fmt = ft_strdup(glb.ret);
		ft_strdel(&glb.ret);
		glb.ret = ft_strjoin(glb.fmt, sfmt);
		ft_strdel(&glb.fmt);
	}
	ft_putstr(glb.ret);
	//cookie_monster(&glb);
	return (ft_strlen(glb.ret));
}

int		main(void)
{
	void	*d2[3];
	d2[0] = (void *)42;
	d2[1] = (void*)"Hello World";
	d2[2] = (void *)(-1);
	int	a, b;

	a = 0;
	b = 0;
	a = ft_printf("string: %6s blah: %10s\n", "Hello", "goodbye");
	b = printf("string: %6s blah: %10s\n", "Hello", "goodbye");
	printf("%d\n%d\n", a, b);
	//ft_printf("string: %5s\n", "goodbye world");
	//ft_printf("single line - no arguments...\n");
	return (0);
}

