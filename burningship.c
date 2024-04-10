/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:43:32 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/10 15:10:36 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	loop_img_buringship(t_master *master)
{
	master->fract->x = -1;
	while (++(master->fract->x) < WINDOW_X)
	{
		master->fract->y = -1;
		while (++(master->fract->y) < WINDOW_Y)
			buringship(master);
	}
}

void	buringship(t_master *master)
{
	clear_px(master);
	master->px->b = (((WINDOW_Y / -2) + master->fract->y) / master->scale) + master->fract->horizontal_shift - 0.5;
	master->px->a = (((WINDOW_X / -2) + master->fract->x) / master->scale) + master->fract->vertical_shift - 0.5;
	master->px->ca = master->px->a;
	master->px->cb = master->px->b;
	while (master->px->i < master->iterations)
	{
		master->px->aa = master->px->a * master->px->a - master->px->b * master->px->b;
		master->px->bb = 2 * fabs(master->px->a * master->px->b);
		master->px->a = master->px->aa + master->px->ca;
		master->px->b = master->px->bb + master->px->cb;
		if ((master->px->a * master->px->a + master->px->b * master->px->b) > 16)
			break ;
		master->px->i++;
	}
	if (master->px->i == master->iterations)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_grey(0, 255));
	else if (master->px->i > 0)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(master->px->i, 255, master));
	else
		mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_grey(0, 255));
}
