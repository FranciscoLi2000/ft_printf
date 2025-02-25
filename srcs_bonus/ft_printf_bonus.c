#include "../ft_printf_bonus.h"

void parse_flags(t_print *tab, const char *format, int *i)
{
    // Reiniciar flags para cada nuevo especificador
    tab->flags = (t_flags){0};

    while (format[*i])
    {
        if (format[*i] == '-')
            parse_minus(&tab->flags);
        else if (format[*i] == '0')
            parse_zero(&tab->flags);
        else if (format[*i] == '#')
            parse_hash(&tab->flags);
        else if (format[*i] == '+')
            parse_plus(&tab->flags);
        else if (format[*i] == ' ')
            parse_space(&tab->flags);
        else if (format[*i] == '.')
            parse_precision(tab, format, i); // Ejemplo: .5
        else if (ft_isdigit(format[*i]) || format[*i] == '*')
            parse_width(tab, format, i);     // Ejemplo: 10 o *
        else
            break ;
        (*i)++;
    }
}

void	ft_parse_specifier(t_print *tab, char spec)
{
	if (spec == 'c')
		print_char(tab);
	else if (spec == 's')
		print_str(tab);
	else if (spec == 'p')
		print_ptr(tab);
	else if (spec == 'd' || spec == 'i')
		print_int(tab);
	else if (spec == 'u')
		print_uint(tab);
	else if (spec == 'x')
		print_hex(tab, 0);
	else if (spec == 'X')
		print_hex(tab, 1);
	else if (spec == '%')
		tab->tl += write(1, "%", 1);
	else
	{
		tab->tl += write(1, "%", 1);
		tab->tl += write(1, &spec, 1);
	}
}

int ft_printf(const char *format, ...)
{
    t_print tab;
    int     i;

    va_start(tab.args, format);
    tab.tl = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                break ;
            parse_flags(&tab, format, &i);  // Analizar flags aquí
            ft_parse_specifier(&tab, format[i]); // Luego procesar el especificador
        }
        else
            tab.tl += write(1, &format[i], 1);
        i++;
    }
    va_end(tab.args);
    return (tab.tl);
}
