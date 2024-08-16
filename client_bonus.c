/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:51:46 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/01/20 15:33:25 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bzero(int *tab)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		tab[i] = 0;
		i++;
	}
}

void	to_binary(int *binary, int j, int c)
{
	static int	i;

	if (c < 2)
	{
		i = 8 - j;
		binary[i] = c % 2;
		i++;
	}
	else
	{
		to_binary(binary, j + 1, c / 2);
		binary[i] = c % 2;
		i++;
	}
}

void	send_sig(int pid, int *binary)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (binary[i] == 0)
			kill(pid, SIGUSR1);
		else if (binary[i] == 1)
			kill(pid, SIGUSR2);
		usleep(300);
		i++;
	}
	ft_bzero(binary);
}

void	confirming_receipt(int b)
{
	if (b == SIGUSR1)
	{
		afficher("RECEIPT_COMPLETED");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_var		var;
	int			binary[8];

	var.i = 0;
	var.counter = 1;
	var.av = (unsigned char **)argv;
	if (argc == 3)
	{
		var.pid = ft_atoi(argv[1]);
		if (var.pid <= 1)
		{
			afficher("Create an correct PID\n");
			exit(0);
		}
		while (var.av[2][var.i])
		{
			signal(SIGUSR1, confirming_receipt);
			signal(SIGUSR2, confirming_receipt);
			to_binary(binary, var.counter, var.av[2][var.i]);
			send_sig(var.pid, binary);
			var.i++;
		}
		send_sig(ft_atoi((char *)var.av[1]), binary);
	}
	return (0);
}
