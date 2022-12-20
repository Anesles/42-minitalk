/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:50:11 by brumarti          #+#    #+#             */
/*   Updated: 2022/12/20 19:39:06 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	encoder(int pid, const char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			if (str[i] & (1 << j--))
			{
				if (kill(pid, SIGUSR1) == -1)
					send_error("Unable to send SIGUSR1.");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					send_error("Unable to send SIGUSR2.");
			}
			usleep(50);
		}
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	pid_t	pid;
	int		i;

	if (argc != 3)
		send_error("Invalid amount of arguments");
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
			send_error("Invalid PID");
	}
	pid = ft_atoi(argv[1]);
	encoder(pid, argv[2]);
	encoder(pid, "\n");
	return (EXIT_SUCCESS);
}
