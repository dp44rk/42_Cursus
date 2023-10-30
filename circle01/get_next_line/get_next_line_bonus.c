/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:40:36 by dpark             #+#    #+#             */
/*   Updated: 2022/04/29 19:08:57 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_handle_node(int fd, char **temp, char **mount, t_list **head)
{
	t_list	*new;

	if (*temp == NULL)
	{
		ft_remove_empty_lst(fd, *head, head, NULL);
		return (1);
	}
	if (temp != mount)
		return (1);
	new = malloc(sizeof(t_list));
	if (new == NULL)
	{
		if (*temp)
		{
			free(*temp);
			*temp = NULL;
		}
		return (0);
	}
	new->temp = *temp;
	new->fd = fd;
	new->next = *head;
	*head = new;
	return (1);
}

int	update_temp(char **origin)
{
	char	*update;
	char	*temp;
	int		lf;
	int		status;

	temp = *origin;
	lf = ft_strchr(temp, '\n');
	if (lf == -1 || temp[lf + 1] == '\0')
	{
		free(temp);
		*origin = NULL;
		return (1);
	}
	update = NULL;
	status = ft_strjoin(&update, &(temp[lf + 1]));
	if (status)
		free(temp);
	*origin = update;
	return (status);
}

int	get_line(char **line, char **temp)
{
	int		lf;
	char	lf_char;
	int		status;

	*line = 0;
	lf = ft_strchr((const char *)temp[0], '\n');
	if (lf != -1)
	{
		lf_char = temp[0][lf + 1];
		temp[0][lf + 1] = '\0';
	}
	status = ft_strjoin(line, *temp);
	if (lf != -1)
		temp[0][lf + 1] = lf_char;
	if (!status)
	{
		free(*temp);
		*temp = NULL;
	}
	return (status);
}

int	make_temp(char **temp, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_bytes;

	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0)
			return (1);
		if (read_bytes == -1)
			break ;
		buffer[read_bytes] = '\0';
		if (!ft_strjoin(temp, buffer))
			break ;
		if (ft_strchr(buffer, '\n') != -1)
			return (1);
	}
	if (*temp)
		free(*temp);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*head = NULL;
	char			**temp;
	char			*mount;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = gnl_init(fd, head, &mount, &line);
	if (ft_strchr((const char *)*temp, '\n') == -1)
		if (!make_temp(temp, fd))
			return (0);
	if (!*temp)
		return (0);
	if (!get_line(&line, temp))
		return (0);
	if (!update_temp(temp) || \
		!ft_handle_node(fd, temp, &mount, &head))
	{
		free(line);
		return (0);
	}
	return (line);
}
