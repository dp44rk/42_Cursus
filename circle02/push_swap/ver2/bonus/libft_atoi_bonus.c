/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_atoi_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:18:09 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:18:11 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static bool	is_int(long long number, bool minus)
{
	long long	max_value;

	max_value = 2147483647;
	if (minus)
		max_value++;
	if (number > max_value)
		return (false);
	return (true);
}

static bool	is_digit(int c)
{
	if ('0' <= c && c <= '9')
		return (true);
	return (false);
}

char	*ft_atoi(char *str, int *dest)
{
	bool		minus;
	long long	number;

	minus = false;
	if (*str == '-')
	{
		minus = true;
		str++;
	}
	if (!is_digit(*str))
		return (NULL);
	number = 0;
	while (is_digit(*str))
	{
		number = (number * 10) + (*str++ - '0');
		if (!is_int(number, minus))
			return (NULL);
	}
	if (minus)
		number *= -1;
	if (dest)
		*dest = (int)number;
	return (str);
}
