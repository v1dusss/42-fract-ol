/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:10:11 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/09 14:43:12 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_rgb_a(int i, int a, t_master *master)
{
	return ((i * master->r) << 24 | (i * master->g) << 16 | (i * master->b) << 8 | a);
}

int	get_grey(int grey, int a)
{
	return (grey << 24 | grey << 16 | grey << 8 | a);
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

