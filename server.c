/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 07:38:14 by sakkus            #+#    #+#             */
/*   Updated: 2022/11/18 07:38:17 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	binary_handler(int sig)
{
	static int	bit = 7;
	static int	res = 0;
	int			catch;

	if (sig == SIGUSR1)
		catch = 1;
	else
		catch = 0;
	res = res + (catch << bit);
	if (bit == 0)
	{
		ft_printf("%c", res);
		bit = 7;
		res = 0;
	}
	else
	{
		bit--;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID=> %d\n", pid);
	signal(SIGUSR1, binary_handler);
	signal(SIGUSR2, binary_handler);
	while (1)
		;
	return (0);
}
