/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:46 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:46 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

t_ray	ray(t_point3 origin, t_vec3 direction)
{
	t_ray	ray;

	ray.orig = origin;
	ray.dir = vunit(direction);
	return (ray);
}

/*
	ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
*/
t_point3	ray_at(t_ray *ray, double t)
{
	const t_point3	at = vplus(ray->orig, vmult(ray->dir, t));

	return (at);
}

/*
	primary_ray 생성자
	left_bottom + u * horizontal + v * vertical - origin 의 단위 벡터.
*/
t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray			ray;
	const t_vec3	dh = vmult(cam->right_normal, u);
	const t_vec3	dv = vmult(cam->up_normal, v);
	const t_point3	viewport_point = vplus(cam->left_bottom, vplus(dh, dv));

	ray.orig = cam->origin;
	ray.dir = vunit(vminus(viewport_point, ray.orig));
	return (ray);
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

/*
	광선이 최종적으로 얻게된 픽셀의 색상 값을 리턴.
	t: ray의 방향벡터의 y 값을 기준으로 그라데이션을 주기 위한 계수, (1-t) * 흰색 + t * 하늘색
*/
t_color3	ray_color(t_scene *scene, double u, double v)
{	
	scene->primary_ray = ray_primary(&scene->camera, u, v);
	scene->rec = record_init();
	if (hit(scene->world, &scene->primary_ray, &scene->rec))
		return (phong_lighting(scene));
	return (color3(1, 1, 1));
}
