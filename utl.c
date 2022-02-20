#include "mini.h"
#include <stdlib.h>

int	ft_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long int			c;
	unsigned long int	i;
	int					n;

	c = 0;
	n = 1;
	i = ft_space(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c *= 10;
		c += (str[i] - '0');
		if (c > 2147483647 && n == 1)
			return (-1);
		if (c > 2147483648 && n == -1)
			return (0);
		i++;
	}
	return ((int)c * n);
}

int	ft_count(long int nan)
{
	int	i;

	i = 0;
	while (nan != 0)
	{
		nan /= 10;
		i++;
	}
	return (i);
}

char	*ft_putnbr(long int n, char *p, int negative)
{
	long int	k;
	long int	power;
	long int	i;

	i = 0;
	if (negative == -1)
	{
		p[i] = '-';
		i++;
	}
	power = n;
	k = 1;
	while (power > 9)
	{
		k = k * 10;
		power = power / 10;
	}
	while (k != 0)
	{
		p[i] = (n / k % 10) + '0';
		k /= 10;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	long int			i;
	char				*p;
	long int			nan;
	long int			negative;

	i = 0;
	nan = n;
	negative = 0;
	i = ft_count(nan);
	if (nan < 0)
	{
		nan = nan * -1;
		negative = -1;
		i++;
	}
	if (nan == 0)
		p = malloc(sizeof(char) + 1);
	else
		p = malloc(i + 1);
	if (p == NULL)
		return ((void *)0);
	p = ft_putnbr(nan, p, negative);
	return (p);
}
