/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:51 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:11:52 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static char	*_ft_strjoin_or_dup(char *prev, const char *added)
{
	int		i;
	int		j;
	char	*str;

	if (prev == NULL)
		prev = "";
	str = ft_alert_malloc((ft_strlen((const char *)prev) + \
		ft_strlen((const char *)added) + 1) * sizeof(char));
	i = -1;
	while (prev[++i] != '\0')
		str[i] = prev[i];
	j = 0;
	while (added[j] != '\0')
		str[i++] = added[j++];
	str[i] = '\0';
	if (prev[0] != '\0')
		free(prev);
	return (str);
}

static char	*_ft_read_and_update(int fd, char *save)
{
	char *const	buff = ft_alert_calloc((BUFFER_SIZE + 1) * sizeof(char));
	int			read_bytes;

	while (!ft_strchr((const char *)buff, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
			aterr_exit("Fail to read\n", NULL);
		buff[read_bytes] = '\0';
		if (read_bytes)
			save = _ft_strjoin_or_dup(save, (const char *)buff);
		else
			break ;
	}
	free(buff);
	return (save);
}

static char	*_ft_get_until_lf(char *save)
{
	int		i;
	char	*line;
	char	*p;

	i = 0;
	while (save[i])
		if (save[i++] == '\n')
			break ;
	line = ft_alert_malloc(sizeof(char) * (i + 1));
	p = line;
	while (i--)
		*p++ = *save++;
	*p = '\0';
	return (line);
}

static char	*_ft_get_after_lf(char *save)
{
	int		i;
	int		c;
	char	*ret;

	ret = NULL;
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] != '\0' && save[++i] != '\0')
	{
		ret = ft_alert_malloc(sizeof(char) * \
				(ft_strlen((const char *)save) - i + 1));
		c = 0;
		while (save[i])
			ret[c++] = save[i++];
		ret[c] = '\0';
	}
	free(save);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr((const char *)save, '\n'))
		save = _ft_read_and_update(fd, save);
	if (!save)
		return (NULL);
	line = _ft_get_until_lf(save);
	save = _ft_get_after_lf(save);
	return (line);
}
