/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:14:43 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/06 20:16:50 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	loop_img_mandelbrot(t_master *master)
{
	if (master->img)
	{
		mlx_delete_image(master->mlx, master->img);
		printf("img deleted\n");
	}
	master->img = mlx_new_image(master->mlx, master->window_x,
			master->window_y);
	printf("img created\n");
	master->fract->x = -1;
	while (++(master->fract->x) < master->window_x)
	{
		master->fract->y = -1;
		while (++(master->fract->y) < master->window_y)
			mandelbrot(master);
	}
	mlx_image_to_window(master->mlx, master->img, 0, 0);
}

void	mandelbrot(t_master *master)
{
	clear_px(master->px);
	master->px->b = (((master->window_y / -2) + master->fract->y) / 350);
	master->px->a = (((master->window_x / -2) + master->fract->x) / 350)
		- 0.5;
	master->px->ca = master->px->a;
	master->px->cb = master->px->b;
	while (master->px->i < MAX_ITERATIONS)
	{
		master->px->aa = master->px->a * master->px->a - master->px->b
			* master->px->b;
		master->px->bb = 2 * master->px->a * master->px->b;
		master->px->a = master->px->aa + master->px->ca;
		master->px->b = master->px->bb + master->px->cb;
		if ((master->px->a * master->px->a + master->px->b * master->px->b) > 16)
			break ;
		master->px->i++;
	}
	if (master->px->i == MAX_ITERATIONS)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(0, 0, 0, 255));
	else if (master->px->i > 45)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(255, 255, 255, 255));
	else
		mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(map(master->px->i), map(master->px->i), map(master->px->i), 255));
}