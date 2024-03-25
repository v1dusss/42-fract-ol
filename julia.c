/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:38:17 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/25 19:42:31 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(mlx_image_t *img, t_fractol fract)
{
	static t_pixel	pixel;

	clear_pixel(&pixel);
	pixel.b = ((fract.window_y / -2) + fract.y) / 350;
	pixel.a = (((fract.window_x / -2) + fract.x) / 350);
	while (pixel.i < 1000)
	{
		pixel.aa = pixel.a * pixel.a - pixel.b * pixel.b;
		pixel.bb = 2 * pixel.a * pixel.b;
		pixel.a = pixel.aa + fract.ca;
		pixel.b = pixel.bb + fract.cb;
		if ((pixel.a + pixel.b) > 16)
			break ;
		pixel.i++;
	}
	if (pixel.i == 1000)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 0, 0, 255));
	else if (pixel.i > 50)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(255, 255, 255, 255));
	else if (pixel.i > 45)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 255, 0, 255));
	else if (pixel.i > 40)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 200, 50, 255));
	else if (pixel.i > 37)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 150, 90, 255));
	else if (pixel.i > 35)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 50, 200, 255));
	else if (pixel.i > 32)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 0, 255, 255));
	else if (pixel.i > 29)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(50, 0, 150, 255));
	else if (pixel.i > 27)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(150, 0, 100, 255));
	else if (pixel.i > 25)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(255, 0, 0, 255));
	else if (pixel.i > 23)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(255, 0, 180, 255));
	else
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 0, 0, 255));
}
