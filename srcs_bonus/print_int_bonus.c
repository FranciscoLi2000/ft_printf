#include "../ft_printf_bonus.h"

void	print_int(t_print *tab)
{
	char	*str;
	int		num;

	num = va_arg(tab->args, int);
    // Aplicar flags: +, espacio, precisión, etc.
    if (tab->flags.plus && num >= 0)
        str = ft_strjoin("+", ft_itoa(num));
    else if (tab->flags.space && num >= 0)
        str = ft_strjoin(" ", ft_itoa(num));
    else
	    str = ft_itoa(num);
	// Aplicar ancho y alineación (ej: %-10d)
    apply_width(&tab->flags, &str);
	tab->tl += write(1, str, ft_strlen(str));
	free(str);
}