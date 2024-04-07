/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:27:04 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/07 17:16:31 by vsivanat         ###   ########.fr       */
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
	clear_fract(master.fract, ft_strlower(argv[1]), argc, argv, &master);
	master.mlx = mlx_init(WINDOW_X, WINDOW_Y,
			master.fract->fract_name, false);
	if (master.set == MANDELBROT)
		loop_img_mandelbrot(&master);
	else
		loop_img_julia(&master);
	mlx_image_to_window(master.mlx, master.img, 0, 0);
	// mlx_loop_hook(mlx, mlx_render_images);
	mlx_scroll_hook(master.mlx, mouseaction, &master);
	mlx_key_hook(master.mlx, key_pres, &master);
	mlx_loop(master.mlx);
	return (0);
}
