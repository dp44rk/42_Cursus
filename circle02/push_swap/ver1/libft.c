/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:44 by dpark             #+#    #+#             */
/*   Updated: 2022/08/31 18:08:04 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_space(char str)
{
	if (str == ' ' || str == '\t' || str == '\r' \
		|| str == '\n' || str == '\v' || str == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	r;
	int		i;

	r = 0;
	i = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i *= -1;
		str++;
	}
	while (*str)
	{
		if (ft_isdigit(*str) != 1)
			ft_print_error();
		r *= 10;
		r += *str - 48;
		str++;
	}
	if (r > 2147483647 || r < -2147483648)
		ft_print_error();
	return (r * i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
