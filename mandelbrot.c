/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:14:43 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/24 17:36:12 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(mlx_image_t *img, t_fractol fract)
{
	static t_pixel	pixel;

	clear_pixel(&pixel);
	pixel.b = ((fract.window_y / -2) + fract.y) / 400;
	pixel.a = (((fract.window_x / -2) + fract.x) / 400) - 0.5;
	pixel.ca = pixel.a;
	pixel.cb = pixel.b;
	while (pixel.i < 500)
	{
		pixel.aa = pixel.a * pixel.a - pixel.b * pixel.b;
		pixel.bb = 2 * pixel.a * pixel.b;
		pixel.a = pixel.aa + pixel.ca;
		pixel.b = pixel.bb + pixel.cb;
		if ((pixel.a + pixel.b) > 16)
			break ;
		pixel.i++;
	}
	if (pixel.i == 500)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 0, 0, 255));
	else if (pixel.i > 40)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(255, 255, 255, 255));
	else if (pixel.i > 35)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 255, 0, 255));
	else if (pixel.i > 27)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 200, 50, 255));
	else if (pixel.i > 26)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 150, 90, 255));
	else if (pixel.i > 23)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 50, 200, 255));
	else if (pixel.i > 20)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 0, 255, 255));
	else if (pixel.i > 17)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(50, 0, 150, 255));
	else if (pixel.i > 16)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(150, 0, 100, 255));
	else if (pixel.i > 15)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(255, 0, 0, 255));
	else if (pixel.i > 14)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(255, 0, 180, 255));
	else
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 0, 0, 255));
}
