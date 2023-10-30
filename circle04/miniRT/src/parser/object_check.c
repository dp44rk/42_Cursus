/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:25 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:26 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/*
	sp 0.0,0.0,20.6 12.6 10,0,255
	identifier
	2. x,y,z
	3. diameter
	4. rgb
*/
void	parse_sphere(t_scene *scene, const char **splited)
{
	t_object *const	obj = ft_alert_calloc(sizeof(t_object));
	t_sphere *const	sp = ft_alert_calloc(sizeof(t_sphere));
	t_vec3			vec;
	double			diameter;

	if (ft_2d_char_arr_len(splited) != 4)
		aterr_exit("Invalid Line at parse_sphere (1)\n", NULL);
	if (!parse_xyz(splited[1], &vec))
		aterr_exit("Invalid Line at parse_sphere (2)\n", NULL);
	sp->center = vec;
	if (!ft_atod(splited[2], &diameter) || diameter <= 0)
		aterr_exit("Invalid Line at parse_sphere (3)\n", NULL);
	sp->radius = diameter / 2;
	sp->radius2 = sp->radius * sp->radius;
	if (!parse_rgb(splited[3], &vec))
		aterr_exit("Invalid Line at parse_sphere (4)\n", NULL);
	sp->albedo = vec;
	obj->element = sp;
	obj->type = SP;
	oadd(&scene->world, obj);
}

/*
	pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
	identifier pl
	2. x,y,z
	3. normal
	4. rgb
*/
void	parse_plane(t_scene *scene, const char **splited)
{
	t_object *const	obj = ft_alert_calloc(sizeof(t_object));
	t_plane *const	pl = ft_alert_calloc(sizeof(t_plane));
	t_vec3			vec;

	if (ft_2d_char_arr_len(splited) != 4)
		aterr_exit("Invalid Line at parse_plane (1)\n", NULL);
	if (!parse_xyz(splited[1], &vec))
		aterr_exit("Invalid Line at parse_plane (2)\n", NULL);
	pl->x = vec;
	if (!parse_dir(splited[2], &vec))
		aterr_exit("Invalid Line at parse_plane (3)\n", NULL);
	pl->normal = vec;
	if (!parse_rgb(splited[3], &vec))
		aterr_exit("Invalid Line at parse_plane (4)\n", NULL);
	pl->albedo = vec;
	obj->element = pl;
	obj->type = PL;
	oadd(&scene->world, obj);
}

/*
	cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
	identifier pl
	2. x,y,z
	3. normal
	4. diameter
	5. height
	6. rgb
*/
void	parse_cylinder(t_scene *scene, const char **splited)
{
	t_object *const		obj = ft_alert_calloc(sizeof(t_object));
	t_cylinder *const	cy = ft_alert_calloc(sizeof(t_cylinder));
	t_vec3				vec;
	double				d;

	if (ft_2d_char_arr_len(splited) != 6)
		aterr_exit("Invalid Line at parse_cylinder (1)\n", NULL);
	if (!parse_xyz(splited[1], &vec))
		aterr_exit("Invalid Line at parse_cylinder (2)\n", NULL);
	cy->center = vec;
	if (!parse_dir(splited[2], &vec))
		aterr_exit("Invalid Line at parse_cylinder (3)\n", NULL);
	cy->normal = vec;
	if (!ft_atod(splited[3], &d) || d <= 0)
		aterr_exit("Invalid Line at parse_cylinder (4)\n", NULL);
	cy->radius = d / 2;
	if (!ft_atod(splited[4], &cy->height) || d <= 0)
		aterr_exit("Invalid Line at parse_cylinder (5)\n", NULL);
	if (!parse_rgb(splited[5], &vec))
		aterr_exit("Invalid Line at parse_cylinder (6)\n", NULL);
	cy->albedo = vec;
	obj->element = cy;
	obj->type = CY;
	cy->center = vminus(cy->center, vmult(cy->normal, cy->height / 2));
	oadd(&scene->world, obj);
}

void	parse_cone(t_scene *scene, const char **splited)
{
	t_object *const		obj = ft_alert_calloc(sizeof(t_object));
	t_cone *const		cn = ft_alert_calloc(sizeof(t_cone));

	if (ft_2d_char_arr_len(splited) != 6)
		aterr_exit("Invalid Line at parse_cone (1)\n", NULL);
	if (!ft_atod(splited[1], &cn->theta) \
		|| !is_within(cn->theta, 0.0, 90.0, Nothing))
		aterr_exit("Invalid Line at parse_cone (2)\n", NULL);
	cn->theta = get_theta(cn->theta);
	cn->cos_theta = cos(cn->theta);
	cn->cos_theta2 = cn->cos_theta * cn->cos_theta;
	if (!ft_atod(splited[2], &cn->height) || cn->height <= 0)
		aterr_exit("Invalid Line at parse_cone (3)\n", NULL);
	cn->radius = cn->height * tan(cn->theta);
	if (!parse_xyz(splited[3], &cn->center))
		aterr_exit("Invalid Line at parse_cone (4)\n", NULL);
	if (!parse_dir(splited[4], &cn->v))
		aterr_exit("Invalid Line at parse_cone (5)\n", NULL);
	if (!parse_rgb(splited[5], &cn->albedo))
		aterr_exit("Invalid Line at parse_cone (6)\n", NULL);
	obj->element = cn;
	obj->type = CN;
	oadd(&scene->world, obj);
}
