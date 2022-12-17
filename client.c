/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 07:40:47 by sakkus            #+#    #+#             */
/*   Updated: 2022/11/18 07:40:49 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	count;
	int	sign;
	int	result;

	count = 0;
	sign = 1;
	result = 0;
	while (str[count] == ' ' || str[count] == '\t' || str[count] == '\n'
		|| str[count] == '\r' || str[count] == '\v' || str[count] == '\f')
		count++;
	if (str[count] == '+' || str[count] == '-')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		result = (str[count] - '0') + (result * 10);
		count++;
	}
	return (result * sign);
}

void	send_bit(char c, int pid)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if ((c >> bit) & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(100);
	}
}

int	main(int arc, char *argv[])
{
	int		pid;
	int		c;
	char	*str;

	if (arc != 3)
	{
		ft_printf("Eksik Arguman Girdiniz!!\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		c = *str++;
		send_bit(c, pid);
	}
	return (0);
}
