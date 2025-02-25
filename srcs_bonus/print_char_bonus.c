#include "../ft_printf_bonus.h"

void print_char(t_flag *flags)
{
    char c = va_arg(flags->args, int);
    int padding = flags->width > 1 ? flags->width - 1 : 0;

    if (!flags->minus)
        while (padding-- > 0)
            write(1, " ", 1);
    
    write(1, &c, 1);

    if (flags->minus)
        while (padding-- > 0)
            write(1, " ", 1);

    flags->tl++;  // Aumentar la cantidad de caracteres escritos
}
