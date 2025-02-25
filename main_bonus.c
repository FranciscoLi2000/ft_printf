#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main()
{
    int x = 42;
    int n;
    ft_printf("%-010c\n", 'q');
    ft_printf("%023.2s\n", "yufli");
    ft_printf("%.6i\n", INT_MIN);
    ft_printf("%+  d\n", INT_MAX);
    n = ft_printf("%3.4u\n", UINT_MAX);
    ft_printf("%#x\n", x);
    ft_printf("%#X\n", x);
    ft_printf("%p\n", &x);
    ft_printf("%*i%\n", x);
    ft_printf("%i\n", n);
    printf("%i\n", n);
    return (0);
}