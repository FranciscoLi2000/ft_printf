#include "../ft_printf_bonus.h"

void print_int(t_flag *flags)
{
    int n = va_arg(flags->args, int);
    char *str = ft_itoa(n);
    int len = ft_strlen(str);
    
    int padding = flags->width > len ? flags->width - len : 0;

    if (!flags->minus)
        while (padding-- > 0)
            write(1, flags->zero ? "0" : " ", 1);

    write(1, str, len);

    if (flags->minus)
        while (padding-- > 0)
            write(1, " ", 1);

    free(str);
}
