/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:16:10 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/23 18:42:59 by vsivanat         ###   ########.fr       */
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

void	clear_fract(t_fractol *fract, char *fract_name)
{
	fract->x = -1;
	fract->y = -1;
	if (ft_strncmp(fract_name, "mandelbrot", 10) == 0)
		fract->fract = 1;
	else if (ft_strncmp(fract_name, "julia", 5) == 0)
		fract->fract = 2;
	else
		usage();
	ft_printf("Fractol: %s\n", fract_name);
}
