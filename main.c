#include "includes/ft_printf.h"

int		main(void)
{
	long a, b, c = 0;
	int	d, e, f = 0;
	unsigned g, h, i;
	int	*ptr;
	float j = 524.385;
	a = 4256786785678768;
	b = 4211;
	c = 127123;
	d = 420123;
	e = -697345;
	f = 374345;
	g = 123;
	h = -456789;
	i = 98712334;
	ptr = &e;
	//char str0[19] = "string: |%6.3s|\n";
	// char str1[29] = "string: %10s string2: %25s\n";
	// //char str2[25] = "number: %d number2: %d\n";
	// char str3[31] = "string: %-10s string2: %-25s\n";
	// char str4[44] = "char1: |%+10c| char2: |%10c|\nLEFTOVERS!!!\n";
	// char str5[40] = "int1: |%+10d| int2: |%-10d| int3: |%d|\n";
	//ft_printf("Mine:\n");
	//ft_printf("string0: |%15.4s|\nstring1: |%-6s|\nstring2: |%6s|\nstring3: |%6.3s|\n", "waffle", "hello", "world", "bye!!");
	//ft_printf("int0: |%-+30.20ld|\n", a);
	//printf("int0: |%-+30.20ld|\n", a);
	// -->> ft_printf("int0: |%+7.5i|\nint1: |%7.5i|\nint2: |%+6i|\n", d, e, f);
	//printf("ltoh: %s\n", ft_ltoh(b));
	//ft_printf("octal: %o\n", d);
	//printf("octal: %o\n", d);
	//printf("\nThiers:\n");
	//printf("string0: |%15.4s|\nstring1: |%-6s|\nstring2: |%6s|\nstring3: |%6.3s|\n", "waffle", "hello", "world", "bye!!");
	//printf("int0: |%+10.6ld|\nint1: |%10.6ld|\nint2: |%+6ld|\n", a, b, c);
	//ft_printf("int0: |%+7.5li|\nint1: |%7.5li|\nint2: |%+6li|\n", a, b, c);
	//int	aft = (int)j;
	char	stmp[20];
	
	ft_printf("float: %s\n", ft_ftoa(j, 5));
	printf("float: %f\n", j);
	ft_printf("|%10s|\n", stmp);
	ft_printf("int: |%10.6d|\n", e);
	// ft_printf("int0: |%u|\nint1: |%u|\nint2: |%u|\n", g, h, i);
	// printf("int0: |%u|\nint1: |%u|\nint2: |%u|\n", g, h, i);
	return (0);
}
