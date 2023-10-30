/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:07:48 by dpark             #+#    #+#             */
/*   Updated: 2022/04/17 17:50:55 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_base(char *base)
{
	int	n;

	n = 0;
	while (base[n])
		n++;
	return (n);
}

void	remake_base(unsigned long int nbr, char *base, int *len)
{
	int		i;
	char	refine[50];
	int		b;

	b = len_base(base);
	i = 0;
	while (1)
	{
		refine[i++] = base[nbr % b];
		nbr /= b;
		if (nbr == 0)
			break ;
	}
	refine[i] = '\0';
	i--;
	while (i >= 0)
		ft_putchar_fd(refine[i--], 1, len);
	return ;
}

int	invalid_base(char *base)
{
	int	i;

	i = 0;
	if (len_base(base) == 0 || len_base(base) == 1)
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_base(unsigned long nbr, char *base, int *len)
{
	remake_base(nbr, base, len);
	return ;
}
