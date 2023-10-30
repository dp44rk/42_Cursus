/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:30 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:31 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/*
	왼쪽 아래 코너점 좌표, origin - horizontal / 2 - vertical / 2 - vec3(0,0,FOCAL_LENGTH)
*/
double	get_theta(double degree)
{
	const double	radian = M_PI / 180;

	return (degree * radian);
}

void	cal_left_bottom(t_camera *cam)
{
	const t_vec3	vy = vec3(0.0, 1.0, 0.0);
	const t_vec3	vz = vec3(0.0, 0.0, -1.0);
	double			focal_len;

	if (vlength(vcross(vy, cam->dir)))
		cam->right_normal = vunit(vcross(cam->dir, vy));
	else
		cam->right_normal = vunit(vcross(cam->dir, vz));
	cam->up_normal = vunit(vcross(cam->right_normal, cam->dir));
	focal_len = (double)(WINDOW_WIDTH / 2) / tan(get_theta(cam->fov / 2));
	cam->left_bottom = vminus(\
		vplus(cam->origin, vmult(cam->dir, focal_len)), \
		vplus(\
			vmult(cam->right_normal, (double)(WINDOW_WIDTH - 1) / 2), \
			vmult(cam->up_normal, (double)(WINDOW_HEIGHT - 1) / 2) \
		) \
	);
}

void	scene_init(t_scene *scene)
{
	ft_memset(scene, 0, sizeof(t_scene));
	scene->canvas.width = WINDOW_WIDTH;
	scene->canvas.height = WINDOW_HEIGHT;
	scene->world = NULL;
	scene->light = NULL;
}
