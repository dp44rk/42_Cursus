/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:54:59 by dpark             #+#    #+#             */
/*   Updated: 2022/06/13 15:39:48 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	hdr_last_signal(int signum, siginfo_t *info, void *(v))
{
	static char		c;
	static int		cnt;
	static int		server_pid;

	(void)v;
	if (server_pid != info->si_pid && cnt != 0)
	{
		cnt = 0;
		c = 0;
	}
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		c = c << 1;
		if (signum == SIGUSR1)
			c = c | 1;
		cnt++;
	}
	if (cnt == 8 && c == 0)
		exit(0);
	server_pid = info->si_pid;
}

void	hdr_check_signal(int signum, siginfo_t *info, void *(v))
{
	(void)v;
	(void)info;
	if (signum == SIGUSR1)
	{
		g_client_signals.sa_sigaction = hdr_last_signal;
		sigaction(SIGUSR1, &g_client_signals, NULL);
		sigaction(SIGUSR2, &g_client_signals, NULL);
	}
}

void	send_signal(int pid, char c)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if (c && c >> i & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else if (c)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(500);
	}
}

void	send_str(int pid, char *str)
{
	char	c;
	int		i;

	while (*str != '\0')
	{
		c = *str;
		send_signal(pid, c);
		str++;
	}
	if (*str == '\0')
	{
		i = 8;
		while (--i >= 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
			usleep(500);
		}
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	server_pid = ft_atoi(argv[1]);
	g_client_signals.sa_flags = SA_SIGINFO;
	g_client_signals.sa_sigaction = hdr_check_signal;
	sigemptyset(&g_client_signals.sa_mask);
	sigaction(SIGUSR1, &g_client_signals, NULL);
	sigaction(SIGUSR2, &g_client_signals, NULL);
	if (argc != 3)
	{
		ft_printf("INVALID ARGUMENT!");
		return (0);
	}
	if (kill(server_pid, SIGUSR1) == -1)
		exit(1);
	pause();
	send_str(server_pid, argv[2]);
	return (1);
}
