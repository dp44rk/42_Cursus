/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:11:28 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:11:32 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	_ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	_draw_pixel(t_data *data, t_color3 *pixel, int x, int y)
{
	const int	trgb = _create_trgb((0), \
									(int)(255.999 * pixel->x), \
									(int)(255.999 * pixel->y), \
									(int)(255.999 * pixel->z));

	_ft_mlx_pixel_put(data, x, y, trgb);
}

void	draw_image(t_data *x)
{
	int				i;
	int				j;
	t_vec3 *const	pixels = x->pixels;

	j = x->h;
	while (--j >= 0)
	{
		i = -1;
		while (++i < x->w)
			_draw_pixel(x, &pixels[i + (j * x->w)], i, x->h - j);
	}
}
