/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:12:06 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:12:07 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_bool	ft_ext_cmp(const char *ext, const char *path)
{
	const t_size	ext_size = ft_strlen(ext);
	const t_size	path_size = ft_strlen(path);

	return (path_size >= ext_size && \
			ft_strcmp(".rt", path + path_size - 3) == 0);
}
