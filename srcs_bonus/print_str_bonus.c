#include "../ft_printf_bonus.h"

void    print_str(t_print *tab)
{
    char *str = va_arg(tab->args, char *); // Obtener la cadena
    int width = tab->flags.width;         // Ancho de campo
    int precision = tab->flags.precision; // Precisión
    int len = 0;                          // Longitud de la cadena
    char pad_char = ' ';                  // Carácter de relleno (espacio por defecto)

    // Si la cadena es NULL, usar "(null)"
    if (!str)
        str = "(null)";
    // Calcular la longitud de la cadena (teniendo en cuenta la precisión)
    len = ft_strlen(str);
    if (precision >= 0 && precision < len)
        len = precision;
    // Si se especifica '0' y no hay '-', rellenar con ceros
    if (tab->flags.zero && !tab->flags.minus)
        pad_char = '0';
    // Imprimir relleno a la izquierda (si no hay '-')
    if (!tab->flags.minus && width > len)
    {
        while (width-- > len)
            tab->tl += write(1, &pad_char, 1);
    }
    // Imprimir la cadena (hasta la longitud especificada por la precisión)
    tab->tl += write(1, str, len);
    // Imprimir relleno a la derecha (si hay '-')
    if (tab->flags.minus && width > len)
    {
        while (width-- > len)
            tab->tl += write(1, &pad_char, 1);
    }
}