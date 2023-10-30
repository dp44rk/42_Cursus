/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:20 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:20 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_bool	parse_rgb(const char *s, t_color3 *dest)
{
	t_bool		is_valid;
	const char	**splited = (const char	**)ft_alert_split(s, ',');

	is_valid = FALSE;
	if (ft_2d_char_arr_len((const char **)splited) == 3)
	{
		if (\
		(ft_atod(splited[0], &dest->x) && \
		is_within(dest->x, 0.0, 255, Both)) && \
		(ft_atod(splited[1], &dest->y) && \
		is_within(dest->y, 0.0, 255, Both)) && \
		(ft_atod(splited[2], &dest->z) && \
		is_within(dest->z, 0.0, 255, Both)))
		{
			is_valid = TRUE;
			*dest = vdivide(*dest, 255.0);
		}
	}
	ft_2d_char_arr_free((char **)splited);
	return (is_valid);
}

t_bool	parse_xyz(const char *s, t_point3 *dest)
{
	t_bool		is_valid;
	const char	**splited = (const char	**)ft_alert_split(s, ',');

	is_valid = FALSE;
	if (ft_2d_char_arr_len((const char **)splited) == 3)
	{
		if (\
			ft_atod(splited[0], &dest->x) && \
			ft_atod(splited[1], &dest->y) && \
			ft_atod(splited[2], &dest->z))
			is_valid = TRUE;
	}
	ft_2d_char_arr_free((char **)splited);
	return (is_valid);
}

t_bool	parse_dir(const char *s, t_color3 *dest)
{
	t_bool		is_valid;
	const char	**splited = (const char	**)ft_alert_split(s, ',');

	is_valid = FALSE;
	if (ft_2d_char_arr_len((const char **)splited) == 3)
	{
		if (\
		(ft_atod(splited[0], &dest->x) && \
		is_within(dest->x, -1.0, 1.0, Both)) && \
		(ft_atod(splited[1], &dest->y) && \
		is_within(dest->y, -1.0, 1.0, Both)) && \
		(ft_atod(splited[2], &dest->z) && \
		is_within(dest->z, -1.0, 1.0, Both)))
		{
			is_valid = TRUE;
			*dest = vunit(*dest);
		}
	}
	ft_2d_char_arr_free((char **)splited);
	return (is_valid);
}
