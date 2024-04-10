/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:16:10 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/10 19:57:51 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	if (input [0] == '\0')
		return (0);
	if (input[0] == '-' || input[0] == '+')
		i++;
	while (input[i] >= '0' && input[i] <= '9')
		i++;
	if (input[i] == '\0')
		return (1);
	if (input[0] != '.')
		return (0);
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
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		master->set = MANDELBROT;
		ft_printf("Fractol: mandelbrot\n");
		master->fract->fract_name = "mandelbrot";
	}
	else if (ft_strncmp(argv[1], "burningship", 11) == 0)
	{
		master->set = BURNINGSHIP;
		ft_printf("Fractol: burningship\n");
		master->fract->fract_name = "burningship";
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0 && argc != 3)
		julia_settings(argc, argv, master);
	else
		usage();
}
