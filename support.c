/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:57:19 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/01/20 11:03:40 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_printchar(int c)
{
	write(1, &c, 1);
}

void	afficher(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_printchar(str[i++]);
	}
}

int	ft_pow(int number, int n)
{
	int	i;
	int	old;

	i = 0;
	old = number;
	if (n == 0)
		return (1);
	while (n-- > 1)
		number = number * old;
	return (number);
}

int	bin_todec(int array[32], int start, int end)
{
	int	result;
	int	p;

	result = 0;
	p = 7;
	while (start < end)
	{
		result += array[start] * ft_pow(2, p);
		start++;
		p--;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
	{
		afficher("create an correct PID!");
		exit(0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		{
			afficher("create an correct PID!");
			exit(0);
		}
	}
	return (sign * res);
}
