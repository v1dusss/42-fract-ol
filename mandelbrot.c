/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:14:43 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/07 16:24:57 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	loop_img_mandelbrot(t_master *master)
{
	master->fract->x = -1;
	master->fract->y = -1;
	if (master->img)
		mlx_delete_image(master->mlx, master->img);
	ft_printf("img deleted\n");
	master->img = mlx_new_image(master->mlx, WINDOW_X,
			WINDOW_Y);
	ft_printf("img created\n");
	master->fract->x = -1;
	while (++(master->fract->x) < WINDOW_X)
	{
		master->fract->y = -1;
		while (++(master->fract->y) < WINDOW_Y)
			mandelbrot(master);
	}
	mlx_image_to_window(master->mlx, master->img, 0, 0);
}

void	mandelbrot(t_master *master)
{
	clear_px(master->px);
	master->px->b = (((WINDOW_Y / -2) + master->fract->y) / 350);
	master->px->a = (((WINDOW_X / -2) + master->fract->x) / 350)
		- 0.5;
	master->px->ca = master->px->a;
	master->px->cb = master->px->b;
	while (master->px->i < master->iterations)
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
	if (master->px->i == master->iterations)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_grey(0, 255));
	else
		mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_grey(map(master), 255));
}
