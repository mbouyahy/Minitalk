/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:52:43 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/01/20 13:14:58 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_binary[32];

void	unicode_check(int *j)
{
	if (g_binary[0] == 1 && g_binary[1] == 1 \
				&& g_binary[2] == 1 && g_binary[3] == 1)
		(*j) = 32;
	else if (g_binary[0] == 1 && g_binary[1] == 1 && g_binary[2] == 1)
		(*j) = 24;
	else if (g_binary[0] == 1 && g_binary[1] == 1)
		(*j) = 16;
	else
		(*j) = 8;
}

void	remplir(int b, siginfo_t *s, void *context)
{
	static int	i;
	static int	j;
	static int	pid;

	(void)context;
	if (pid != s->si_pid)
	{
		pid = s->si_pid;
		i = 0;
		j = 0;
	}
	if (b == SIGUSR1)
		g_binary[i++] = 0;
	else if (b == SIGUSR2)
		g_binary[i++] = 1;
	if (i == 4)
		unicode_check(&j);
	check_bits(pid, g_binary, &i, &j);
	if (i == j)
	{
		shorting_code(g_binary, &i);
		i = 0;
		j = 0;
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
