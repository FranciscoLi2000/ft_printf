#include "../ft_printf_bonus.h"

void    print_char(t_print *tab)
{
    char c = va_arg(tab->args, int); // Obtener el carácter
    int width = tab->flags.width;    // Ancho de campo
    int len = 1;                    // Longitud del carácter (siempre 1)
    char pad_char = ' ';            // Carácter de relleno (espacio por defecto)

    // Si se especifica '0' y no hay '-', rellenar con ceros
    if (tab->flags.zero && !tab->flags.minus)
        pad_char = '0';
    // Imprimir relleno a la izquierda (si no hay '-')
    if (!tab->flags.minus && width > len)
    {
        while (width-- > len)
            tab->tl += write(1, &pad_char, 1);
    }
    // Imprimir el carácter
    tab->tl += write(1, &c, 1);
    // Imprimir relleno a la derecha (si hay '-')
    if (tab->flags.minus && width > len)
    {
        while (width-- > len)
            tab->tl += write(1, &pad_char, 1);
    }
}