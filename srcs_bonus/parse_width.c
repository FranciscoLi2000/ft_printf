#include "../ft_printf_bonus.h"

// 解析静态宽度（如 "10"）
void parse_width(t_flags *flags, const char *format, int *i)
{
    flags->width = ft_atoi(&format[*i]);
    while (ft_isdigit(format[*i]))
        (*i)++;
}

// 解析动态宽度（如 "*"）
void parse_width_star(t_flags *flags, va_list args)
{
    flags->width = va_arg(args, int);
    if (flags->width < 0) {
        flags->minus = 1; // 负宽度等价于 '-' 标志
        flags->width = -flags->width;
    }
}