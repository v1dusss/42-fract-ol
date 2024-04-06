/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:38:17 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/27 20:05:56 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_master *master)
{
	if (master->fract->y == 0 && master->fract->x == 0)
		printf("cb: %F\nca: %F\n", master->fract->cb, master->fract->ca);
	clear_px(master->px);
	master->px->b = ((master->fract->window_y / -2) + master->fract->y)
		/ (master->fract->window_y / 2.3);
	master->px->a = ((master->fract->window_x / -2) + master->fract->x)
			/ (master->fract->window_y / 2.3);
	while (++master->px->i < 500)
	{
		master->px->aa = master->px->a * master->px->a
			- master->px->b * master->px->b;
		master->px->bb = 2 * master->px->a * master->px->b;
		master->px->a = master->px->aa + master->fract->ca;
		master->px->b = master->px->bb + master->fract->cb;
		if ((master->px->a + master->px->b) > 16)
			break ;
	}
	if (master->px->i == 500)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(0, 0, 0, 255));
	else
		mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(master->px->i * 255 / 500, master->px->i * 255 / 500, master->px->i * 255 / 500, 255));
	
	//if (master->fract->x == (master->fract->window_x / 2) || master->fract->y == (master->fract->window_y / 2))
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(255, 255, 255, 255));
	//else if (master->px->i == 500)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(0, 0, 0, 255));
	//else if (master->px->i > 50)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(255, 255, 255, 255));
	//else if (master->px->i > 45)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(0, 255, 0, 255));
	//else if (master->px->i > 40)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(0, 200, 50, 255));
	//else if (master->px->i > 37)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(0, 150, 90, 255));
	//else if (master->px->i > 35)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(0, 50, 200, 255));
	//else if (master->px->i > 32)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(0, 0, 255, 255));
	//else if (master->px->i > 29)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(50, 0, 150, 255));
	//else if (master->px->i > 27)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(150, 0, 100, 255));
	//else if (master->px->i > 25)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(255, 0, 0, 255));
	//else if (master->px->i > 23)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(255, 0, 180, 255));
	//else
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(0, 0, 0, 255));
}
