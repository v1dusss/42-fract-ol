/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:16:10 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/07 21:29:39 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_rgb_a(int r, int g, int b, int a)
{
	return ((r * g) << 24 | g * 255 << 16 | b << 8 | a);
}

int	get_grey(int grey, int a)
{
	return (grey << 24 | grey << 16 | grey << 8 | a);
}
void	clear_px(t_px *px)
{
	px->aa = 0;
	px->bb = 0;
	px->i = -1;
}

char	*mlx_name(t_master *master, char *fract_name, int argc, char **argv)
{
	char	*name;
	char	*name2;

	if (master->set == MANDELBROT)
		return (fract_name);
	else
	{
		if (argc == 2)
			return ("julia [0.285] [0.01]");
		else
		{
			name = ft_strjoin("julia [", argv[2]);
			name2 = ft_strjoin(name, "] [");
			free(name);
			name = ft_strjoin(name2, argv[3]);
			free(name2);
			name2 = ft_strjoin(name, "]");
			free(name);
			return (name2);
		}
	}
}

void	clear_fract(char *fract_name, int argc, char **argv,
		t_master *master)
{
	if (ft_strncmp(fract_name, "mandelbrot", 10) == 0)
		master->set = MANDELBROT;
	else if (ft_strncmp(fract_name, "julia", 5) == 0 && argc != 3)
	{
		master->set = JULIA;
		if (argc == 4)
		{
			master->fract->ca = ft_atof(argv[2]);
			master->fract->cb = ft_atof(argv[3]);
			ft_printf("Fractol: julia [%s] [%s]\n", argv[2], argv[3]);
		}
		else
		{
			master->fract->ca = 0.285;
			master->fract->cb = 0.01;
			ft_printf("Fractol: julia [0.285] [0.01]\n");
		}
	}
	else
		usage();
	if (master->set == MANDELBROT)
		ft_printf("Fractol: %s\n", "mandelbrot");
	master->fract->fract_name = mlx_name(master, fract_name, argc, argv);
	
}

int map(t_master *master)
{
	int in_min;
	int in_max;
	int out_min;
	int out_max;
	
	in_min = 0;
	in_max = master->iterations;
	out_min = 0;
	out_max = 255;
	return (sqrt(master->px->i / (255.0 / (master->iterations * master->iterations * 2))));
	// return ((master->px->i - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}
