#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_flags
{
    int     minus;
    int     zero;
    int     hash;
    int     plus;
    int     space;
    int     width;
    int     precision;
    // ... otros flags si es necesario
}   t_flags;

typedef struct s_print
{
    va_list args;
    int     tl;     // Total de caracteres impresos
    char    spec;   // Especificador actual (c, s, d, etc.)
    t_flags flags;  // Flags y parámetros
} t_print;

char	*ft_utoa(unsigned int n);
char	*ft_itoa_base(unsigned long long n, int base, int uppercase);
char	*ft_ptoa(void *ptr);
void	ft_parse_specifier(t_print *tab, char spec);
void    parse_flags(t_print *tab, const char *format, int *i);
void    apply_width(t_flags *flags, char **str);
void    apply_precision(t_flags *flags, char **str);
void    parse_zero(t_flags *flags);
void    parse_width(t_flags *flags, const char *format, int *i);
void    parse_width_star(t_flags *flags, va_list args);
void    parse_space(t_flags *flags);
void    parse_precision(t_flags *flags, const char *format, int *i, va_list args);
void    parse_plus(t_flags *flags);
void    parse_minus(t_flags *flags);
void    parse_hash(t_flags *flags);
void	print_char(t_print *tab);
void	print_str(t_print *tab);
void	print_int(t_print *tab);
void	print_uint(t_print *tab);
void	print_hex(t_print *tab, int uppercase);
void	print_ptr(t_print *tab);
int		ft_printf(const char *format, ...);

#endif
