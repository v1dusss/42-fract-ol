/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:38:17 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/06 20:15:18 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int map(int y)
{
	int in_min;
	int in_max;
	int out_min;
	int out_max;
	
	in_min = 0;
	in_max = MAX_ITERATIONS;
	out_min = 0;
	out_max = 255;
	return (sqrt(y / (255.0 / (MAX_ITERATIONS * MAX_ITERATIONS * 2))));
	// return ((y - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

void	loop_img_julia(t_master *master)
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
				julia(master);
	}
	mlx_image_to_window(master->mlx, master->img, 0, 0);
}

void	julia(t_master *master)
{
	clear_px(master->px);
	master->px->b = ((master->window_y / -2) + master->fract->y)
		/ (master->window_y / 2.3);
	master->px->a = ((master->window_x / -2) + master->fract->x)
			/ (master->window_y / 2.3);
	while (++master->px->i < MAX_ITERATIONS)
	{
		master->px->aa = master->px->a * master->px->a
			- master->px->b * master->px->b;
		master->px->bb = 2 * master->px->a * master->px->b;
		master->px->a = master->px->aa + master->fract->ca;
		master->px->b = master->px->bb + master->fract->cb;
		if ((master->px->a * master->px->a + master->px->b * master->px->b) > 16)
			break ;
	}
	if (master->px->i == MAX_ITERATIONS)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(0, 0, 0, 255));
	else
		mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(map(master->px->i), map(master->px->i), map(master->px->i), 255));
}
