#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int ft_printf(const char *format, ...);
int handle_conversion(const char **format, va_list ap);
int print_char(int c);
int print_string(const char *s);
int print_int(int n);
int print_pointer(void *ptr);
int print_unsigned(unsigned int n);
int print_hex(unsigned int n, int uppercase);
int ft_strlen(const char *str);

#endif
