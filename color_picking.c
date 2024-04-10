/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:10:11 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/10 15:21:53 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_rgb_a(int i, int a, t_master *master)
{
	(void)a;
	return ((i * master->r) << 24 | (i * master->g) << 16 | (i * master->b) << 8 | 255);
}

int	get_grey(int grey, int a)
{
	return (grey << 24 | grey << 16 | grey << 8 | a);
}
