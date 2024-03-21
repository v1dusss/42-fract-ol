/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:27:04 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/21 15:33:52 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_pres(mlx_key_data_t key_data, void *data)
{
	(void)data;
	if (key_data.key == MLX_KEY_ESCAPE)
	{
		exit(0);
	}
	// else if (key_data.key == MLX_KEY_KP_ADD)
	// {
	// 	fractol->window_x += 10;
	// 	fractol->window_y += 10;
	// }
	// else if (key_data.key == MLX_KEY_KP_SUBTRACT)
	// {
	// 	fractol->window_x -= 10;
	// 	fractol->window_y -= 10;
	// }
}

int	get_rgb_a(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	main(void)
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	struct s_fractol	fractol;

	fractol.window_x = 500;
	fractol.window_y = 500;
	mlx = mlx_init(fractol.window_x, fractol.window_y, "get on my level", true);
	img = mlx_new_image(mlx, fractol.window_x, fractol.window_y);
	mlx_key_hook(mlx, key_pres, NULL);
	mlx_put_pixel(img, fractol.window_x / 2, fractol.window_y / 2,
		get_rgb_a(255, 0, 0, 255));
	mlx_image_to_window(mlx, img, 0, 0);
	// mlx_loop_hook(mlx, mlx_render_images);
	mlx_loop(mlx);
	return (0);
}
