#include <unistd.h>
#include <signal.h>
#include "mini.h"
#include <stdlib.h>
#include <stdio.h>

struct t_str g_g;
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

void	mainfunction(int usersignal)
{
	if (usersignal == SIGUSR1)
		g_g.c = (g_g.c  << 1) + 1;
	else
		g_g.c  = (g_g.c  << 1);
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
