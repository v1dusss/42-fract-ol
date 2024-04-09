/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:46:11 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/09 17:13:57 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void key_pres_julia(t_master *master, mlx_key_data_t key_data)
{
	if (key_data.key == MLX_KEY_W)
		master->px->cb += 0.0002;
	if (key_data.key == MLX_KEY_S)
		master->px->cb -= 0.0002;
	if (key_data.key == MLX_KEY_A)
		master->px->ca -= 0.0002;
	if (key_data.key == MLX_KEY_D)
		master->px->ca += 0.0002;
	loop_img_julia(master);
}

void	key_stadart(t_master *master, mlx_key_data_t key_data)
{
	int x;

	x = 15;
	if (key_data.key == MLX_KEY_KP_ADD || key_data.key == MLX_KEY_KP_SUBTRACT)
	{
		if (key_data.key == MLX_KEY_KP_SUBTRACT)
			master->iterations -= 10;
		else
			master->iterations += 10;
		ft_printf("ITERATIONS = %d\n", master->iterations);
	}
	if (key_data.key == MLX_KEY_R || key_data.key == MLX_KEY_G || key_data.key == MLX_KEY_B)
	{
		if (mlx_is_key_down(master->mlx, MLX_KEY_LEFT_SHIFT))
			x = -15;
		if (key_data.key == MLX_KEY_R)
			master->r += x;
		else if (key_data.key == MLX_KEY_B)
			master->b += x;
		else
			master->g += x;
		ft_printf("R = %d\nG = %d\nB = %d\n", master->r, master->g, master->b);
	}
}

void	key_pres(mlx_key_data_t key_data, void *data)
{
	t_master	*master;

	if (key_data.action != MLX_PRESS)
		return ;
	master = (t_master *)data;
	if (key_data.key == MLX_KEY_ESCAPE)
		exit(0);
	if (key_data.key == MLX_KEY_KP_ADD || key_data.key == MLX_KEY_KP_SUBTRACT || key_data.key == MLX_KEY_R || key_data.key == MLX_KEY_G || key_data.key == MLX_KEY_B)
		key_stadart((t_master *)data, key_data);
	if (key_data.key == MLX_KEY_UP)
		master->fract->horizontal_shift -= 0.1;
	if (key_data.key == MLX_KEY_DOWN)
		master->fract->horizontal_shift += 0.1;
	if (key_data.key == MLX_KEY_LEFT)
		master->fract->vertical_shift -= 0.1;
	if (key_data.key == MLX_KEY_RIGHT)
		master->fract->vertical_shift += 0.1;
	if (master->set == MANDELBROT)
		loop_img_mandelbrot(master);
	else if (master->set == JULIA)
		key_pres_julia(master, key_data);
	else
		loop_img_buringship(master);
	ft_printf("=======\n");
}

void	mouseaction(double a, double b, void *params)
{
	double	multiplier;
	t_master	*master;

	(void)a;
	master = (t_master *)params;
	ft_printf("MOUSE SCROLL\n");
	if (b > 0)
		multiplier = 1.1;
	else
		multiplier = 0.9;
	master->scale *= multiplier;
	if (master->set == MANDELBROT)
		loop_img_mandelbrot(master);
	else if (master->set == JULIA)
		loop_img_julia(master);
	else
		loop_img_buringship(master);
}
