#include "../ft_printf_bonus.h"

static unsigned int	num_len_unsigned(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	num;
	unsigned int	len;
	char			*str;

	len = num_len_unsigned(n);
	num = n;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	len--;
	while (num > 0)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

void print_uint(t_flag *flags)
{
    unsigned int n = va_arg(flags->args, unsigned int);
    char *str = ft_utoa(n);
    int len = ft_strlen(str);

    int padding = flags->width > len ? flags->width - len : 0;

    if (!flags->minus)
        while (padding-- > 0)
            write(1, flags->zero ? "0" : " ", 1);

    write(1, str, len);

    if (flags->minus)
        while (padding-- > 0)
            write(1, " ", 1);

    free(str);
}
