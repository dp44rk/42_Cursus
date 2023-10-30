/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:34 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:34 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

static t_bool	_hit_cylinder_plane(const t_cylinder *cy, t_ray *ray, \
	t_hit_record *rec, t_vec3 center)
{
	const double	numerator = vdot(vminus(center, ray->orig), cy->normal);
	const double	denominator = vdot(ray->dir, cy->normal);
	t_vec3			p;
	double			time;

	if (denominator == 0)
		return (FALSE);
	time = numerator / denominator;
	if (!is_within(time, rec->tmin, rec->tmax, Nothing))
		return (FALSE);
	p = ray_at(ray, time);
	if (vlength(vminus(p, center)) > cy->radius)
		return (FALSE);
	rec->p = p;
	rec->t = time;
	rec->tmax = time;
	rec->normal = cy->normal;
	if (vdot(ray->dir, rec->normal) >= 0)
		rec->normal = vmult(rec->normal, -1);
	return (TRUE);
}

static t_bool	_check_side2(
		const t_cylinder *cy, t_ray *ray, t_hit_record *rec, double root)
{
	t_vec3		p;
	t_vec3		cp;
	t_vec3		cq;
	double		q_height;

	p = ray_at(ray, root);
	cp = vminus(p, cy->center);
	cq = vmult(cy->normal, vdot(cp, cy->normal));
	q_height = vdot(cp, cy->normal);
	if (!is_within(q_height, 0, cy->height, Both))
		return (FALSE);
	rec->p = p;
	rec->t = root;
	rec->tmax = root;
	rec->normal = vunit(vminus(cp, cq));
	if (vdot(ray->dir, rec->normal) >= 0)
		rec->normal = vmult(rec->normal, -1);
	return (TRUE);
}

static t_bool	_check_side1(const t_cylinder *cy, t_ray *ray, \
								t_hit_record *rec, double root)
{
	const t_vec3	co = vminus(ray->orig, cy->center);
	const double	a = 1 - pow(vdot(ray->dir, cy->normal), 2);
	const double	half_b = vdot(co, ray->dir) - vdot(ray->dir, cy->normal) * \
								vdot(co, cy->normal);
	const double	c = vlength2(co) - pow(vdot(co, cy->normal), 2) \
										- pow(cy->radius, 2);
	double			discriminant;

	discriminant = (half_b * half_b) - (a * c);
	if (discriminant < 0.00001)
		return (FALSE);
	discriminant = sqrt(discriminant);
	root = (-half_b - discriminant) / a;
	if (!is_within(root, rec->tmin, rec->tmax, Nothing) || \
		!_check_side2(cy, ray, rec, root))
	{
		root = (-half_b + discriminant) / a;
		if (!is_within(root, rec->tmin, rec->tmax, Nothing) || \
			!_check_side2(cy, ray, rec, root))
			return (FALSE);
	}
	return (TRUE);
}

t_bool	hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_bool				is_hit[3];

	is_hit[0] = FALSE;
	is_hit[1] = FALSE;
	is_hit[0] = _hit_cylinder_plane(cy, ray, rec, \
		vplus(cy->center, vmult(cy->normal, 0)));
	is_hit[1] = _hit_cylinder_plane(cy, ray, rec, \
		vplus(cy->center, vmult(cy->normal, cy->height)));
	is_hit[2] = _check_side1(cy, ray, rec, 0);
	if (!is_hit[0] && !is_hit[1] && !is_hit[2])
		return (FALSE);
	rec->albedo = cy->albedo;
	return (TRUE);
}
