#include "../ft_printf_bonus.h"

static unsigned int	num_len_base(unsigned long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long long n, int base, int uppercase)
{
	char	*digits;
	char	*str;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = num_len_base(n, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	len--;
	while (n > 0)
	{
		str[len] = digits[n % base];
		n /= base;
		len--;
	}
	return (str);
}

void print_hex(t_flag *flags, int uppercase)
{
    unsigned int n = va_arg(flags->args, unsigned int);
    char *prefix = (flags->hash && n) ? (uppercase ? "0X" : "0x") : "";
    char *str = ft_itoa_base(n, 16, uppercase);
    int len = ft_strlen(str) + ft_strlen(prefix);

    int padding = flags->width > len ? flags->width - len : 0;

    if (!flags->minus)
        while (padding-- > 0)
            write(1, flags->zero ? "0" : " ", 1);

    write(1, prefix, ft_strlen(prefix));
    write(1, str, ft_strlen(str));

    if (flags->minus)
        while (padding-- > 0)
            write(1, " ", 1);

    free(str);
}
