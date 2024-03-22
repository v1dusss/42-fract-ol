/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:24:46 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/22 19:04:33 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "lib/libft/libft.h"
# include "lib/mlx-42/include/MLX42/MLX42.h"

typedef struct s_fractol
{
	double	window_x;
	double	window_y;
	double	x;
	double	y;
}			t_fractol;

typedef struct s_pixel
{
	double	a;
	double	b;
	double	ca;
	double	cb;
	double	aa;
	double	bb;
	int		i;
}			t_pixel;

#endif