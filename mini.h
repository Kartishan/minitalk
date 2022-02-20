#ifndef MINI_H
# define MINI_H

#include <unistd.h>
#include <signal.h>

int		translator(int pid, char c);
int 	clientfunction(int pid, char *s);
static void	mainfunction(int usersignal);
int		ft_space(const char *str);
int		ft_atoi(const char *str);
int		t_count(long int nan);
char	*ft_putnbr(long int n, char *p, int negative);
char	*ft_itoa(int n);

struct t_str
{
	char	*str;
	int		i;
	int		bit;
	int		pid;
	char	c;
} s_str;


#endif
