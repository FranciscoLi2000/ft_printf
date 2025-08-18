#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*res;
	int	i;

	i = 0;
	if (!src)
		return (NULL);
	len = ft_strlen(src);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
