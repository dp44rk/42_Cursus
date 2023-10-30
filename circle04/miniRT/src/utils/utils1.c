/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:12:01 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:12:02 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_size	ft_strlen(const char *s)
{
	t_size	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

t_bool	is_within(double value, double min_value, double max_value, \
					t_comparison_mode mode)
{
	return (
		(mode & Left && min_value == value) || \
		(mode & Right && max_value == value) || \
		(min_value < value && value < max_value)
	);
}

char	*ft_strchr(const char *s, char ch)
{
	if (s == NULL)
		return (NULL);
	while (*s != ch)
		if (*s++ == '\0')
			return (NULL);
	return ((char *)s);
}

void	ft_memset(void *ptr, int value, t_size n)
{
	t_size			i;
	unsigned char	*up;
	unsigned char	uc;

	up = (unsigned char *)ptr;
	uc = (unsigned char) value;
	i = 0;
	while (i < n)
		up[i++] = uc;
}
