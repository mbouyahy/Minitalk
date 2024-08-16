/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:02:58 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/01/20 15:26:41 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

//Structures

typedef struct s_var
{
	int				i;
	int				counter;
	int				pid;
	unsigned char	**av;
}	t_var;

//Functions

int		ft_atoi(char *str);
void	afficher(char *str);
void	ft_printchar(int c);
int		bin_todec(int array[32], int start, int end);
void	shorting_code(int *g_binary, int *i);
void	check_bits(int pid, int *g_binary, int *i, int *j);
int		final_check(int binary[8]);

#endif
