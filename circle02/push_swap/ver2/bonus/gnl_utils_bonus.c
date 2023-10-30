/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:16:59 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:17:01 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strdup(char *buf)
{
	char	*ret;
	char	*p;

	ret = malloc(sizeof(char) * \
		(ft_strlen((const char *)buf) + 1));
	if (!ret)
		return (NULL);
	p = ret;
	while (*buf)
		*p++ = *buf++;
	*p = '\0';
	return (ret);
}

char	*ft_strjoin_or_dup(char *save, char *buf)
{
	int		i;
	int		j;
	char	*str;

	if (!save)
		return (ft_strdup(buf));
	str = malloc((ft_strlen(save) + \
		ft_strlen((const char *)buf) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (save[++i] != '\0')
		str[i] = save[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[i] = '\0';
	free(save);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	*s;
	unsigned char	uc;

	s = (unsigned char *)str;
	uc = (unsigned char)c;
	while (1)
	{
		if (*s == uc)
			return ((char *)s);
		if (!*s)
			return (0);
		s++;
	}
}
