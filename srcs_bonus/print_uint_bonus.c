#include "../ft_printf_bonus.h"

static unsigned int	num_len_unsigned(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	num;
	unsigned int	len;
	char			*str;

	len = num_len_unsigned(n);
	num = n;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	len--;
	while (num > 0)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

void apply_precision(t_flags *flags, char **str)
{
    int len = ft_strlen(*str);
    int precision = flags->precision;

    if (precision > len)
    {
        char *new_str = malloc(precision + 1);
        if (!new_str)
            return ;
        ft_memset(new_str, '0', precision - len);
        ft_strlcpy(new_str + (precision - len), *str, len + 1);
        free(*str);
        *str = new_str;
    }
}

void apply_width(t_flags *flags, char **str)
{
    int len = ft_strlen(*str);
    int width = flags->width;

    if (width > len)
    {
        char *new_str = malloc(width + 1);
        if (!new_str)
            return ;
        if (flags->minus)
        {
            ft_strlcpy(new_str, *str, len + 1);
            ft_memset(new_str + len, ' ', width - len);
        }
        else
        {
            ft_memset(new_str, (flags->zero && !flags->minus) ? '0' : ' ', width - len);
            ft_strlcpy(new_str + (width - len), *str, len + 1);
        }
        free(*str);
        *str = new_str;
    }
}

void print_uint(t_print *tab)
{
    char            *str;
    unsigned int    num = va_arg(tab->args, unsigned int);

    // Convertir el número a cadena
    str = ft_utoa(num); // Usa tu función ft_utoa para unsigned int
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