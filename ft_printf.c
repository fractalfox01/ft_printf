/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/31 20:13:07 by tvandivi         ###   ########.fr       */
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

char	*parse_padding(t_glb *glb, char *fmt)
{
	char	*tmp;
	char	*zero;
	int		max;
	int		i;

	max = 0;
	i = 0;
	if (*fmt == '%' && glb && *(fmt + 1) != '\0')
	{
		fmt++;
		if (ft_isdigit(*fmt))
		{
			max = ft_atoi(fmt);
			tmp = ft_strdup(glb->ret);
			zero = ft_strnew(max);
			ft_memset((void *)zero, ' ', max);
			free((void *)glb->ret);
			glb->ret = ft_strjoin(tmp, zero);
		}
	}
	return (fmt);
}

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
	va_list	ap;

	glb->ap = &ap;
	info.b_sign = 0;
	info.f_prefix = 0;
	info.f_sign = 0;
	info.right_pad = 0;
	info.zero_pad = 0;
	glb->ret = NULL;
	glb->fmt = NULL;
	glb->info = &info;
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
		//cut_and_paste(glb, fmt);
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
