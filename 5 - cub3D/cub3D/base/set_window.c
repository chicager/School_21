/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:07:14 by curreg            #+#    #+#             */
/*   Updated: 2020/10/20 21:38:43 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, vars->x_res,
									vars->y_res, "cube3D");
	vars->img = mlx_new_image(vars->mlx, vars->x_res, vars->y_res);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
									&vars->line_length, &vars->endian);
}
