/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:08:48 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/01/20 11:23:37 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	shorting_code(int *g_binary, int *i)
{
	int	j;

	j = 0;
	if (*i > 8)
	{
		while (j < *i)
		{
			ft_printchar(bin_todec(g_binary, j, j + 8));
			j += 8;
		}
	}
	else
		ft_printchar(bin_todec(g_binary, j, 8));
}

int	final_check(int binary[8])
{
	int	i;

	i = 0;
	while (i <= 7 && binary[i] == 0)
			i++;
	if (i == 8)
		return (1);
	return (0);
}

void	check_bits(int pid, int *g_binary, int *i, int *j)
{
	if (*i == *j && final_check(g_binary) == 1)
	{
		kill(pid, SIGUSR1);
		*i = 0;
		*j = 0;
	}
}
