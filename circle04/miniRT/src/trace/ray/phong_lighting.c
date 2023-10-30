/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:44 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:45 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vplus(vmult(v, -1), vmult(n, 2 * vdot(v, n))));
}

t_vec3	diffuse_color(t_scene *scene, t_light *light, t_vec3 light_unit_dir)
{
	const double	diffuse_strength = fmax(\
		vdot(scene->rec.normal, light_unit_dir), 0.0);

	return (vmult(light->light_color, diffuse_strength));
}

t_vec3	specular_color(t_scene *scene, t_light *light, t_vec3 light_unit_dir)
{
	const double	spec = pow(fmax(vdot(\
		vunit(vmult(scene->primary_ray.dir, -1)), \
		reflect(light_unit_dir, scene->rec.normal)), 0.0), SHININESS_VALUE);

	return (vmult(light->light_color, SPECULAR_STRENGTH * spec));
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	const t_vec3	light_dir = vminus(light->origin, scene->rec.p);
	const t_vec3	light_unit_dir = vunit(light_dir);
	t_color3		diffuse;
	t_color3		specular;

	diffuse = diffuse_color(scene, light, light_unit_dir);
	specular = specular_color(scene, light, light_unit_dir);
	return (vmult(vplus(diffuse, specular), light->bright_ratio * LUMEN));
}

/*
	기본값 => ambient;
	각 광원마다 => 그림자 여부 체크 후 => diffuse, specular 수치를 더해준다.
	마지막으로 이렇게 구해진 빛의 양에 오브젝트 반사율을 곱해준다.
*/
t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*light_obj;

	light_color = scene->ambient;
	light_obj = scene->light;
	while (light_obj)
	{
		if (!is_in_shadow(scene, light_obj->element))
			light_color = vplus(light_color, \
							point_light_get(scene, light_obj->element));
		light_obj = light_obj->next;
	}
	return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}
