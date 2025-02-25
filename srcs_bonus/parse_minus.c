#include "../ft_printf_bonus.h"

void    parse_minus(t_flags *flags)
{
    flags->minus = 1;
    if (flags->zero) // '-' 优先级高于 '0'
        flags->zero = 0;
}