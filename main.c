/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:27:04 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/22 19:23:03 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	clear_fract(t_fractol *fract)
// {
// 	fract->x = 0;
// 	fract->y = 0;
// }

void	clear_pixel(t_pixel *pixel)
{
	pixel->a = 0;
	pixel->b = 0;
	pixel->ca = 0;
	pixel->cb = 0;
	pixel->aa = 0;
	pixel->bb = 0;
	pixel->i = 0;
}

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

void	usage(void)
{
	ft_putstr_fd("Usage: ./fractol [mandelbrot/julia]\n", 1);
	exit(-1);
}

int	get_rgb_a(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	fract_ol(mlx_image_t *img, t_fractol fract)
{
	static t_pixel	pixel;

	// clear_pixel(&pixel);
	pixel.b = ((fract.window_y / -2) + fract.y) / 350;
	pixel.a = (((fract.window_x / -2) + fract.x) / 350) - 0.5;
	pixel.ca = pixel.a;
	pixel.cb = pixel.b;
	pixel.i = 0;
	pixel.aa = 0;
	pixel.bb = 0;
	while (pixel.i < 1000)
	{
		pixel.aa = pixel.a * pixel.a - pixel.b * pixel.b;
		pixel.bb = 2 * pixel.a * pixel.b;
		pixel.a = pixel.aa + pixel.ca;
		pixel.b = pixel.bb + pixel.cb;
		if ((pixel.a + pixel.b) > 16)
			break ;
		pixel.i++;
	}
	if (pixel.i == 1000)
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(255, 255, 255, 255));
	else
		mlx_put_pixel(img, fract.x, fract.y, get_rgb_a(0, 0, 0, 255));
}

int	main(int argc, char **argv)
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	struct s_fractol	fract;

	(void)argv;
	if (argc < 2)
		usage();
	fract.window_x = 1080;
	fract.window_y = 1080;
	fract.x = 0;
	fract.y = 0;
	mlx = mlx_init(fract.window_x, fract.window_y, "get on my level", true);
	img = mlx_new_image(mlx, fract.window_x, fract.window_y);
	mlx_key_hook(mlx, key_pres, NULL);
	while (fract.x < fract.window_x)
	{
		fract.y = 0;
		while (fract.y < fract.window_y)
		{
			fract_ol(img, fract);
			fract.y++;
		}
		fract.x++;
	}
	fract.x = 0;
	fract.y = 0;
	mlx_image_to_window(mlx, img, 0, 0);
	// mlx_loop_hook(mlx, mlx_render_images);
	mlx_loop(mlx);
	return (0);
}
