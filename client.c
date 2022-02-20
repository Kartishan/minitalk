#include <unistd.h>
#include "mini.h"
#include <stdio.h>

struct t_str	g_g;

void	handlerforsignal(int signal)
{
	if (g_g.str[g_g.i] == '\0')
		return ;
	g_g.bit--;
	if (g_g.bit < 0)
	{
		g_g.bit = 8;
		g_g.i++;
	}
	if ((g_g.str[g_g.i] >> g_g.bit) & 1)
	{
		kill(g_g.pid, SIGUSR1);
	}
	else
	{
		kill(g_g.pid, SIGUSR2);
	}

}

int	clientfunction(int pid, char *s)
{
	g_g.pid = pid;
	int i = 0;
	kill(getpid(), SIGUSR1);
	while (g_g.str[g_g.i] != '\0')
	{
	}
	return(0);
}

int	main(int argc, char **argv)
{
		
	struct sigaction	s;

	s.sa_handler = handlerforsignal;
	g_g.str = argv[2];
	g_g.i = 0;
	g_g.bit = 8;
	printf("%d\n", getpid());
	if (argc <= 2)
		write(1, "use ./client {pid} {messege}\n", 29);
	else
	{
		sigaction(SIGUSR1, &s, NULL);
		clientfunction(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}