/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:27:04 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/25 19:26:40 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_printf("Usage: ./fractol [mandelbrot | julia]\n");
	ft_printf("\t-mandelbrot\n");
	ft_printf("\t-julia\n");
	ft_printf("\t-julia [ca] [cb]\n");
	exit(-1);
}

int	main(int argc, char **argv)
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	struct s_fractol	fract;

	if (argc < 2 || argc > 4)
		usage();
	fract.window_x = 1080;
	fract.window_y = 1080;
	clear_fract(&fract, ft_strlower(argv[1]), argc, argv);
	mlx = mlx_init(fract.window_x, fract.window_y, fract.fract_name, true);
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
