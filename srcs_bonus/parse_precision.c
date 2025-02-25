#include "../ft_printf_bonus.h"

// 解析精度（如 ".5" 或 ".*"）
void parse_precision(t_flags *flags, const char *format, int *i, va_list args)
{
    (*i)++; // 跳过 '.'
    if (format[*i] == '*')
    {
        flags->precision = va_arg(args, int);
        (*i)++;
    }
    else
    {
        flags->precision = ft_atoi(&format[*i]);
        while (ft_isdigit(format[*i]))
            (*i)++;
    }
}