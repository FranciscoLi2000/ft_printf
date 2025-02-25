#include "../ft_printf_bonus.h"

void parse_flag_plus(t_flag *flags)
{
    flags->plus = 1;
    flags->space = 0;  // El flag ' ' no tiene efecto si '+' está activado
}
