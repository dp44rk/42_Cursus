/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:49 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:11:49 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static char	**_push_arr(char **s, char *pushed)
{
	t_size	i;
	char	**ret;

	i = 0;
	while (s[i])
		i++;
	ret = ft_alert_malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	free(s);
	ret[i] = pushed;
	ret[i + 1] = NULL;
	return (ret);
}

char	**ft_alert_split(const char *s, char delimiter)
{
	const char	*p;
	char		**ret;

	ret = ft_alert_calloc(sizeof(char *));
	while (42)
	{
		p = ft_strchr(s, delimiter);
		if (!p)
			p = s + ft_strlen(s);
		ret = _push_arr(ret, ft_alert_strndup(s, p - s + 1));
		if (*p == '\0')
			break ;
		s = p;
		while (*s == delimiter)
			s++;
	}
	return (ret);
}
