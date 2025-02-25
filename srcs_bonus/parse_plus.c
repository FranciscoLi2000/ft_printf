#include "../ft_printf_bonus.h"

void parse_plus(t_flags *flags)
{
    flags->plus = 1;
    if (flags->space) // '+' 优先级高于 ' '
        flags->space = 0;
}
