#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main()
{
    int x = 42;
    int n;
    ft_printf("%c\n", 'q');
    ft_printf("%s\n", "yufli");
    ft_printf("%i\n", INT_MIN);
    ft_printf("%d\n", INT_MAX);
    n = ft_printf("%u\n", UINT_MAX);
    ft_printf("%x\n", x);
    ft_printf("%X\n", x);
    ft_printf("%p\n", &x);
    ft_printf("%i%\n", x);
    ft_printf("%i\n", n);
    printf("%i\n", n);
    return (0);
}