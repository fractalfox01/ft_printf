#include <math.h>
#include "includes/ft_printf.h"

int		main(void)
{
	char str[] = "Simple string";
	long a, b, c = 0;
	int	d, e, f = 0;
	unsigned g, h, i;
	int	*int_ptr;
	long *lng_ptr;
	char *str_ptr;
	void *vptr;
	//float j = 134454.16042534565756746;
	a = 4256786785678768;
	b = 4211;
	c = 127123;
	d = 420123;
	e = -697345;
	f = 374345;
	g = 4294967295;
	h = 456789;
	i = 98712334;
	int_ptr = &e;
	lng_ptr = &a;
	str_ptr = str;
	vptr = &*(void *)(str_ptr);
	long ptest = (long)vptr;
	
	ft_printf("int pointer: %p\n", int_ptr);
	printf("int pointer: %p\n", int_ptr);
	ft_printf("long pointer: %p\n", lng_ptr);
	printf("long pointer: %p\n", lng_ptr);
	ft_printf("string pointer: %p\n", str_ptr);
	printf("string pointer: %p\n", str_ptr);
	ft_printf("lx: %lx\n", ptest);
	printf("lx: %lx\n", ptest);

	ft_printf("string 1: |%15.4s|\nstring 2: |%-6s|\nstring 3: |%6s|\nstring 4: |%6.3s|\n", "waffle", "hello", "world", "bye!!");
	printf("string 1: |%15.4s|\nstring 2: |%-6s|\nstring 3: |%6s|\nstring 4: |%6.3s|\n", "waffle", "hello", "world", "bye!!");

	ft_printf("char 1: |%c|\nchar 2: |%10c|\nchar 3: |%-10c|\n", 'a', 'b', 'c');
	printf("char 1: |%c|\nchar 2: |%10c|\nchar 3: |%-10c|\n", 'a', 'b', 'c');

	ft_printf("d flag: |%-+30.20ld|\n", a);
	printf("d flag: |%-+30.20ld|\n", a);
	
	ft_printf("i flag 1: |%+7.5i|\ni flag 2: |%7.5i|\ni flag 3: |%+6i|\n", d, e, f);
	printf("i flag 1: |%+7.5i|\ni flag 2: |%7.5i|\ni flag 3: |%+6i|\n", d, e, f);
	
	ft_printf("octal 1: %o\noctal 2: |%10o|\noctal 3: |%-10o|\n", d, d, d);
	printf("octal 1: %o\noctal 2: |%10o|\noctal 3: |%-10o|\n", d, d, d);

	ft_printf("unsigned 0: |%u|\nunsigned 1: |%10u|\nunsigned 2: |%-10u|\n", g, h, i);
	printf("unsigned 0: |%u|\nunsigned 1: |%10u|\nunsigned 2: |%-10u|\n", g, h, i);
	//int	aft = (int)j;
	char	stmp[20];
	
	//int	pasta = 0xabcdef;
	long monster = 0xdeadbeef;

	ft_printf("sizeof pointer: |%5lu|\n", sizeof(str_ptr));
	printf("sizeof pointer: |%5lu|\n", sizeof(str_ptr));
	ft_printf("my hex: %p\n", str_ptr);
	ft_printf("my hex: %p\n", &monster);
	printf("there hex: |%-30p|\n", str_ptr);
	printf("there hex: %p\n", &monster);
	ft_printf("my hex: %lx\n", monster);
	printf("there hex: %lx\n", monster);
	// ft_printf("float: |%.35f|\n", j);
	// printf("float: |%20.35f|\n", j);
	ft_printf("|%10s|\n", stmp);
	ft_printf("int: |%10.6d|\n", e);
	ft_printf("int0: |%u|\nint1: |%u|\nint2: |%u|\n", g, h, i);
	printf("int0: |%u|\nint1: |%u|\nint2: |%u|\n", g, h, i);
	return (0);
}
