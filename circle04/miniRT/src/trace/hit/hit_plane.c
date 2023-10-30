/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:35 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:36 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/structures.h"
#include "../../../include/utils.h"
#include "../../../include/trace.h"

t_bool	hit_plane(t_plane *pl, t_ray *ray, t_hit_record *rec)
{
	const double	denominator = vdot(ray->dir, pl->normal);
	const double	numerator = vdot(vminus(pl->x, ray->orig), pl->normal);
	double			t;

	if (denominator == 0)
		return (FALSE);
	t = numerator / denominator;
	if (t < rec->tmin || t > rec->tmax)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(ray, rec->t);
	rec->normal = pl->normal;
	if (vdot(ray->dir, rec->normal) >= 0)
		rec->normal = vmult(rec->normal, -1);
	rec->albedo = pl->albedo;
	return (TRUE);
}
