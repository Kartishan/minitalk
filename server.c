#include <unistd.h>
#include <signal.h>
#include "mini.h"
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

static void	reversetranslate(char *str)
{
	long int	pow;
	char		c;
	long int	i;

	i = ft_strlen(str);
	while (i != 0)
	{
		c += pow * (str[i] - '0');
		pow =pow * 2;
		i--;
	}
	write(1, &c, 1);
}

static void	mainfunction(int usersignal)
{
	static int	i;
	static char	buf[8];

	if (buf == NULL)
	{
		buf[0] = ' ';
		i = 0;
	}
	i++;
	if (usersignal == SIGUSR1)
		buf[i] += '1';
	else
		buf[i] += '0';
	if (i == 7)
	{
		reversetranslate(buf);
		buf == NULL;
	}
}

int	main(void)
{
	int	pid;

	pid = getpgid(pid);
	printf("%d\n", pid);
	while (1)
	{
		signal(SIGUSR1, mainfunction);
		signal(SIGUSR2, mainfunction);
	}
}
