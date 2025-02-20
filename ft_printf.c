#include "ft_printf.h"
/* 必须部分（Obligatoria）
1. 基本结构
主函数ft_printf遍历格式字符串，处理普通字符和转换说明符（%c, %s, %p, %d, %i, %u, %x, %X, %%）。
使用va_list处理可变参数，逐个字符输出。

2. 转换处理函数
%c：直接输出字符。
%s：输出字符串，处理NULL为"(null)"。
%p：输出指针地址（0x前缀 + 十六进制小写）。
%d/%i：有符号十进制转换。
%u：无符号十进制转换。
%x/%X：十六进制转换（小写/大写）。
%%：输出%。

3. 数值转换工具函数
实现itoa（有符号）、utoa（无符号）、ptrtoa（指针地址）等函数，避免使用标准库函数。

4. Makefile
编译生成静态库libftprintf.a，包含必须的.c文件，使用ar命令打包。*/
int  ft_strlen(const char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
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
