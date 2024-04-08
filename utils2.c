/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:01:25 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/07 20:03:22 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_window(void *params)
{
	t_master	*master;

	master = (t_master *)params;
	mlx_destroy_window(master->mlx);
	exit(0);
}