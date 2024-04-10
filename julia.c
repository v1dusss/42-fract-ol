/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:38:17 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/10 21:00:12 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	loop_img_julia(t_master *master)
{
	master->fract->x = -1;
	while (++(master->fract->x) < WINDOW_X)
	{
		master->fract->y = -1;
		while (++(master->fract->y) < WINDOW_Y)
			julia(master);
	}
}

void	julia(t_master *master)
{
	clear_px(master);
	master->px->b = (((WINDOW_Y / -2) + master->fract->y) / master->scale)
		+ master->fract->horizontal_shift;
	master->px->a = (((WINDOW_X / -2) + master->fract->x) / master->scale)
		+ master->fract->vertical_shift;
	while (++master->px->i < master->iterations)
	{
		master->px->aa = master->px->a * master->px->a - master->px->b
			* master->px->b;
		master->px->bb = 2 * master->px->a * master->px->b;
		master->px->a = master->px->aa + master->px->ca;
		master->px->b = master->px->bb + master->px->cb;
		if ((master->px->a * master->px->a + master->px->b
				* master->px->b) > 16)
			break ;
	}
	if (master->px->i == master->iterations || master->px->i == 0)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_grey(0, 255));
	else if (master->px->i > 0)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y,
			get_rgb_a(master->px->i, 255, master));
}
