/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:24 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:24 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/*
	A 0.2 255,255,255
	identifier
	ambient ratio [0.0, 1.0]
	RGB colors [0-255]
*/
void	parse_ambient(t_scene *scene, const char **splited)
{
	t_vec3	vec;
	double	rgb;

	if (scene->num_of_ambient != 0)
		aterr_exit("Invalid Line at parse_ambient (1: not unique)\n", NULL);
	scene->num_of_ambient = 1;
	if (ft_2d_char_arr_len((const char **)splited) != 3)
		aterr_exit("Invalid Line at parse_ambient (2: Invalid format)\n", NULL);
	if (!ft_atod(splited[1], &rgb) || !is_within(rgb, 0.0, 1.0, Both))
		aterr_exit("Invalid Line at parse_ambient (3)\n", NULL);
	if (!parse_rgb(splited[2], &vec))
		aterr_exit("Invalid Line at parse_ambient (4)\n", NULL);
	scene->ambient = vmult_(point3(rgb, rgb, rgb), vec);
}

/*
	C -50.0,0,20 0,0,1 70
	identifier
	3. x,y,z double 3개
	4. normal double 3개 [-1,1]
	5. FOV double 1개 [0,180]
*/
void	parse_camera(t_scene *scene, const char **splited)
{
	t_camera *const	camera = &scene->camera;
	t_point3		origin;
	t_vec3			dir;
	double			fov;

	if (scene->num_of_camera != 0)
		aterr_exit("Invalid Line at parse_camera (1: not unique)\n", NULL);
	scene->num_of_camera = 1;
	if (ft_2d_char_arr_len((const char **)splited) != 4)
		aterr_exit("Invalid Line at parse_camera (2)\n", NULL);
	if (!parse_xyz(splited[1], &origin))
		aterr_exit("Invalid Line at parse_camera (3)\n", NULL);
	camera->origin = origin;
	if (!parse_dir(splited[2], &dir))
		aterr_exit("Invalid Line at parse_camera (4)\n", NULL);
	camera->dir = dir;
	if (!ft_atod(splited[3], &fov) || !is_within(fov, 0, 180, Both))
		aterr_exit("Invalid Line at parse_camera (5)\n", NULL);
	camera->fov = fov;
	cal_left_bottom((t_camera *)camera);
}

/*
	중복 허용
	L -40.0,50.0,0.0 0.6 10,0,255
	identifier
	2. x,y,z double 3개
	3. brightness ratio double 1개 [0.0, 1.0]
	4. rgb double 3개 [0-255]
*/
void	parse_light(t_scene *scene, const char **splited)
{
	t_object *const	obj = ft_alert_calloc(sizeof(t_object));
	t_light *const	light = ft_alert_calloc(sizeof(t_light));
	t_vec3			vec;
	double			brightness;

	if (ft_2d_char_arr_len((const char **)splited) != 4)
		aterr_exit("Invalid Line at parse_light (1)\n", NULL);
	if (!parse_xyz(splited[1], &vec))
		aterr_exit("Invalid Line at parse_light (2)\n", NULL);
	light->origin = vec;
	if (!ft_atod(splited[2], &brightness) || \
		!is_within(brightness, 0, 1, Both))
		aterr_exit("Invalid Line at parse_light (3)\n", NULL);
	light->bright_ratio = brightness;
	if (!parse_rgb(splited[3], &vec))
		aterr_exit("Invalid Line at parse_light (4)\n", NULL);
	light->light_color = vec;
	obj->type = LIGHT_POINT;
	obj->element = light;
	oadd(&scene->light, obj);
}
