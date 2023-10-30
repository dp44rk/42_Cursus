/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:04:29 by dpark             #+#    #+#             */
/*   Updated: 2022/04/29 18:49:26 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_remove_empty_lst(int fd, t_list *cur, t_list **head, t_list *deleted)
{
	if (cur == NULL)
		return ;
	if (cur->fd == fd)
	{
		deleted = cur;
		*head = cur->next;
		free(deleted);
		return ;
	}
	while (cur->next)
	{
		if (cur->next->fd == fd)
		{
			deleted = cur->next;
			cur->next = cur->next->next;
			free(deleted);
			return ;
		}
		cur = cur->next;
	}
}

char	**gnl_init(int fd, t_list *cur, char **mount, char **line)
{
	*mount = NULL;
	*line = NULL;
	while (cur)
	{
		if (cur->fd == fd)
			return (&(cur->temp));
		cur = cur->next;
	}
	return (mount);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (1)
	{
		if (s[i] == (char)c)
			return (i);
		if (s[i] == '\0')
			return (-1);
		i++;
	}
}

int	ft_strjoin(char **dest, char *s2)
{
	int			i;
	int			j;
	char		*s1;
	char		*c;

	if (!(*dest))
		s1 = "";
	else
		s1 = *dest;
	c = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!c)
		return (0);
	i = -1;
	j = -1;
	while (s1[++i])
		c[i] = s1[i];
	while (s2[++j])
		c[i + j] = s2[j];
	c[i + j] = '\0';
	if (*dest)
		free(*dest);
	*dest = c;
	return (1);
}
