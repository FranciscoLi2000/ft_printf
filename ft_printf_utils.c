#include "ft_printf.h"

int print_char(int c)
{
    return (write(1, &c, 1));
}

int print_string(const char *s)
{
    if (!s)
        return (write(1, "(null)", 6));
    return (write(1, s, ft_strlen(s)));
}

int print_int(int n)
{
    char    c;
    int     count;

    count = 0;
    if (n == -2147483648)
        return (write(1, "-2147483648", 11));
    if (n < 0)
    {
        count += write(1, "-", 1);
        n = -n;
    }
    if (n > 9)
        count += print_int(n / 10);
    c = (n % 10) + '0';
    count += write(1, &c, 1);
    return (count);
}

// Función auxiliar para manejar unsigned long
static int print_hex_long(unsigned long n)
{
    char    c;
    int     count;
    char    *hex;
    
    hex = "0123456789abcdef";  // Para punteros usamos minúsculas por convención
    count = 0;
    if (n > 15)
        count += print_hex_long(n / 16);
    c = hex[n % 16];
    count += write(1, &c, 1);
    return (count);
}
int print_pointer(void *ptr)
{
    int             count;
    unsigned long   address;
    
    // Primero imprimimos el prefijo
    count = write(1, "0x", 2);
    // Convertimos el puntero a unsigned long para manejarlo
    address = (unsigned long)ptr;
    // Si el puntero es NULL, manejamos este caso especial
    if (address == 0)
        return (count + write(1, "(nil)", 5));
    // Usamos una función auxiliar para imprimir el valor hexadecimal
    count += print_hex_long(address);
    return (count);
}

int print_unsigned(unsigned int n)
{
    char    c;
    int     count;
    
    count = 0;
    if (n > 9)
        count += print_unsigned(n / 10);
    c = (n % 10) + '0';
    count += write(1, &c, 1);
    return (count);
}

int print_hex(unsigned int n, int uppercase)
{
    char    *hex;
    char    c;
    int         count;

    // Definimos los caracteres hexadecimales que usaremos
    // Podemos elegir entre minúsculas o mayúsculas según el parámetro uppercase
    if (n == 0) 
        return (write(1, "0", 1));
    if (uppercase)
        hex = "0123456789ABCDEF";
    else
        hex = "0123456789abcdef";
    count = 0;
    if (n > 15)  // En lugar de 9, comparamos con 15 (porque hex es base 16)
        count += print_hex(n / 16, uppercase);  // Dividimos por 16 en lugar de 10
    // Usamos el resto para indexar en nuestra string de caracteres hex
    c = hex[n % 16];  // Esto convierte automáticamente 10-15 a a-f o A-F
    count += write(1, &c, 1);
    return (count);
}
