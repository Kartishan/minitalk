/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:02:46 by pwildcat          #+#    #+#             */
/*   Updated: 2022/02/23 12:04:04 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

struct s_str	g_g;

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

void	handlerforsignal(int signal)
{
	usleep(30);
	signal = 1;
	if (g_g.bit < 0)
	{
		g_g.bit = 7;
		g_g.i++;
	}
	if (g_g.str[g_g.i] == '\0')
		return ;
	if ((g_g.str[g_g.i] >> g_g.bit) & 1)
	{
		g_g.bit--;
		kill(g_g.pid, SIGUSR1);
	}
	else
	{
		g_g.bit--;
		kill(g_g.pid, SIGUSR2);
	}
}

int	clientfunction(int pid)
{
	g_g.pid = pid;
	kill(getpid(), SIGUSR1);
	while (g_g.str[g_g.i] != '\0')
		;
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	s;

	s.sa_handler = handlerforsignal;
	g_g.str = argv[2];
	g_g.i = 0;
	g_g.bit = 7;
	if (argc <= 2)
		write(1, "use ./client {pid} {messege}\n", 29);
	else
	{
		sigaction(SIGUSR1, &s, NULL);
		clientfunction(ft_atoi(argv[1]));
	}
	return (0);
}
