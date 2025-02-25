#include "../ft_printf_bonus.h"

void print_str(t_flag *flags)
{
    char *str = va_arg(flags->args, char *);
    int len = str ? ft_strlen(str) : 6;  // Si NULL, "(null)" (longitud = 6)
    
    if (!str)
        str = "(null)";

    if (flags->precision >= 0 && flags->precision < len)  
        len = flags->precision;  // Cortar la cadena según precisión
    
    int padding = flags->width > len ? flags->width - len : 0;

    if (!flags->minus)
        while (padding-- > 0)
            write(1, " ", 1);
    
    write(1, str, len);

    if (flags->minus)
        while (padding-- > 0)
            write(1, " ", 1);
}
