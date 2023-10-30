/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alert1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:40 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:11:42 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	*ft_alert_malloc(t_size n)
{
	void	*temp;

	if (n == 0)
		(NULL);
	temp = malloc(n);
	if (temp == NULL)
		aterr_exit("Fail to malloc\n", NULL);
	return (temp);
}

void	*ft_alert_calloc(t_size n)
{
	void	*temp;

	if (n == 0)
		(NULL);
	temp = ft_alert_malloc(n);
	if (temp == NULL)
		aterr_exit("Fail to malloc\n", NULL);
	ft_memset(temp, 0, n);
	return (temp);
}

// 최대 n - 1까지 복사, n번째에는 \0 보장.
char	*ft_alert_strndup(const char *origin, t_size n)
{
	char	*s;
	t_size	i;

	i = 0;
	s = ft_alert_malloc(n);
	while (origin[i] && i + 1 < n)
	{
		s[i] = origin[i];
		i++;
	}
	while (i < n)
		s[i++] = '\0';
	return (s);
}
