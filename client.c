#include <unistd.h>
#include "mini.h"
#include <stdio.h>

int	translator(int pid, char c)
{
	int	i;

	i = 128;
	while (i >= 1)
	{
		if (i & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		i /= 2;
	}
	return (0);
}
int	clientfunction(int pid, char *s)
{
	int	i;

	i = 0;
	while (s[i] >= 32 && s[i] <= 126)
	{
		if (translator(pid, s[i]))
			return (1);
		i++;
	}
	usleep(1000);
	return(0);
}

int	main(int argc, char **argv)
{
	if (argc <= 2)
		write(1, "use ./client {pid} {messege}\n", 29);
	else
		clientfunction(ft_atoi(argv[1]), argv[2]);
	return (0);
}