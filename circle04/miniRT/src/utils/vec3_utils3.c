/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:12:15 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:12:16 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

// 벡터 스칼라 나누기
t_vec3	vdivide(t_vec3 vec1, double t)
{
	t_vec3	vec;

	if (t == 0)
		aterr_exit("Devider is 0\n", NULL);
	vec.x = vec1.x / t;
	vec.y = vec1.y / t;
	vec.z = vec1.z / t;
	return (vec);
}

// 벡터 내적
double	vdot(t_vec3 vec1, t_vec3 vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

// 벡터 외적
t_vec3	vcross(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec.x = vec1.y * vec2.z - vec1.z * vec2.y;
	vec.y = vec1.z * vec2.x - vec1.x * vec2.z;
	vec.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (vec);
}

// 단위 벡터
t_vec3	vunit(t_vec3 vec1)
{
	t_vec3			vec;
	const double	len = vlength(vec1);

	vec = vdivide(vec1, len);
	return (vec);
}

// 두 벡터의 원소를 비교하여 작은 값들만 반환 
t_vec3	vmin(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec = vec1;
	if (vec1.x > vec2.x)
		vec.x = vec2.x;
	if (vec1.y > vec2.y)
		vec.y = vec2.y;
	if (vec1.z > vec2.z)
		vec.z = vec2.z;
	return (vec);
}
