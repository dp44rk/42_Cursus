/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:12:18 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:12:18 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minirt.h"

t_vec3	vmax(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec = vec1;
	if (vec1.x < vec2.x)
		vec.x = vec2.x;
	if (vec1.y < vec2.y)
		vec.y = vec2.y;
	if (vec1.z < vec2.z)
		vec.z = vec2.z;
	return (vec);
}
