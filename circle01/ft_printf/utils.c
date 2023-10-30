/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:08:15 by dpark             #+#    #+#             */
/*   Updated: 2022/04/17 20:32:43 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd, int *len)
{
	write(fd, &c, 1);
	*len = *len + 1;
	return ;
}

void	ft_putstr_fd(char *s, int fd, int *len)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd, len);
		s++;
	}
	return ;
}

void	ft_unputnbr_fd(unsigned long int n, int fd, int *len)
{
	if (n > 9)
		ft_unputnbr_fd(n / 10, fd, len);
	ft_putchar_fd((n % 10) + '0', fd, len);
}

void	ft_putnbr_fd(int n, int fd, int *len)
{	
	char	c;

	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd, len);
		ft_putnbr_fd(8, 1, len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1, len);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd, len);
	c = '0' + (n % 10);
	ft_putchar_fd(c, 1, len);
}
