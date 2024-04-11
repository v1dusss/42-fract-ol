/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:46:11 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/11 16:09:44 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_pres_julia(t_master *master, mlx_key_data_t key_data)
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

void	key_rgb(t_master *master, mlx_key_data_t key_data)
{
	int	x;

	x = 1;
	if (mlx_is_key_down(master->mlx, MLX_KEY_LEFT_SHIFT)
		|| mlx_is_key_down(master->mlx, MLX_KEY_RIGHT_SHIFT))
		x *= -1;
	if (key_data.key == MLX_KEY_R)
		master->r += x;
	else if (key_data.key == MLX_KEY_B)
		master->b += x;
	else if (key_data.key == MLX_KEY_G)
		master->g += x;
	ft_printf("R = %d\nG = %d\nB = %d\n", master->r, master->g, master->b);
	ft_printf("=======\n");
}
void	key_iterations(t_master *master, mlx_key_data_t key_data)
{
	int	x;

	x = 1;
	if (mlx_is_key_down(master->mlx, MLX_KEY_LEFT_SHIFT)
		|| mlx_is_key_down(master->mlx, MLX_KEY_RIGHT_SHIFT))
		x = 10;
	if (key_data.key == MLX_KEY_KP_SUBTRACT)
		master->iterations -= 10 / x;
	else if (key_data.key == MLX_KEY_KP_ADD)
		master->iterations += 10 / x;
	if (master->iterations < 0)
	{
		master->iterations = 0;
		ft_printf("WARNING: Iterations cannot be less than 0\n");
	}
	ft_printf("ITERATIONS = %d\n", master->iterations);
	ft_printf("=======\n");
}

void	key_move(t_master *master, mlx_key_data_t key_data)
{
	double	x;

	x = 1;
	if (mlx_is_key_down(master->mlx, MLX_KEY_LEFT_SHIFT)
		|| mlx_is_key_down(master->mlx, MLX_KEY_RIGHT_SHIFT))
		x = 0.1;
	if (key_data.key == MLX_KEY_DOWN)
		master->fract->horizontal_shift += (0.1 * x);
	if (key_data.key == MLX_KEY_UP)
		master->fract->horizontal_shift -= (0.1 * x);
	if (key_data.key == MLX_KEY_LEFT)
		master->fract->vertical_shift -= (0.1 * x);
	if (key_data.key == MLX_KEY_RIGHT)
		master->fract->vertical_shift += (0.1 * x);
}

void	key_pres(mlx_key_data_t key_data, void *data)
{
	t_master	*master;

	if (key_data.action != MLX_PRESS && key_data.action != MLX_REPEAT)
		return ;
	master = (t_master *)data;
	if (key_data.key == MLX_KEY_ESCAPE)
		close_window(data);
	if (key_data.key == MLX_KEY_KP_ADD || key_data.key == MLX_KEY_KP_SUBTRACT)
		key_iterations((t_master *)data, key_data);
	if (key_data.key == MLX_KEY_R || key_data.key == MLX_KEY_G
		|| key_data.key == MLX_KEY_B)
		key_rgb((t_master *)data, key_data);
	if (key_data.key == MLX_KEY_UP || key_data.key == MLX_KEY_DOWN
		|| key_data.key == MLX_KEY_LEFT || key_data.key == MLX_KEY_RIGHT)
		key_move((t_master *)data, key_data);
	if (master->set == MANDELBROT)
		loop_img_mandelbrot(master);
	else if (master->set == JULIA)
		key_pres_julia(master, key_data);
	else
		loop_img_buringship(master);
}
