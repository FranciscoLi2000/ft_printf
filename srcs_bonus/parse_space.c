#include "../ft_printf_bonus.h"

void parse_space(t_flags *flags)
{
    if (!flags->plus) // 仅在无 '+' 时生效
        flags->space = 1;
}