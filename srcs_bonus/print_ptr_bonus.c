#include "../ft_printf_bonus.h"

char	*ft_ptoa(void *ptr)
{
	unsigned long long	addr;
	char				*hex;
	char				*result;

	addr = (unsigned long long)ptr;
	if (addr == 0)
		return (ft_strdup("(nil)"));
	hex = ft_itoa_base(addr, 16, 0);
	result = ft_strjoin("0x", hex);
	free(hex);
	return (result);
}

void print_ptr(t_print *tab)
{
    char            *str;
    void            *ptr = va_arg(tab->args, void *);

    // Convertir la dirección a cadena hexadecimal
    str = ft_itoa_base((unsigned long long)ptr, 16, 0); // Usa tu función ft_itoa_base
    // Añadir el prefijo "0x" (obligatorio para punteros)
    char *new_str = ft_strjoin("0x", str);
    free(str);
    str = new_str;
    // Aplicar precisión (si es necesario)
    if (tab->flags.precision >= 0)
        apply_precision(&tab->flags, &str);
    // Aplicar ancho y alineación (si es necesario)
    if (tab->flags.width > 0)
        apply_width(&tab->flags, &str);
    // Imprimir la cadena final
    tab->tl += write(1, str, ft_strlen(str));
    // Liberar memoria
    free(str);
}