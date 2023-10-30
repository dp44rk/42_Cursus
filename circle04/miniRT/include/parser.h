/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:12:42 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:12:42 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include "utils.h"
# include "structures.h"
# include "scene.h"

// file_check.c
void	file_check(t_scene *scene, const char *path);

// line_check
void	parse_camera(t_scene *scene, const char **splited);
void	parse_ambient(t_scene *scene, const char **splited);
void	parse_light(t_scene *scene, const char **splited);

// object_check
void	parse_sphere(t_scene *scene, const char **splited);
void	parse_plane(t_scene *scene, const char **splited);
void	parse_cylinder(t_scene *scene, const char **splited);
void	parse_cone(t_scene *scene, const char **splited);

// element_check
t_bool	parse_rgb(const char *s, t_color3 *dest);
t_bool	parse_xyz(const char *s, t_point3 *dest);
t_bool	parse_dir(const char *s, t_color3 *dest);

// parser_utils.c
t_bool	is_empty_or_annotaion_line(const char *line);
double	ft_get_focal_len(double viewport_w, double fov);

#endif