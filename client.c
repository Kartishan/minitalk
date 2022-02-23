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

#include <unistd.h>
#include "mini.h"
#include <stdio.h>

struct s_str	g_g;

void	handlerforsignal(int signal)
{
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

int	clientfunction(int pid, char *s)
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
		clientfunction(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}
