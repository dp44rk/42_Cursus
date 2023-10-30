/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:43 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:45:16 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_bool	_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || \
			c == '\v' || c == '\f' || c == '\r');
}

t_bool	_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

t_bool	ft_atod(const char *str, double *dest)
{
	const char	**splited = (const char **)ft_alert_split(str, '.');
	int			sign;
	double		number;
	int			i;
	int			j;

	number = 0;
	sign = 1;
	j = 0;
	while (_isspace(splited[0][j]))
		j++;
	if (ft_strchr("+-", splited[0][j]) && splited[0][j++] == '-')
		sign = -1;
	while (_isdigit(splited[0][j]))
		number = (10.0 * number) + (sign * (splited[0][j++] - '0'));
	i = 0;
	if (splited[1])
		while (_isdigit(splited[1][i]))
			number = (10.0 * number) + (sign * (splited[1][i++] - '0'));
	if (splited[1])
		number = number / pow(10.0, i);
	*dest = number;
	sign = (!splited[0][j] || (splited[1] && splited[1][i] != '\0'));
	ft_2d_char_arr_free((char **)splited);
	return (sign);
}
