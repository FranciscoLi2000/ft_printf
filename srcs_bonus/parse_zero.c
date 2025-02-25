#include "../ft_printf_bonus.h"

void    parse_zero(t_flags *flags)
{
    if (!flags->minus) // 仅在无 '-' 时生效
        flags->zero = 1;
}