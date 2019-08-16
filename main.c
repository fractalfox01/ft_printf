#include "includes/ft_printf.h"

int		main(void)
{
	char str0[25] = "string: %s string2: %s\n";
	char str1[29] = "string: %10s string2: %25s\n";
	//char str2[25] = "number: %d number2: %d\n";
	char str3[31] = "string: %-10s string2: %-25s\n";
	char str4[44] = "char1: |%10c| char2: |%-10c|\nLEFTOVERS!!!\n";
	
	ft_printf("Mine:\n");
	ft_printf(str0, "hello", "goodbye");
	//ft_putchar('\n');
	ft_printf(str1, "hello", "goodbye");
	//ft_printf(str2, 42, -99);
	ft_printf(str3, "hello", "goodbye");

	ft_printf(str4, 'a', 'b');
	//ft_putchar('\n');
	printf("\nTheres:\n");
	printf(str0, "hello", "goodbye");
	//printf("\n");
	printf(str1, "hello", "goodbye");
	printf(str3, "hello", "goodbye");
	printf(str4, 'a', 'b');
	//printf("\n");
	return (0);
}
