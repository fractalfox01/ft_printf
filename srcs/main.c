#include <limits.h>
#include <unistd.h>
#include "../includes/ft_printf.h"

int main(void)
{
    //int *p;
    long int a = -42;

    //*p = a;
    ft_printf("%ld\n", a);
    // system("leaks ft_printf");
    return (0);
}