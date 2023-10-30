/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:12:45 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:12:52 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

// scene.c
void		scene_init(t_scene *scene);
double		get_theta(double degree);
void		cal_left_bottom(t_camera *cam);

// object_create.c
t_object	*new_object(t_object_type type, void *element, int size);
t_sphere	*new_sphere(t_point3 center, double radius);
t_plane		*new_plane(t_point3 x, t_vec3 normal);
t_cylinder	*new_cylinder(t_point3 center, t_vec3 normal, \
						double radius, double height);
t_light		*new_light(t_point3 light_origin, \
						t_color3 light_color, double bright_ratio);

#endif