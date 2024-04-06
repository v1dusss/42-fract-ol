/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:24:46 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/06 20:12:53 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "lib/libft/libft.h"
# include "lib/mlx-42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <string.h>


typedef struct s_fractol
{
	double		x;
	double		y;
	double		ca;
	double		cb;
	char		*fract_name;
	int			max_iter;
}				t_fractol;

typedef struct s_px
{
	double		a;
	double		b;
	double		ca;
	double		cb;
	double		aa;
	double		bb;
	int			i;
}				t_px;

typedef enum e_set
{
	MANDELBROT,
	JULIA,
}				t_set;

typedef struct s_master
{
	t_set		set;
	t_fractol	*fract;
	t_px		*px;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			window_x;
	int			window_y;
	int			*r;
	int			*g;
	int			*b;
	int			*shade;
}				t_master;

// # define WINDOW_X 1080
// # define WINDOW_Y 720
# define MAX_ITERATIONS 700

void			mandelbrot(t_master *master);
void			julia(t_master *master);
void			loop_img_mandelbrot(t_master *master);
void			loop_img_julia(t_master *master);
int				get_rgb_a(int r, int g, int b, int a);
void			key_pres(mlx_key_data_t key_data, void *data);
void			clear_px(t_px *px);
void			clear_fract(t_fractol *fract, char *fract_name, int argc,
					char **argv, t_master *master);
void			usage(void);
uint32_t		get_vibrant_rgba(int gradient_value);
int map(int y);

#endif