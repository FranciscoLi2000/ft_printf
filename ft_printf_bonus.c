#include "ft_printf_bonus.h"

t_flags init_flags(void)
{
    t_flags flags;

    flags.width = -1;      // -1 indica que no se especificó
    flags.precision = -1;  // -1 indica que no se especificó
    flags.minus = 0;
    flags.zero = 0;
    flags.hash = 0;
    flags.space = 0;
    flags.plus = 0;
    return (flags);
}

int  ft_strlen(const char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

void parse_flags(const char **format, t_flags *flags)
{
    while (**format == '-' || **format == '0' || **format == '#' || **format == ' ' || **format == '+')
    {
        if (**format == '-')
            flags->minus = 1;
        else if (**format == '0')
            flags->zero = 1;
        else if (**format == '#')
            flags->hash = 1;
        else if (**format == ' ')
            flags->space = 1;
        else if (**format == '+')
            flags->plus = 1;
        (*format)++;
    }
}

int handle_conversion(const char **format, va_list ap)
{
    char    specifier;
    int     uppercase;

    specifier = **format;
    (*format)++;
    if (specifier == '%')// Esta parte maneja bien todos los conversores requeridos
        return (write(1, "%", 1));
    if (specifier == 'c')
        return (print_char(va_arg(ap, int)));
    if (specifier == 's')
        return (print_string(va_arg(ap, char *)));
    if (specifier == 'd' || specifier == 'i')
        return (print_int(va_arg(ap, int)));
    if (specifier == 'p')
        return (print_pointer(va_arg(ap, void *)));
    if (specifier == 'u')
        return (print_unsigned(va_arg(ap, unsigned int)));
    if (specifier == 'x' || specifier == 'X')
    {
        uppercase = (specifier == 'X');
        return (print_hex(va_arg(ap, unsigned int), uppercase));
    }
    write(1, "%", 1);// El manejo de especificadores inválidos está bien
    write(1, &specifier, 1);
    return (2);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     count;

    if (!format)// Buen chequeo inicial del formato
        return (-1);
    count = 0;
    va_start(ap, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (!*format)  // Excelente chequeo de terminación inesperada
                break ;
            count += handle_conversion(&format, ap);
        }
        else
        {
            write(1, format, 1);
            format++;
            count++;
        }
    }
    va_end(ap);
    return (count);
}
