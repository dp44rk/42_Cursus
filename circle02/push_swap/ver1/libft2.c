/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:46 by dpark             #+#    #+#             */
/*   Updated: 2022/08/31 18:17:07 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (true);
		s1++;
		s2++;
	}
	return (false);
}

void	*ft_alert_malloc(size_t size)
{
	void	*ret;

	if (size == 0)
		return (NULL);
	ret = malloc(size);
	if (ret == NULL)
	{
		write(2, "malloc fail\n", 12);
		exit(1);
	}
	return (ret);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	uc;

	ptr = (unsigned char *)b;
	uc = (unsigned char)c;
	while (len--)
		*ptr++ = uc;
	return (b);
}

void	ft_print_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}
