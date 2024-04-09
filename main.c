/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:27:04 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/09 14:42:43 by vsivanat         ###   ########.fr       */
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
	t_master	master;
	t_fractol	fract;
	t_px		px;

	master.fract = &fract;
	master.px = &px;
	if (argc < 2 || argc > 4)
		usage();
	master.iterations = MAX_ITERATIONS;
	master.scale = SCALE;
	clear_fract(ft_strlower(argv[1]), argc, argv, &master);
	master.mlx = mlx_init(WINDOW_X, WINDOW_Y, master.fract->fract_name, false);
	master.img = mlx_new_image(master.mlx, WINDOW_X, WINDOW_Y);
		if (master.set == MANDELBROT)
		{
				master.r = MANDELBROT_R;
				master.g = MANDELBROT_G;
				master.b = MANDELBROT_B;
				loop_img_mandelbrot(&master);
		}
		else if (master.set == JULIA)
		{
				master.r = JULIA_R;
				master.g = JULIA_G;
				master.b = JULIA_B;
				loop_img_julia(&master);
		}
		else
		{
				master.r = BURNINGSHIP_R;
				master.g = BURNINGSHIP_G;
				master.b = BURNINGSHIP_B;
				loop_img_buringship(&master);
		}
	mlx_image_to_window(master.mlx, master.img, 0, 0);
	mlx_scroll_hook(master.mlx, mouseaction, &master);
	mlx_key_hook(master.mlx, key_pres, &master);
	mlx_loop(master.mlx);
	// mlx_close_hook(master.mlx, close_window, &master);
	mlx_image_to_window(master.mlx, master.img, 0, 0);
	return (0);
}
