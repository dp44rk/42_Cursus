/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:27 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:27 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_bool	is_empty_or_annotaion_line(const char *line)
{
	while (*line == ' ')
		line++;
	return (*line == '\0' || *line == '#');
}

double	_theta_to_radian(double theta)
{
	static const double	radian = M_PI / 180;

	return (theta * radian);
}

double	ft_get_focal_len(double viewport_w, double fov)
{
	const double	radian = _theta_to_radian(fov / 2.0);
	const double	a = viewport_w / 2;
	const double	b = tan(radian);

	return (a / b);
}
