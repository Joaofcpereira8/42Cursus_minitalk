/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:50:28 by jofilipe          #+#    #+#             */
/*   Updated: 2023/03/24 11:06:33 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum)
{
	static int	bits;
	static char	c;

	if (signum == SIGUSR1)
		c |= (0b1 << bits);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		bits = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	(void) argv;

	if (argc != 1)
	{
		ft_printf("%s\n", "There's more arguments then you need!");
		return (0);
	}
	printf ("PID is %d\n",getpid());
	signal(SIGUSR1, &sig_handler);
	signal(SIGUSR2, &sig_handler);
	while(1)
		pause();
	return (0);
}
