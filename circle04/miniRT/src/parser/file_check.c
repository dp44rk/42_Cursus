/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:22 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:22 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	_excute_line_parser(t_scene *scene, const char *line)
{
	const char	**splited = (const char **)ft_alert_split(line, ' ');

	if (!ft_strcmp(splited[0], "A"))
		parse_ambient(scene, splited);
	else if (!ft_strcmp(splited[0], "C"))
		parse_camera(scene, splited);
	else if (!ft_strcmp(splited[0], "L"))
		parse_light(scene, splited);
	else if (!ft_strcmp(splited[0], "pl"))
		parse_plane(scene, splited);
	else if (!ft_strcmp(splited[0], "sp"))
		parse_sphere(scene, splited);
	else if (!ft_strcmp(splited[0], "cy"))
		parse_cylinder(scene, splited);
	else if (!ft_strcmp(splited[0], "cn"))
		parse_cone(scene, splited);
	else
		aterr_exit("Invalid Line (Invalid identifier)\n", NULL);
	ft_2d_char_arr_free((char **)splited);
}

void	file_check(t_scene *scene, const char *path)
{
	int		fd;
	char	*line;

	if (!ft_ext_cmp(".rt", path))
		aterr_exit("Invalid file name. (.rt file is required)\n", NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		aterr_exit("Fail to open file.\n", NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (!is_empty_or_annotaion_line(line))
			_excute_line_parser(scene, line);
		free(line);
		line = get_next_line(fd);
	}
}
