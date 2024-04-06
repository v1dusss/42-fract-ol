/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:27:04 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/06 19:39:03 by vsivanat         ###   ########.fr       */
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

	write(1, "A\n", 2);
	printf("MAX_ITERATIONS = %d\n", MAX_ITERATIONS);
	master.fract = &fract;
	master.px = &px;
	if (argc < 2 || argc > 4)
		usage();
	write(1, "B\n", 2);
	master.window_x = 1080;
	master.window_y = 800;
	write(1, "C\n", 2);
	clear_fract(master.fract, ft_strlower(argv[1]), argc, argv, &master);
	master.mlx = mlx_init(master.window_x, master.window_y,
			master.fract->fract_name, true);
	write(1, "D\n", 2);
	if (master.set == MANDELBROT)
		loop_img_mandelbrot(&master);
	else
		loop_img_julia(&master);
	mlx_image_to_window(master.mlx, master.img, 0, 0);
	// mlx_loop_hook(mlx, mlx_render_images);
	mlx_key_hook(master.mlx, key_pres, &master);
	mlx_loop(master.mlx);
	return (0);
}
