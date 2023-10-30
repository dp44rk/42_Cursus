/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:59 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:11:59 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	render(t_scene *scene, t_vec3 **pixels, int h, int w)
{
	int			u;
	int			v;

	*pixels = ft_alert_calloc(sizeof(t_vec3) * \
		scene->canvas.width * scene->canvas.height);
	v = h;
	while (--v >= 0)
	{
		u = -1;
		while (++u < w)
			(*pixels)[u + (v * w)] = ray_color(scene, (double)u, (double)v);
	}
}
