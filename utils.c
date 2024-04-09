/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:16:10 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/09 13:43:46 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear_px(t_master *master)
{
	master->px->aa = 0;
	master->px->bb = 0;
	master->px->i = -1;
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

void	clear_fract(char *fract_name, int argc, char **argv, t_master *master)
{
	if (ft_strncmp(fract_name, "mandelbrot", 10) == 0)
		master->set = MANDELBROT;
	else if (ft_strncmp(fract_name, "julia", 5) == 0 && argc != 3)
	{
		master->set = JULIA;
		if (argc == 4)
		{
			master->px->ca = ft_atof(argv[2]);
			master->px->cb = ft_atof(argv[3]);
			ft_printf("Fractol: julia [%s] [%s]\n", argv[2], argv[3]);
		}
		else
		{
			master->px->ca = 0.285;
			master->px->cb = 0.01;
			ft_printf("Fractol: julia [0.285] [0.01]\n");
		}
	}
	else if (ft_strncmp(fract_name, "burningship", 11) == 0)
		master->set = BURNINGSHIP;
	else
		usage();
	if (master->set == MANDELBROT)
		ft_printf("Fractol: %s\n", "mandelbrot");
	else if (master->set == BURNINGSHIP)
		ft_printf("Fractol: %s\n", "burningship");
	master->fract->fract_name = mlx_name(master, fract_name, argc, argv);
}
