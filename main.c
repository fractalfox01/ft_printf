#include "includes/ft_printf.h"

int		main(int ac, char **av)
{
	char str[25] = "string: %s string2: %s";

	ft_printf(str, "hello", "goodbye");
	return (0);
}
