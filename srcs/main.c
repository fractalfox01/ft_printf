#include <limits.h>
#include "../includes/ft_printf.h"

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
	g = -4294967290;
	h = 0;
	i = -15000;
	j = 15000;
	k = 0x7ffffffffffffffe;
	l = -3245465845856945425;
	m = 0;
	ft_printf("int testing: %%d\n", 42);
	ft_printf("Int 1: |%d|\nInt 2: |%10d|\nInt 3: |%-10d|\nInt 4: |%10.5d|\nInt 5: |%-10.5d|\nInt 6: |%+10.5d|\nInt 7: |%+-10.5d|\n", 42, 90234383, -234234, 25, -25, 420, -420);
	printf("Int 1: |%d|\nInt 2: |%10d|\nInt 3: |%-10d|\nInt 4: |%10.5d|\nInt 5: |%-10.5d|\nInt 6: |%+10.5d|\nInt 7: |%+-10.5d|\n", 42, 90234383, -234234, 25, -25, 420, -420);
	
	ft_printf("\nlong testing: %%l\n");
	ft_printf("Int 1: |%ld|\nInt 2: |%20ld|\nInt 3: |%-20ld|\nInt 4: |%20.5ld|\nInt 5: |%-20.5ld|\nInt 6: |%+20.5ld|\nInt 7: |%+-20.7ld|\n", g, b, c, d, e, f, g);
	printf("Int 1: |%ld|\nInt 2: |%20ld|\nInt 3: |%-20ld|\nInt 4: |%20.5ld|\nInt 5: |%-20.5ld|\nInt 6: |%+20.5ld|\nInt 7: |%+-20.7ld|\n", g, b, c, d, e, f, g);

	ft_printf("\nshort testing: %%h\n");
	ft_printf("Int 1: |%hd|\nInt 2: |%10hd|\nInt 3: |%-10hd|\nInt 4: |%10.5hd|\nInt 5: |%-10.5hd|\nInt 6: |%+10.5hd|\nInt 7: |%+-10.5hd|\n", h, i, i, j, j, i, i);
	printf("Int 1: |%hd|\nInt 2: |%10hd|\nInt 3: |%-10hd|\nInt 4: |%10.5hd|\nInt 5: |%-10.5hd|\nInt 6: |%+10.5hd|\nInt 7: |%+-10.5hd|\n", h, i, i, j, j, i, i);

	ft_printf("\nlong long testing: %%ll\n");
	ft_printf("Int 1: |%lld|\nInt 2: |%25lld|\nInt 3: |%-25lld|\nInt 4: |%35.25lld|\nInt 5: |%-35.25lld|\nInt 6: |%+35.25lld|\nInt 7: |%+-35.25lld|\n", m, k, l, l, k, l, k);
	printf("Int 1: |%lld|\nInt 2: |%25lld|\nInt 3: |%-25lld|\nInt 4: |%35.25lld|\nInt 5: |%-35.25lld|\nInt 6: |%+35.25lld|\nInt 7: |%+-35.25lld|\n", m, k, l, l, k, l, k);
}

void	octal_test(void)
{
	short x = 0xff;
	int a = 0xbeef;
	long b = 0xbeefbeddead;
	long long c = 0x7fffffffffffff;

	ft_printf("octal 1: |%o|\noctal 2: |%ho|\noctal 3: |%lo|\noctal 4: |%llo|\n", a, x, b, c);
	printf("octal 1: |%o|\noctal 2: |%ho|\noctal 3: |%lo|\noctal 4: |%llo|\n", a, x, b, c);
	ft_printf("\noctal 1: |%10o|\noctal 2: |%10ho|\noctal 3: |%20lo|\noctal 4: |%20llo|\n", a, x, b, c);
	printf("octal 1: |%10o|\noctal 2: |%10ho|\noctal 3: |%20lo|\noctal 4: |%20llo|\n", a, x, b, c);
	ft_printf("\noctal 1: |%-10o|\noctal 2: |%-10ho|\noctal 3: |%-20lo|\noctal 4: |%-20llo|\n", a, x, b, c);
	printf("octal 1: |%-10o|\noctal 2: |%-10ho|\noctal 3: |%-20lo|\noctal 4: |%-20llo|\n", a, x, b, c);
}

void	hex_test(void)
{
	short x = 0xff;
	int	a = 0xbeef;
	long b = 0xdeadbeddead;
	long long c = 0x7ffffffffffffffe;

	ft_printf("hex 1: |%x|\nhex 2: |%hx|\nhex 3: |%lx|\nhex 4: |%llx|\n", a, x, b, c);
	printf("hex 1: |%x|\nhex 2: |%hx|\nhex 3: |%lx|\nhex 4: |%llx|\n", a, x, b, c);
	ft_printf("\nhex 1: |%15x|\nhex 2: |%15hx|\nhex 3: |%25lx|\nhex 4: |%25llx|\n", a, x, b, c);
	printf("hex 1: |%15x|\nhex 2: |%15hx|\nhex 3: |%25lx|\nhex 4: |%25llx|\n", a, x, b, c);
	ft_printf("\nhex 1: |%-15x|\nhex 2: |%-15hx|\nhex 3: |%-25lx|\nhex 4: |%-25llx|\n", a, x, b, c);
	printf("hex 1: |%-15x|\nhex 2: |%-15hx|\nhex 3: |%-25lx|\nhex 4: |%-25llx|\n", a, x, b, c);
	ft_printf("\nhex 1: |%-15.7x|\nhex 2: |%-15.5hx|\nhex 3: |%-25.15lx|\nhex 4: |%-25.20llx|\n", a, x, b, c);
	printf("hex 1: |%-15.7x|\nhex 2: |%-15.5hx|\nhex 3: |%-25.15lx|\nhex 4: |%-25.20llx|\n", a, x, b, c);
	ft_printf("\nhex 1: |%15.7x|\nhex 2: |%15.5hx|\nhex 3: |%25.15lx|\nhex 4: |%25.20llx|\n", a, x, b, c);
	printf("hex 1: |%15.7x|\nhex 2: |%15.5hx|\nhex 3: |%25.15lx|\nhex 4: |%25.20llx|\n", a, x, b, c);
}

void	float_test(void)
{
//	long double b = 1234765984536567456.123543657678756;
	float c = 12347.123543657678756;

	// NOTE: Standard printf does not work with 'l' length modifier.
	ft_printf("float 1: |%f|\nfloat 2: |%20f|\nfloat 3: |%25f|\nfloat 4: |%-25f|\n", c, c, c, c);
	printf("float 1: |%f|\nfloat 2: |%20f|\nfloat 3: |%25f|\nfloat 4: |%-25f|\n", c, c, c, c);
//	ft_printf("float 1: |%f|\nfloat 2: |%20Lf|\nfloat 3: |%25lf|\nfloat 4: |%-25lf|\nfloat 5: |%+-50lf|\nfloat 6: |%-+50f|\nfloat 7: |%-+15.2lf|\n", c, b, b, b, b, c, b);
//	printf("float 1: |%f|\nfloat 2: |%20Lf|\nfloat 3: |%25Lf|\nfloat 4: |%-25Lf|\nfloat 5: |%+-50Lf|\nfloat 6: |%-+50f|\nfloat 7: |%-+15.2Lf|\n", c, b, b, b, b, c, b);
}

void	pointer_test()
{
	int		*iptr;
	int b = 42;
	char	str[20] = "Hello World";
	char	*sptr = str;
	iptr = &b;
	
	ft_printf("int pointer: %p\nStr pointer: %p\n", iptr, sptr);
	printf("int pointer: %p\nStr pointer: %p\n", iptr, sptr);
}

void	unsigned_test()
{
	unsigned a = 123456678;
	unsigned long b = 0xdeadbeef;
	unsigned long long c = 0x7fffffffffffffff;

	ft_printf("usign: |%u|\nusign long: |%lu|\nusign long long: |%llu|\n", a, b, c);
	printf("usign: |%u|\nusign long: |%lu|\nusign long long: |%llu|\n", a, b, c);
	ft_printf("\nusign: |%15u|\nusign long: |%15lu|\nusign long long: |%25llu|\n", a, b, c);
	printf("usign: |%15u|\nusign long: |%15lu|\nusign long long: |%25llu|\n", a, b, c);
	ft_printf("\nusign: |%-15u|\nusign long: |%-15lu|\nusign long long: |%-25llu|\n", a, b, c);
	printf("usign: |%-15u|\nusign long: |%-15lu|\nusign long long: |%-25llu|\n", a, b, c);
}

int		main(void)
{
    // printf("%%d 0000042 == |%d|\n", 0000042);
    // ft_printf("%%d 0000042 == |%d|\n", 0000042);
    // ft_printf("Kashim a %d histoires à raconter\n", 1001);
    // printf("Kashim a %d histoires à raconter\n", 1001);
    // ft_printf("Il fait au moins %d\n", -8000);
    // printf("Il fait au moins %d\n", -8000);
	// ft_printf("%d\n", -0);
    // printf("%d\n", -0);
	// ft_printf("%d\n", 0);
    // printf("%d\n", 0);
	// ft_printf("%d\n", INT_MAX);
    // printf("%d\n", INT_MAX);
	// ft_printf("%d\n", INT_MIN);
    // printf("%d\n", INT_MIN);
	// ft_printf("%d\n", INT_MIN - 1);
    // printf("%d\n", INT_MIN - 1);
	// ft_printf("%d\n", INT_MAX + 1);
    // printf("%d\n", INT_MAX + 1);
	// ft_printf("%%d 0000042 == |%d|\n", 0000042);
    // printf("%%d 0000042 == |%d|\n", 0000042);
	// ft_printf("%%d \t == |%d|\n", '\t');
    // printf("%%d \t == |%d|\n", '\t');
	// ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
    // printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');

    // ft_printf("%c\n", 42);
	// ft_printf("Kashim a %c histoires à raconter\n", 1001);
	// ft_printf("Il fait au moins %c\n", -8000);
	ft_printf("%c\n", -0);
	ft_printf("%c\n", 0);
	ft_printf("%c\n", INT_MAX);
	ft_printf("%c\n", 'c');
	ft_printf("%c\n", '\n');
    ft_printf("next:\n");
    printf("%c\n", '\0');
	// ft_printf("%c", 'l');
	// ft_printf("%c", 'y');
	// ft_printf("%c", ' ');
	// ft_printf("%c", 'e');
	// ft_printf("%c", 's');
	// ft_printf("%c", 't');
	// ft_printf("%c", ' ');
	// ft_printf("%c", 'f');
	// ft_printf("%c", 'a');
	// ft_printf("%c", 'n');
	// ft_printf("%c", 't');
	// ft_printf("%c", 'a');
	// ft_printf("%c", 's');
	// ft_printf("%c", 't');
	// ft_printf("%c", 'i');
	// ft_printf("%c", 'q');
	// ft_printf("%c", 'u');
	// ft_printf("%c", 'e');
	// ft_printf("%c\n", '!');
	// ft_printf("%c\n", '\r');
	// ft_printf("%c\n", '\t');

    // printf("%c\n", 42);
	// printf("Kashim a %c histoires à raconter\n", 1001);
	// printf("Il fait au moins %c\n", -8000);
	printf("%c\n", -0);
	printf("%c\n", 0);
	printf("%c\n", INT_MAX);
	printf("%c\n", 'c');
	printf("%c\n", '\n');
    printf("Done\n");
	// printf("%c", 'l');
	// printf("%c", 'y');
	// printf("%c", ' ');
	// printf("%c", 'e');
	// printf("%c", 's');
	// printf("%c", 't');
	// printf("%c", ' ');
	// printf("%c", 'f');
	// printf("%c", 'a');
	// printf("%c", 'n');
	// printf("%c", 't');
	// printf("%c", 'a');
	// printf("%c", 's');
	// printf("%c", 't');
	// printf("%c", 'i');
	// printf("%c", 'q');
	// printf("%c", 'u');
	// printf("%c", 'e');
	// printf("%c\n", '!');
	// printf("%c\n", '\r');
	// printf("%c\n", '\t');
	// STRING TESTS:
	//str_tests();

	// INTEGER TESTS:
	//int_tests();

	// OCTAL TESTS:
	//octal_test();

	// HEX TESTS:
	//hex_test();

	// FLOAT TESTS:
	//float_test();

	// POINTER TESTS:
	// pointer_test();

	// UNSIGNED TESTS:
	// unsigned_test();
	return (0);
}
