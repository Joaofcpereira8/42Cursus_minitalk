/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:50:28 by jofilipe          #+#    #+#             */
/*   Updated: 2023/03/24 11:26:27 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum, siginfo_t *info, void *ucontext)
{
	static int	bits;
	static char	c;
	(void)		ucontext;

	if (signum == SIGUSR1)
		c |= (0b1 << bits);
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		ft_printf("%c", c);
		bits = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	(void) argv;
	struct sigaction fds;
	fds.sa_sigaction = &sig_handler;
	fds.sa_flags = SA_SIGINFO;
	sigemptyset(&fds.sa_mask);

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
