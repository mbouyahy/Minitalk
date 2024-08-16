/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:40:36 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/01/20 13:15:03 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_binary[8];

void	remplir(int b, siginfo_t *s, void *context)
{
	static int	i;
	static int	pid;

	(void)context;
	if (pid != s->si_pid)
	{
		pid = s->si_pid;
		i = 0;
	}
	if (b == SIGUSR1)
		g_binary[i++] = 0;
	else if (b == SIGUSR2)
		g_binary[i++] = 1;
	if (i == 8)
	{
		ft_printchar(bin_todec(g_binary, 0, 8));
		i = 0;
	}
}

void	ft_putnbr(int n)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_printchar('-');
		n *= -1;
	}
	nbr = n;
	if (nbr < 10)
	{
		ft_printchar(n + '0');
		return ;
	}
	ft_putnbr(nbr / 10);
	ft_printchar(nbr % 10 + '0');
}

int	main(void)
{
	struct sigaction	act;

	act.__sigaction_u.__sa_sigaction = remplir;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	afficher("PID : ");
	ft_putnbr(getpid());
	afficher("\n");
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		;
	return (0);
}
