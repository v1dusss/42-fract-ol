/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:27:04 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/19 20:32:59 by vsivanat         ###   ########.fr       */
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
}

int	get_rgb_a(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(1920, 1080, "get on my level", true);
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_key_hook(mlx, key_pres, NULL);
	mlx_put_pixel(img, 1920 / 2, 1080 / 2, get_rgb_a(255, 0, 0, 255));
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
