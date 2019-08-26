#include <math.h>
#include "includes/ft_printf.h"

void	str_tests(void)
{
	ft_printf("Str 1: |%s|\nStr 2: |%10s|\nStr 3: |%-10s|\nStr 4: |%10.7s|\nStr 5: |%-10.7s|\n", "hello", "world", "Hello", "World", "hEllo");
	printf("Str 1: |%s|\nStr 2: |%10s|\nStr 3: |%-10s|\nStr 4: |%10.7s|\nStr 5: |%-10.7s|\n", "hello", "world", "Hello", "World", "hEllo");
	ft_printf("\n");
	ft_printf("Str 1: |%s|\nStr 2: |%4s|\nStr 3: |%-4s|\nStr 4: |%10.4s|\nStr 5: |%-10.4s|\nStr 6: |%-.7s|\n", "hello", "world", "Hello", "World", "hEllo", "wOrld");
	printf("Str 1: |%s|\nStr 2: |%4s|\nStr 3: |%-4s|\nStr 4: |%10.4s|\nStr 5: |%-10.4s|\nStr 6: |%-.7s|\n", "hello", "world", "Hello", "World", "hEllo", "wOrld");
}

char		*fp_itoa(int n)
{
	char	*tmp;
	char	*ret;
	long	i;
	long	nbr;
	
	tmp = ft_strnew(12);
	i = 0;
	nbr = (long)n;
	if (nbr < 0)
		nbr *= -1;
	while (nbr / 10 > 0)
	{
		tmp[i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	tmp[i++] = nbr + 48;
	if (n < 0)
		tmp[i++] = '-';
	tmp[i] = '\0';
	ret = ft_strrev(tmp);
	ft_strdel(&tmp);
	return (ret);
}

void	int_tests(void)
{
	long	a, b, c, d, e, f, g;
	short	h, i, j;
	long long k, l, m;
	a = 342345245645;
	b = 3423534543;
	c = -234235426545437823;
	d = 9045834502349;
	e = 42;
	f = -0;
	g = 0xfffffffa;
	h = 0;
	i = -15000;
	j = 15000;
	k = 1234567809864563254;
	l = -3245465845856945425;
	m = 0;
	ft_printf("Int 1: |%d|\nInt 2: |%10d|\nInt 3: |%-10d|\nInt 4: |%10.5d|\nInt 5: |%-10.5d|\nInt 6: |%+10.5d|\nInt 7: |%+-10.5d|\n", 42, 90234383, -234234, 25, -25, 420, -420);
	printf("Int 1: |%d|\nInt 2: |%10d|\nInt 3: |%-10d|\nInt 4: |%10.5d|\nInt 5: |%-10.5d|\nInt 6: |%+10.5d|\nInt 7: |%+-10.5d|\n", 42, 90234383, -234234, 25, -25, 420, -420);
	
	ft_printf("\nNext:\n");
	// 3 not working (ret: Int 3: |-?        |), 7 not working (ret: Int 7: |4294967290|)
	ft_printf("Int 1: |%ld|\nInt 2: |%10ld|\nInt 3: |%-10ld|\nInt 4: |%10.5ld|\nInt 5: |%-10.5ld|\nInt 6: |%+10.5ld|\nInt 7: |%+-10.5ld|\n", a, b, c, d, e, f, g);
	printf("Int 1: |%ld|\nInt 2: |%10ld|\nInt 3: |%-10ld|\nInt 4: |%10.5ld|\nInt 5: |%-10.5ld|\nInt 6: |%+10.5ld|\nInt 7: |%+-10.5ld|\n", a, b, c, d, e, f, g);

	ft_printf("\nNext:\n");
	ft_printf("Int 1: |%hd|\nInt 2: |%10hd|\nInt 3: |%-10hd|\nInt 4: |%10.5hd|\nInt 5: |%-10.5hd|\nInt 6: |%+10.5hd|\nInt 7: |%+-10.5hd|\n", h, i, i, j, j, i, i);
	printf("Int 1: |%hd|\nInt 2: |%10hd|\nInt 3: |%-10hd|\nInt 4: |%10.5hd|\nInt 5: |%-10.5hd|\nInt 6: |%+10.5hd|\nInt 7: |%+-10.5hd|\n", h, i, i, j, j, i, i);

	ft_printf("\nNext:\n");
	ft_printf("Int 1: |%lld|\nInt 2: |%20lld|\nInt 3: |%-20lld|\nInt 4: |%20.25lld|\nInt 5: |%-20.25lld|\nInt 6: |%+20.25lld|\nInt 7: |%+-20.25lld|\n", m, k, l, l, k, l, k);
	printf("Int 1: |%lld|\nInt 2: |%20lld|\nInt 3: |%-20lld|\nInt 4: |%20.25lld|\nInt 5: |%-20.25lld|\nInt 6: |%+20.25lld|\nInt 7: |%+-20.25lld|\n", m, k, l, l, k, l, k);
}

void	octal_test(void)
{
	int a = 0xbeef;
	long b = 0xbeefbed;


	ft_printf("octal 1: |%o|\n octal 2: |%lo|\n", a, b);
	printf("octal 1: |%o|\n octal 2: |%lo|\n", a, b);
}

int		main(void)
{

	// STRING TESTS:
	//str_tests();

	// INTEGER TESTS:
	int_tests();

	// OCTAL TESTS:
	octal_test();
	return (0);
}
