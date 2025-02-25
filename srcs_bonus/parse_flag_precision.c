#include "../ft_printf_bonus.h"

void parse_flag_precision(t_flag *flags, const char *format, int *i, va_list args)
{
    (*i)++;
    if (format[*i] == '*')
    {
        flags->precision = va_arg(args, int);
        if (flags->precision < 0) flags->precision = -1;
        (*i)++;
    }
    else
    {
        flags->precision = 0;
        while (ft_isdigit(format[*i]))
        {
            flags->precision = (flags->precision * 10) + (format[*i] - '0');
            (*i)++;
        }
    }
}
