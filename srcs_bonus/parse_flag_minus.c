#include "../ft_printf_bonus.h"

void parse_flag_minus(t_flag *flags)
{
    flags->minus = 1;
    flags->zero = 0;
}