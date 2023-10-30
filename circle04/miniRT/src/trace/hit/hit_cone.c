/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:32 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:32 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

static t_bool	_hit_cone_plane(t_cone *cn, t_ray *ray, t_hit_record *rec, \
								t_vec3 center)
{
	const double	numerator = vdot(vminus(center, ray->orig), cn->v);
	const double	denominator = vdot(ray->dir, cn->v);
	t_point3		p;
	double			time;

	if (denominator == 0)
		return (FALSE);
	time = numerator / denominator;
	if (!is_within(time, rec->tmin, rec->tmax, Nothing))
		return (FALSE);
	p = ray_at(ray, time);
	if (vlength(vminus(p, center)) > cn->radius)
		return (FALSE);
	rec->p = p;
	rec->t = time;
	rec->tmax = time;
	rec->normal = cn->v;
	if (vdot(ray->dir, rec->normal) >= 0)
		rec->normal = vmult(rec->normal, -1);
	return (TRUE);
}

static t_bool	_check_height(const t_cone *cn, const t_ray *ray, t_vec3 co, \
								double time)
{
	const t_vec3	cp = vplus(co, vmult(ray->dir, time));
	const double	h = vdot(cp, cn->v);

	return (is_within(h, 0, cn->height, Nothing));
}

static t_bool	_cal_root(const t_cone *cn, t_ray *ray, \
									t_hit_record *rec, t_vec3 co)
{
	const double	a = vdot(ray->dir, cn->v) * vdot(ray->dir, cn->v) - \
						cn->cos_theta2;
	const double	half_b = vdot(ray->dir, cn->v) * vdot(co, cn->v) - \
							vdot(ray->dir, co) * cn->cos_theta2;
	const double	c = vdot(co, cn->v) * vdot(co, cn->v) - vdot(co, co) * \
						cn->cos_theta2;
	double			discriminant;
	double			root;

	discriminant = (half_b * half_b) - (a * c);
	if (discriminant < EPSILON)
		return (FALSE);
	discriminant = sqrt(discriminant);
	root = (-half_b - discriminant) / a;
	if (!is_within(root, rec->tmin, rec->tmax, Nothing) || \
		!_check_height(cn, ray, co, root))
		root = (-half_b + discriminant) / a;
	if (!is_within(root, rec->tmin, rec->tmax, Nothing) || \
		!_check_height(cn, ray, co, root))
		return (FALSE);
	rec->t = root;
	return (TRUE);
}

static t_bool	_hit_cone_side(t_cone *cn, t_ray *ray, t_hit_record *rec)
{
	t_vec3			cp;
	const t_vec3	co = vminus(ray->orig, cn->center);

	if (!_cal_root(cn, ray, rec, co))
		return (FALSE);
	rec->tmax = rec->t;
	rec->p = ray_at(ray, rec->t);
	cp = vplus(co, vmult(ray->dir, rec->t));
	rec->normal = vunit(vminus(vdivide(vmult(cp, vdot(cn->v, cp)), \
										vdot(cp, cp)), cn->v));
	return (TRUE);
}

t_bool	hit_cone(t_cone *cn, t_ray *r, t_hit_record *rec)
{
	t_bool			is_hit[2];
	const t_vec3	center = vplus(cn->center, vmult(cn->v, cn->height));

	is_hit[0] = _hit_cone_side((t_cone *)cn, r, rec);
	is_hit[1] = _hit_cone_plane((t_cone *)cn, r, rec, center);
	if (!is_hit[0] && !is_hit[1])
		return (FALSE);
	rec->albedo = cn->albedo;
	return (TRUE);
}
