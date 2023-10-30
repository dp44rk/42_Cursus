/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:42 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:43 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

t_bool	is_in_shadow(t_scene *scene, t_light *light)
{
	const t_vec3	light_dir = vminus(light->origin, scene->rec.p);
	const double	light_len = vlength(light_dir);
	t_ray			light_ray;
	t_hit_record	rec;

	light_ray = ray(vplus(scene->rec.p, vmult(vunit(light_dir), EPSILON)), \
					light_dir);
	rec.tmin = EPSILON;
	rec.tmax = light_len;
	if (hit(scene->world, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}
