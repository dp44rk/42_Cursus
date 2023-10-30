/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:26:16 by dpark             #+#    #+#             */
/*   Updated: 2022/04/17 17:49:19 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_c(va_list ap, int *len)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1, len);
}

void	format_s(va_list ap, int *len)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	ft_putstr_fd(s, 1, len);
}

void	format_p(va_list ap, int *len)
{
	unsigned long	i;

	i = va_arg(ap, unsigned long);
	ft_putstr_fd("0x", 1, len);
	ft_putnbr_base(i, "0123456789abcdef", len);
}

void	format_d_i(va_list ap, int *len)
{
	int	i;

	i = va_arg(ap, int);
	ft_putnbr_fd(i, 1, len);
}

void	format_u(va_list ap, int *len)
{
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	ft_unputnbr_fd(i, 1, len);
}
