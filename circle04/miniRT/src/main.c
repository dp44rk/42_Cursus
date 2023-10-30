/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:15 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:16 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	_ft_mlx_init(t_scene *scene, t_data	*x)
{
	x->mlx_ptr = mlx_init();
	if (!x->mlx_ptr)
		aterr_exit("Fail to mlx_init()\n", NULL);
	x->h = scene->canvas.height;
	x->w = scene->canvas.width;
	x->win_ptr = mlx_new_window(x->mlx_ptr, x->w, x->h, "window_name");
	if (!x->win_ptr)
		aterr_exit("Fail to mlx_new_window()\n", NULL);
	x->img = mlx_new_image(x->mlx_ptr, x->w, x->h);
	x->addr = mlx_get_data_addr(x->img, &x->bits_per_pixel, \
								&x->line_length, &x->endian);
}

int	main(int ac, char **av)
{
	t_scene	scene;
	t_data	x;

	if (ac != 2)
		aterr_exit("Invalid Argument\n", NULL);
	scene_init(&scene);
	file_check(&scene, (const char *)av[1]);
	render(&scene, &x.pixels, scene.canvas.height, scene.canvas.width);
	_ft_mlx_init(&scene, &x);
	draw_image(&x);
	mlx_put_image_to_window(x.mlx_ptr, x.win_ptr, x.img, 0, 0);
	mlx_hook(x.win_ptr, X_EVENT_KEY_RELEASE, 0, &on_key_press, NULL);
	mlx_hook(x.win_ptr, X_EVENT_CLOSE, 0, &on_close, NULL);
	mlx_loop(x.mlx_ptr);
	return (0);
}
