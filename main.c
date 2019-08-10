#include "includes/ft_printf.h"

int		main(void)
{
	char str[25] = "string: %s string2: %s";

	ft_printf(str, "hello", "goodbye");
	return (0);
}
