#include "../ft_printf_bonus.h"

void parse_flag_zero(t_flag *flags)
{
    if (flags->minus == 0)  // Si el flag '-' no está activo
        flags->zero = 1;
}
