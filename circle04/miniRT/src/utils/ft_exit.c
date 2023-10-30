/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:46 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:11:47 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	aterr_exit(const char *s1, const char *s2)
{
	const char	*err_msg = "Error\n";
	const int	err_msg_size = ft_strlen(err_msg);

	write(STDERR_FILENO, err_msg, err_msg_size);
	if (s1)
		write(STDERR_FILENO, s1, ft_strlen(s1));
	if (s2)
		write(STDERR_FILENO, s2, ft_strlen(s2));
	exit(1);
}
