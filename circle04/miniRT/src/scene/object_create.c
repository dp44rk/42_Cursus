/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:29 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:29 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_object	*new_object(t_object_type type, void *element, int size)
{
	t_object *const	obj = ft_alert_malloc(size);

	obj->type = type;
	obj->element = element;
	obj->next = NULL;
	return (obj);
}

t_sphere	*new_sphere(t_point3 center, double radius)
{
	t_sphere *const	sp = ft_alert_malloc(sizeof(t_sphere));

	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

t_plane	*new_plane(t_point3 x, t_vec3 normal)
{
	t_plane *const	pl = ft_alert_malloc(sizeof(t_plane));

	pl->x = x;
	pl->normal = normal;
	return (pl);
}

t_cylinder	*new_cylinder(t_point3 center, t_vec3 normal, \
						double radius, double height)
{
	t_cylinder *const	cy = ft_alert_malloc(sizeof(t_cylinder));

	cy->center = vminus(center, vmult(normal, height / 2));
	cy->normal = normal;
	cy->radius = radius;
	cy->height = height;
	return (cy);
}

t_light	*new_light(t_point3 light_origin, t_color3 light_color, \
						double bright_ratio)
{
	t_light *const	light = ft_alert_malloc(sizeof(t_light));

	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
