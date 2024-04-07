/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:46:11 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/07 16:34:36 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_pres(mlx_key_data_t key_data, void *data)
{
	t_master	*master;

	if(key_data.action != MLX_PRESS)
		return ;
	ft_printf("*************************\n");
	master = (t_master *)data;
	if (key_data.key == MLX_KEY_ESCAPE)
		exit(0);
	else if (key_data.key == MLX_KEY_KP_ADD || key_data.key == MLX_KEY_KP_SUBTRACT)
	{
		if (key_data.key == MLX_KEY_KP_ADD)
			master->iterations += 25;
		else
			master->iterations -= 25;
		if (master->set == MANDELBROT)
			loop_img_mandelbrot(master);
		else
			loop_img_julia(master);
		ft_printf("ITERATIONS = %d\n", master->iterations);
	}
	else if (master->set == JULIA)
		key_pres_julia(master, key_data);
}

void key_pres_julia(t_master *master, mlx_key_data_t key_data)
{
	if (key_data.key == MLX_KEY_UP)
	{
		master->fract->cb += 0.0002;
		loop_img_julia(master);
		ft_printf("CB += 0.0002\n");
	}
	if (key_data.key == MLX_KEY_DOWN)
	{
		master->fract->cb -= 0.0002;
		loop_img_julia(master);
		ft_printf("CB -= 0.0002\n");
	}
	if (key_data.key == MLX_KEY_LEFT)
	{
		master->fract->ca -= 0.0002;
		loop_img_julia(master);
		ft_printf("CA -= 0.0002\n");
	}
	if (key_data.key == MLX_KEY_RIGHT)
	{
		master->fract->ca += 0.0002;
		loop_img_julia(master);
		ft_printf("CA += 0.0002\n");
	}
}
