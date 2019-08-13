#include "includes/ft_printf.h"

int		main(void)
{
	char str0[25] = "string: %s string2: %s";
	char str1[29] = "string: %10s string2: %25s";

	ft_printf(str0, "hello", "goodbye");
	ft_printf(str1, "hello", "goodbye");
	return (0);
}
