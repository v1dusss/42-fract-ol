/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:16:10 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/11 16:01:30 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	clear_px(t_master *master)
{
	master->px->aa = 0;
	master->px->bb = 0;
	master->px->i = -1;
}

int	valid_params(char *input)
{
	int	i;

	i = 0;
	if (input[0] == '\0')
		return (0);
	if (input[0] == '-' || input[0] == '+')
		i++;
	while (input[i] >= '0' && input[i] <= '9')
		i++;
	if (input[i] == '\0')
		return (1);
	if (input[i] != '.')
		return (0);
	if (input[i] == '.')
		i++;
	while (input[i] >= '0' && input[i] <= '9')
		i++;
	if (input[i] == '\0')
		return (1);
	return (0);
}

void	julia_settings(int argc, char **argv, t_master *master)
{
	if (argc == 2)
	{
		master->px->ca = 0.285;
		master->px->cb = 0.01;
		ft_printf("Fractol: julia [0.285] [0.01]\n");
	}
	else if (argc == 4 && valid_params(argv[2]) && valid_params(argv[3]))
	{
		master->px->ca = ft_atof(argv[2]);
		master->px->cb = ft_atof(argv[3]);
		ft_printf("Fractol: julia [%s] [%s]\n", argv[2], argv[3]);
	}
	else
		usage();
	master->set = JULIA;
	master->fract->fract_name = "julia";
}

void	which_fract(int argc, char **argv, t_master *master)
{
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		master->set = MANDELBROT;
		ft_printf("Fractol: mandelbrot\n");
		master->fract->fract_name = "mandelbrot";
	}
	else if (ft_strncmp(argv[1], "burningship", 12) == 0)
	{
		master->set = BURNINGSHIP;
		ft_printf("Fractol: burningship\n");
		master->fract->fract_name = "burningship";
	}
	else if (ft_strncmp(argv[1], "julia", 6) == 0 && argc != 3)
		julia_settings(argc, argv, master);
	else
		usage();
}

void	mouseaction(double a, double b, void *params)
{
	double		multiplier;
	t_master	*master;

	(void)a;
	master = (t_master *)params;
	if (b > 0)
		multiplier = 1.1;
	else
		multiplier = 0.9;
	master->scale *= multiplier;
	if (master->set == MANDELBROT)
		loop_img_mandelbrot(master);
	else if (master->set == JULIA)
		loop_img_julia(master);
	else
		loop_img_buringship(master);
}
