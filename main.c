/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:27:04 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/26 21:02:51 by vsivanat         ###   ########.fr       */
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

void	loop_img(t_master *master)
{
	printf("%f\n", master->pixel->cb);
	if (master->img)
	{
		mlx_delete_image(master->mlx, master->img);
		printf("img deleted\n");
	}
	master->img = mlx_new_image(master->mlx, master->fract->window_x,
			master->fract->window_y);
	printf("img created\n");
	master->fract->x = -1;
	while (++(master->fract->x) < master->fract->window_x)
	{
		master->fract->y = -1;
		while (++(master->fract->y) < master->fract->window_y)
		{
			if (master->set == MANDELBROT)
				mandelbrot(master->img, master->fract, master->pixel);
			else if (master->set == JULIA)
			{
				julia(master);
			}
		}
	}
	mlx_image_to_window(master->mlx, master->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_master	master;
	t_fractol	fract;
	t_pixel		pixel;

	write(1, "0", 1);
	master.fract = &fract;
	master.pixel = &pixel;
	if (argc < 2 || argc > 4)
		usage();
	write(1, "0", 1);
	master.fract->window_x = 1080;
	master.fract->window_y = 1080;
	write(1, "0", 1);
	clear_fract(master.fract, ft_strlower(argv[1]), argc, argv, &master);
	master.mlx = mlx_init(master.fract->window_x, master.fract->window_y,
			master.fract->fract_name, true);
	write(1, "0", 1);
	loop_img(&master);
	mlx_image_to_window(master.mlx, master.img, 0, 0);
	// mlx_loop_hook(mlx, mlx_render_images);
	mlx_key_hook(master.mlx, key_pres, &master);
	mlx_loop(master.mlx);
	return (0);
}
