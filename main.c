#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main()
{
    int x = 42;

    ft_printf("%c\n", 'W');
    printf("%c\n", 'W');
    ft_printf("%s\n", NULL);
    
    ft_printf("%d\t%i\n", INT_MAX, INT_MIN);
    printf("%d\t%i\n", INT_MAX, INT_MIN);
    ft_printf("%u\t%u\n", UINT_MAX, 0);
    printf("%u\t%u\n", UINT_MAX, 0);
    ft_printf("%x\t%X\n", 0, 0XFFFFFFFF);
    printf("%x\t%X\n", 0, 0XFFFFFFFF);
    ft_printf("%p\t%p\n", NULL, &x);
    printf("%p\t%p\n", NULL, &x);
    return (0);
}