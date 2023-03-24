/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:50:23 by jofilipe          #+#    #+#             */
/*   Updated: 2023/03/24 11:24:15 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bits(char c, int pid)
{
	int	bits;

	bits = 0;
	while (bits <= 7)
	{
		if ((c & (0b1 << bits)) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bits++;
		usleep(400);
	}
}

//print message "message received" when all message is sent to the other terminal

void	message_received(int signum)
{
	(void) signum;
	ft_printf("Message received!\n");
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("%s\n", "You just need 2 arguments!");
		return (0);
	}
	while (argv[2][i] != '\0')
	{
		char_to_bits(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
	signal(SIGUSR1, &message_received);
}
