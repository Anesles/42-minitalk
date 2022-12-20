/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:50:11 by brumarti          #+#    #+#             */
/*   Updated: 2022/12/20 19:38:46 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	decoder(char *str)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (str[i])
	{
		result <<= 1;
		if (str[i] == '1')
			result += 1;
		i++;
	}
	return (result);
}

static void	handler(int signal, siginfo_t *info, void *content)
{
	static int	i;
	static char	*c;

	(void)content;
	(void)info;
	if (!c)
		c = (char *)malloc(sizeof(char) * 8);
	if (!i)
		i = 0;
	if (signal == SIGUSR1)
		c[i] = '1';
	else
		c[i] = '0';
	if (++i == 8)
	{
		ft_printf("%c", decoder(c));
		c = 0;
		i = 0;
	}
}

static void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handler;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		send_error("Couldn't change SIGUSR1's state.");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		send_error("Couldn't change SIGUSR2's state.");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
		config_signals();
}
