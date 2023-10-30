/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:37 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:37 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

static t_bool	_cal_root_sphere(const t_sphere *sp, t_ray *ray, \
									t_hit_record *rec, double root)
{
	const t_vec3	oc = vminus(ray->orig, sp->center);
	const double	a = vlength2(ray->dir);
	const double	half_b = vdot(oc, ray->dir);
	const double	c = vlength2(oc) - sp->radius2;
	double			discriminant;

	discriminant = (half_b * half_b) - (a * c);
	if (discriminant < 0.00001)
		return (FALSE);
	discriminant = sqrt(discriminant);
	root = (-half_b - discriminant) / a;
	if (root < rec->tmin || rec->tmax < root)
		root = (-half_b + discriminant) / a;
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	return (TRUE);
}

t_bool	hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	if (!_cal_root_sphere(sp, ray, rec, 0))
		return (FALSE);
	rec->p = ray_at(ray, rec->t);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);
	if (vdot(ray->dir, rec->normal) >= 0)
		rec->normal = vmult(rec->normal, -1);
	rec->albedo = sp->albedo;
	return (TRUE);
}
