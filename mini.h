/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:11:26 by pwildcat          #+#    #+#             */
/*   Updated: 2022/02/23 12:11:28 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <unistd.h>
# include <signal.h>

int			translator(int pid, char c);
int			clientfunction(int pid, char *s);
static void	mainfunction(int usersignal);
int			ft_space(const char *str);
int			ft_atoi(const char *str);
int			t_count(long int nan);
char		*ft_putnbr(long int n, char *p, int negative);
char		*ft_itoa(int n);

struct s_str
{
	char	*str;
	int		i;
	int		bit;
	int		pid;
	char	c;
} t_str;
#endif
