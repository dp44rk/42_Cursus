/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:39 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:39 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

t_bool	hit(t_object *world, t_ray *light_ray, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	temp_rec;
	t_object		*obj;

	temp_rec = *rec;
	hit_anything = FALSE;
	obj = world;
	while (obj)
	{
		if (hit_obj(obj, light_ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		obj = obj->next;
	}
	return (hit_anything);
}

// hit_obj는 오브젝트 타입에 맞는 hit함수로 연결해주는 관문
t_bool	hit_obj(t_object *obj, t_ray *light_ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (obj->type == SP)
		hit_result = hit_sphere(obj->element, light_ray, rec);
	else if (obj->type == PL)
		hit_result = hit_plane(obj->element, light_ray, rec);
	else if (obj->type == CY)
		hit_result = hit_cylinder(obj->element, light_ray, rec);
	else if (obj->type == CN)
		hit_result = hit_cone(obj->element, light_ray, rec);
	else
		aterr_exit("Invalid object type\n", NULL);
	return (hit_result);
}
