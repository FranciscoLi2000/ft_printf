#include "ft_printf.h"

int main()
{
    int x;

    x = 42;
    ft_printf("Hell%c, %s\n", 'O', "Yufeng");
    ft_printf("%i\t%d\t%u\n%p\n", x, x, (unsigned int)x, &x);
    ft_printf("%x\t%X\n", (unsigned int)x, (unsigned int)x);
    ft_printf("%%\n");
    return (0);
}