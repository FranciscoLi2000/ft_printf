#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	x;

	x = 255;
	ft_printf("Single character: %c\n", 'A');
	ft_printf("String: %s\n", "42 Barcelona");
	ft_printf("integer: %i and %d%%\n", 42, 50);
	ft_printf("unsigned int: %u\n", 123);
	ft_printf("pointer: %p\n", &x);
	ft_printf("hex: %x\t%X\n", x, x);
	return (0);
}
