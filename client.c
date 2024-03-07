/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavall <lucavall@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:35:40 by lucavall          #+#    #+#             */
/*   Updated: 2024/02/24 19:06:15 by lucavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bits(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	if (ft_atoi(argv[1]) > 0)
	{
		if (argc == 3)
		{
			while (*argv[2] != '\0')
			{
				send_bits(ft_atoi(argv[1]), *argv[2]);
				argv[2]++;
			}
			send_bits(ft_atoi(argv[1]), '\n');
		}
		else
			ft_printf("Usage: client - PID - MESSAGE\n");
	}
	else
		ft_printf("ERROR: PID must be a number above 0.\n");
}
