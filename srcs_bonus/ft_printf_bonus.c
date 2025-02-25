#include "../ft_printf_bonus.h"

void init_flags(t_flag *flags)
{
    flags->minus = 0;
    flags->zero = 0;
    flags->hash = 0;
    flags->plus = 0;
    flags->space = 0;
    flags->width = 0;
    flags->precision = -1; // -1 indica que no se ha especificado precisión
}

void    parse_flags(t_flag *flags, const char *format, int *i, va_list args)
{
    while (format[*i] && (ft_strchr("#-+ .0123456789*", format[*i])))
    {
        if (format[*i] == '#')
            parse_flag_hash(flags);
        else if (format[*i] == '-')
            parse_flag_minus(flags);
        else if (format[*i] == '+')
            parse_flag_plus(flags);
        else if (format[*i] == ' ')
            parse_flag_space(flags);
        else if (format[*i] == '.')
            parse_flag_precision(flags, format, i, args);
        else if (ft_isdigit(format[*i]))
            parse_flag_width(flags, format, i);
        else if (format[*i] == '*')
            parse_width_star(flags, args);
        (*i)++;
    }
}

void ft_parse_specifier(t_flag *flags, char spec)
{
    if (spec == 'c')
        print_char(flags);
    else if (spec == 's')
        print_str(flags);
    else if (spec == 'p')
        print_ptr(flags);
    else if (spec == 'd' || spec == 'i')
        print_int(flags);
    else if (spec == 'u')
        print_uint(flags);
    else if (spec == 'x')
        print_hex(flags, 0);
    else if (spec == 'X')
        print_hex(flags, 1);
    else if (spec == '%')
        flags->tl += write(1, "%", 1);
    else
    {
        flags->tl += write(1, "%", 1);
        flags->tl += write(1, &spec, 1);
    }
}

int ft_printf(const char *format, ...)
{
    t_flag flags;
    int     i;

    if (!format)
        return (-1);

    va_start(flags.args, format);
    flags.tl = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                break;
            init_flags(&flags); // ¡Importante! Reiniciar los flags para cada conversión
            parse_flags(&flags, format, &i, flags.args); // Pasar flags.args como 4º parámetro
            if (format[i]) // Verificar que no hemos llegado al final
                ft_parse_specifier(&flags, format[i]);
        }
        else
            flags.tl += write(1, &format[i], 1);
        i++;
    }

    va_end(flags.args);
    return (flags.tl);
}