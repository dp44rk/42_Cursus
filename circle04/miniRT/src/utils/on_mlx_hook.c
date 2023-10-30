/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:56 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:11:57 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	on_close(void *some_struct)
{
	(void)some_struct;
	exit(0);
}

int	on_key_press(int keycode, void *x)
{
	const char	*msg = "End Minirt by press esc\n";
	const int	msg_size = ft_strlen(msg);

	(void)x;
	if (keycode == KEY_ESC)
	{
		write(1, msg, msg_size);
		exit(0);
	}
	return (0);
}
