/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_char_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:37 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:11:38 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	ft_2d_char_arr_free(char **arr2)
{
	t_size	i;

	if (arr2 == NULL)
		return ;
	i = 0;
	while (arr2[i])
		free(arr2[i++]);
	free(arr2);
}

t_size	ft_2d_char_arr_len(const char **arr)
{
	t_size	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
