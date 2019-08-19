#include "includes/ft_printf.h"

int		main(void)
{
	//char str0[19] = "string: |%6.3s|\n";
	// char str1[29] = "string: %10s string2: %25s\n";
	// //char str2[25] = "number: %d number2: %d\n";
	// char str3[31] = "string: %-10s string2: %-25s\n";
	// char str4[44] = "char1: |%+10c| char2: |%10c|\nLEFTOVERS!!!\n";
	// char str5[40] = "int1: |%+10d| int2: |%-10d| int3: |%d|\n";
	ft_printf("Mine:\n");
	ft_printf("string0: |%15.4s|\nstring1: |%-6s|\nstring2: |%6s|\nstring3: |%6.3s|\n", "waffle", "hello", "world", "bye!!");
	ft_printf("int0: |%+10.6d|\nint1: |%10.6d|\nint2: |%+6d|\n", 42, -42, 127);

	printf("\nThiers:\n");
	printf("string0: |%15.4s|\nstring1: |%-6s|\nstring2: |%6s|\nstring3: |%6.3s|\n", "waffle", "hello", "world", "bye!!");
	printf("int0: |%+10.6d|\nint1: |%10.6d|\nint2: |%+6d|\n", 42, -42, 127);
	return (0);
}
