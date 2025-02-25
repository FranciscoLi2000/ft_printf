#include "../ft_printf_bonus.h"

void parse_flag_space(t_flag *flags)
{
    if (flags->plus == 0)  // Si el flag '+' no está activo
        flags->space = 1;
}
