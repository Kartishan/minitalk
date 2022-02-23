/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:03:43 by pwildcat          #+#    #+#             */
/*   Updated: 2022/02/23 12:03:46 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "mini.h"
#include <stdlib.h>
#include <stdio.h>

struct s_str	g_g;

void	mainfunction(int usersignal)
{
	if (usersignal == SIGUSR1)
	{
		g_g.c = (g_g.c << 1) + 1;
	}
	else
	{
		g_g.c = (g_g.c << 1);
	}
	g_g.i++;
	if (g_g.i == 8)
	{
		write(1, &g_g.c, 1);
		g_g.i = 0;
		g_g.c = 0;
	}
}

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	mainfunction(sig);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s;

	s.sa_flags = SA_SIGINFO;
	g_g.c = 0;
	g_g.i = 0;
	s.sa_sigaction = handler;
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	pid = getpid();
	printf("%d\n", pid);
	while (1)
	{
	}
}
