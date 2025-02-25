#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

// Única estructura para manejar todo en el bonus
typedef struct s_flag {
    va_list args;   // Lista de argumentos
    int     tl;     // Total de caracteres escritos

    // Flags
    int     minus;
    int     zero;
    int     hash;
    int     plus;
    int     space;
    int     width;
    int     precision;
} t_flag;

void    init_flags(t_flag *flags);
// Prototipos de funciones
void    parse_flags(t_flag *flags, const char *format, int *i, va_list args);
void    ft_parse_specifier(t_flag *flags, char spec);
int     ft_printf(const char *format, ...);
char	*ft_itoa_base(unsigned long long n, int base, int uppercase);

// Funciones de impresión
void	print_char(t_flag *flags);
void	print_str(t_flag *flags);
void	print_int(t_flag *flags);
void	print_uint(t_flag *flags);
void	print_hex(t_flag *flags, int uppercase);
void	print_ptr(t_flag *flags);

void parse_flag_hash(t_flag *flags);
void parse_flag_minus(t_flag *flags);
void parse_flag_plus(t_flag *flags);
void parse_flag_precision(t_flag *flags, const char *format, int *i, va_list args);
void parse_flag_space(t_flag *flags);
void parse_flag_width(t_flag *flags, const char *format, int *i);
void parse_width_star(t_flag *flags, va_list args);
void parse_flag_zero(t_flag *flags);

#endif

