/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:12:12 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:12:13 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

// 벡터 길이
double	vlength(t_vec3 vec)
{
	return (sqrt(vlength2(vec)));
}

// 벡터합
t_vec3	vplus(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	vec.z = vec1.z + vec2.z;
	return (vec);
}

// 벡터차
t_vec3	vminus(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	vec.z = vec1.z - vec2.z;
	return (vec);
}

// 벡터 * 스칼라 곱연산, scalar multipliation
t_vec3	vmult(t_vec3 vec1, double t)
{
	t_vec3	vec;

	vec.x = vec1.x * t;
	vec.y = vec1.y * t;
	vec.z = vec1.z * t;
	return (vec);
}

// 벡터 축 값끼리 곱연산
t_vec3	vmult_(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec.x = vec1.x * vec2.x;
	vec.y = vec1.y * vec2.y;
	vec.z = vec1.z * vec2.z;
	return (vec);
}
