/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:16:10 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/25 19:01:20 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_rgb_a(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	key_pres(mlx_key_data_t key_data, void *data)
{
	(void)data;
	if (key_data.key == MLX_KEY_ESCAPE)
		exit(0);
}

void	clear_pixel(t_pixel *pixel)
{
	pixel->aa = 0;
	pixel->bb = 0;
	pixel->i = 0;
}

char	*mlx_name(t_fractol *fract, char *fract_name, int argc, char **argv)
{
	char	*name;
	char	*name2;

	if (fract->fract == 1)
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

void	clear_fract(t_fractol *fract, char *fract_name, int argc, char **argv)
{
	fract->x = -1;
	fract->y = -1;
	if (ft_strncmp(fract_name, "mandelbrot", 10) == 0)
		fract->fract = 1;
	else if (ft_strncmp(fract_name, "julia", 5) == 0 && argc != 3)
	{
		fract->fract = 2;
		if (argc == 4)
		{
			fract->ca = ft_atof(argv[2]);
			fract->cb = ft_atof(argv[3]);
			ft_printf("Fractol: julia [%s] [%s]\n", argv[2], argv[3]);
		}
		else
		{
			fract->ca = 0.285;
			fract->cb = 0.01;
			ft_printf("Fractol: julia [0.285] [0.01]\n");
		}
	}
	else
		usage();
	if (fract->fract == 1)
		ft_printf("Fractol: %s\n", "mandelbrot");
	fract->fract_name = mlx_name(fract, fract_name, argc, argv);
}
