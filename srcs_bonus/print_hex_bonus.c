#include "../ft_printf_bonus.h"

static unsigned int	num_len_base(unsigned long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long long n, int base, int uppercase)
{
	char	*digits;
	char	*str;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = num_len_base(n, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len--] = digits[n % base];
		n /= base;
	}
	return (str);
}

void print_hex(t_print *tab, int uppercase)
{
    char            *str;
    unsigned int    num = va_arg(tab->args, unsigned int);

    // Convertir el número a cadena hexadecimal
    str = ft_itoa_base(num, 16, uppercase); // Usa tu función ft_itoa_base
    // Aplicar el flag '#' para prefijo (0x o 0X)
    if (tab->flags.hash && num != 0)
    {
        char *prefix = uppercase ? "0X" : "0x";
        char *new_str = ft_strjoin(prefix, str);
        free(str);
        str = new_str;
    }
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