/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:16:54 by dpark             #+#    #+#             */
/*   Updated: 2022/03/28 19:16:55 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_sstrdup(const char *s)
{
	int		i;
	int		j;
	char	*c;

	j = 0;
	i = 0;
	while (s[i])
		i++;
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (!c)
		return (0);
	while (j < i)
	{
		c[j] = s[j];
		j++;
	}
	c[j] = '\0';
	return (c);
}

static int	check_digit(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*makearr(int negative, int digit)
{
	char	*num;

	if (!negative)
	{
		num = (char *)malloc(sizeof(char) * (digit + 1));
		if (!num)
			return (0);
		num[digit] = '\0';
	}
	else
	{
		num = (char *)malloc(sizeof(char) * (digit + 2));
		if (!num)
			return (0);
		num[0] = '-';
		num[digit + 1] = '\0';
	}
	return (num);
}

static char	*make_str(int negative, int n, int digit)
{
	char	*num;

	num = makearr(negative, digit);
	if (!num)
		return (0);
	if (!negative)
		digit --;
	if (n == 0)
		num[0] = '0';
	while (n > 0)
	{
		num[digit--] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	int		negative;
	char	*num;

	if (n == -2147483648)
		return (ft_sstrdup("-2147483648"));
	if (n >= 0)
		negative = 0;
	if (n < 0)
	{
		n *= (-1);
		negative = 1;
	}
	num = make_str(negative, n, check_digit(n));
	return (num);
}
