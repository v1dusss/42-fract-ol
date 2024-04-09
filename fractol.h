/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:24:46 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/09 15:55:33 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "lib/libft/libft.h"
# include "lib/mlx-42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <string.h>

typedef enum e_set
{
	MANDELBROT,
	JULIA,
	BURNINGSHIP,
}				t_set;

typedef struct s_fractol
{
	double		x;
	double		y;
	double		ca;
	double		cb;
	char		*fract_name;
	double		vertical_shift;
	double		horizontal_shift;
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

typedef struct s_master
{
	t_set			set;
	t_fractol		*fract;
	t_px			*px;
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				scale;
	int				iterations;
	int				r;
	int				g;
	int				b;
}			t_master;

# define WINDOW_X 1080
# define WINDOW_Y 720

# define MAX_ITERATIONS 40
# define SCALE 400

# define MANDELBROT_R 90
# define MANDELBROT_G 90
# define MANDELBROT_B 90

# define JULIA_R 90
# define JULIA_G 90
# define JULIA_B 90

# define BURNINGSHIP_R 90
# define BURNINGSHIP_G 90
# define BURNINGSHIP_B 90

void		mandelbrot(t_master *master);
void		julia(t_master *master);
void		buringship(t_master *master);
void		loop_img_mandelbrot(t_master *master);
void		loop_img_julia(t_master *master);
void		loop_img_buringship(t_master *master);
void		key_pres(mlx_key_data_t key_data, void *data);
void		key_stadart(t_master *master, mlx_key_data_t key_data);
void		key_pres_julia(t_master *master, mlx_key_data_t key_data);
void		clear_px(t_master *master);
void		clear_fract(char *fract_name, int argc, char **argv, t_master *master);
void		usage(void);
int			map(t_master *master);
int			get_grey(int grey, int a);
int			get_rgb_a(int i, int a, t_master *master);
void		mouseaction(double a, double b, void *params);

#endif
