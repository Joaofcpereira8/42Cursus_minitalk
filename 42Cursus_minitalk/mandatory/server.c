/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:50:28 by jofilipe          #+#    #+#             */
/*   Updated: 2023/03/21 19:15:09 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int sig_handler(int signum)
{
	static int	bits;
	static char c;

	if (signum == SIGUSR1)
		c |= (0b1 << 1);	
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		bits = 0;
		c = 0; //duvida
	}
}

int	main(int argc, char **argv)
{
	(void) argv;
	struct sigaction fds;
	fds.sa_handler = &sig_handler;

	if (argc != 1)
	{
		ft_printf("%s\n", "There's more arguments then you need!");
		return (0);
	}
	printf("PID is %d\n",getpid());
	sigaction(SIGUSR1, &fds, NULL);
	sigaction(SIGUSR2, &fds, NULL);
	while(1)
		pause();
	return (0);
}
