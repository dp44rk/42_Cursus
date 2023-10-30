/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:35:22 by dpark             #+#    #+#             */
/*   Updated: 2022/04/17 20:44:27 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_type(va_list ap, const char *str, int *len)
{
	unsigned int	i;

	if (*str == 'c')
		format_c(ap, len);
	else if (*str == 's')
		format_s(ap, len);
	else if (*str == 'p')
		format_p(ap, len);
	else if (*str == 'i' || *str == 'd')
		format_d_i(ap, len);
	else if (*str == 'u')
		format_u(ap, len);
	else if (*str == 'X' || *str == 'x')
	{
		i = va_arg(ap, unsigned int);
		if (*str == 'x')
			ft_putnbr_base(i, "0123456789abcdef", len);
		if (*str == 'X')
			ft_putnbr_base(i, "0123456789ABCDEF", len);
	}
	else if (*str == '%')
		ft_putchar_fd('%', 1, len);
	else
		*len = -1;
	return ;
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			find_type(ap, str, &len);
			if (len < 0)
				return (-1);
		}
		else
			ft_putchar_fd(*str, 1, &len);
		str++;
	}
	va_end(ap);
	return (len);
}
