#include "../ft_printf_bonus.h"

char *ft_ptoa(void *ptr)
{
    unsigned long long addr;
    char *hex;
    char *result;

    addr = (unsigned long long)ptr;
    if (addr == 0)
        return (ft_strdup("0x0")); // O "(nil)" según el comportamiento que prefieras
    
    hex = ft_itoa_base(addr, 16, 0);
    if (!hex)
        return (NULL); // Error en la conversión
    
    result = ft_strjoin("0x", hex);
    free(hex); // Liberar memoria temporal
    
    return (result);
}

void print_ptr(t_flag *flags)
{
    void *ptr = va_arg(flags->args, void *);
    char *str = ptr ? ft_ptoa(ptr) : "(nil)";
    int len = ft_strlen(str);

    int padding = flags->width > len ? flags->width - len : 0;

    if (!flags->minus)
        while (padding-- > 0)
            write(1, " ", 1);

    write(1, str, len);

    if (flags->minus)
        while (padding-- > 0)
            write(1, " ", 1);

    if (ptr)
        free(str);
}
