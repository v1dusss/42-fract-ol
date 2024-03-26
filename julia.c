/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:38:17 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/26 17:55:56 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	julia(t_master master)
// {
// 	// del image
// 	// create image
// 	// while loop
// 	// 	mlx_put_pixel
// 	// mlx_image_to_window
// }

void	julia(t_master *master)
{
	// printf("%f %f\n", master->fract->y, master->fract->x);
	if (master->fract->y == 0 && master->fract->x == 0)
		printf("%F\n", master->fract->cb);
	clear_pixel(master->pixel);
	// printf("fract->cb: %f\n", master->fract->cb);
	master->pixel->b = ((master->fract->window_y / -2) + master->fract->y)
		/ 350;
	master->pixel->a = (((master->fract->window_x / -2) + master->fract->x)
			/ 350);
	while (master->pixel->i < 500)
	{
		master->pixel->aa = master->pixel->a * master->pixel->a
			- master->pixel->b * master->pixel->b;
		master->pixel->bb = 2 * master->pixel->a * master->pixel->b;
		master->pixel->a = master->pixel->aa + master->fract->ca;
		master->pixel->b = master->pixel->bb + master->fract->cb;
		if ((master->pixel->a + master->pixel->b) > 16)
			break ;
		master->pixel->i++;
	}
	if (master->pixel->i == 500)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(0, 0, 0, 255));
	else if (master->pixel->i > 50)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(255, 255, 255, 255));
	else if (master->pixel->i > 45)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(0, 255, 0, 255));
	else if (master->pixel->i > 40)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(0, 200, 50, 255));
	else if (master->pixel->i > 37)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(0, 150, 90, 255));
	else if (master->pixel->i > 35)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(0, 50, 200, 255));
	else if (master->pixel->i > 32)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(0, 0, 255, 255));
	else if (master->pixel->i > 29)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(50, 0, 150, 255));
	else if (master->pixel->i > 27)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(150, 0, 100, 255));
	else if (master->pixel->i > 25)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(255, 0, 0, 255));
	else if (master->pixel->i > 23)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(255, 0, 180, 255));
	else
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(0, 0, 0, 255));
}
