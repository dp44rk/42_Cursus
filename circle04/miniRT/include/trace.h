/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:12:57 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:12:57 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

/* trace/ray.c */
t_ray		ray(t_point3 orig, t_vec3 dir);
t_point3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_color3	ray_color(t_scene *scene, double u, double v);
t_vec3		reflect(t_vec3 v, t_vec3 n);
t_vec3		diffuse_color(t_scene *scene, t_light *light, t_vec3 light_dir);
t_vec3		specular_color(t_scene *scene, t_light *light, \
							t_vec3 light_unit_dir);

// trace/ray/is_in_shadow.c
t_bool		is_in_shadow(t_scene *scene, t_light *light);

/* trace/ray/ */
t_color3	phong_lighting(t_scene *scene);
t_color3	point_light_get(t_scene *scene, t_light *light);

/* trace/hit/ */
t_bool		hit(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_plane *pl, t_ray *light_ray, t_hit_record *rec);
t_bool		hit_cylinder(t_cylinder *cy, t_ray *light_ray, t_hit_record *rec);
t_bool		hit_cone(t_cone *cn, t_ray *ray, t_hit_record *rec);
void		set_face_normal(t_ray *r, t_hit_record *rec);

#endif