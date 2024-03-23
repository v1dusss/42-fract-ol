/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:27:04 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/23 19:06:16 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_putstr_fd("Usage: ./fractol [mandelbrot/julia]\n", 1);
	exit(-1);
}

int	main(int argc, char **argv)
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	struct s_fractol	fract;

	if (argc < 2)
		usage();
	fract.window_x = 1080;
	fract.window_y = 1080;
	clear_fract(&fract, ft_strlower(argv[1]));
	mlx = mlx_init(fract.window_x, fract.window_y, ft_strlower(argv[1]), true);
	img = mlx_new_image(mlx, fract.window_x, fract.window_y);
	mlx_key_hook(mlx, key_pres, NULL);
	while (++fract.x < fract.window_x)
	{
		fract.y = -1;
		while (++fract.y < fract.window_y)
		{
			if (fract.fract == 1)
				mandelbrot(img, fract);
			else if (fract.fract == 2)
				julia(img, fract);
		}
	}
	mlx_image_to_window(mlx, img, 0, 0);
	// mlx_loop_hook(mlx, mlx_render_images);
	mlx_loop(mlx);
	return (0);
}
