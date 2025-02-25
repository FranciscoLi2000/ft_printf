#include "../ft_printf_bonus.h"

void parse_flag_width(t_flag *flags, const char *format, int *i)
{
    flags->width = 0;
    while (ft_isdigit(format[*i]))
    {
        flags->width = (flags->width * 10) + (format[*i] - '0');
        (*i)++;
    }
}

void parse_width_star(t_flag *flags, va_list args)
{
    flags->width = va_arg(args, int);
    if (flags->width < 0)
    {
        flags->minus = 1;
        flags->zero = 0;
        flags->width = -flags->width;
    }
}
