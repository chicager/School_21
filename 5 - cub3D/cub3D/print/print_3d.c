/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:27:50 by curreg            #+#    #+#             */
/*   Updated: 2020/10/18 17:09:00 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void			init_print_3d(t_print3d *print, t_vars *vars, float x)
{
	print->count = 0;
	print->color = get_color(vars, 30, 20);
	print->ratio = SCALE / (print->start - print->end);
	print->init_start = print->start;
	print->count_y_pixel = 0;
	if (print->start < 0)
		print->start = 0;
	while (print->count < print->start)
	{
		my_mlx_pixel_put(vars, x, print->count, vars->ceil_col);
		print->count++;
	}
}

void				print_3d(float len, t_vars *vars, float x, double angle_ray)
{
	t_print3d print;

	len = len * cosf(vars->ray_dir - angle_ray);
	print.len_3d = vars->y_res * SCALE / len;
	print.start = vars->y_res / 2 - print.len_3d / 2;
	print.end = vars->y_res / 2 + print.len_3d / 2;
	init_print_3d(&print, vars, x);
	while (print.start < print.end && print.start < vars->y_res
			&& x < vars->x_res && print.start >= 0)
	{
		print.count_y_pixel = (int)((print.init_start - print.start)
									* print.ratio);
		print.color = get_color(vars, (int)vars->text_x, print.count_y_pixel);
		my_mlx_pixel_put(vars, x, print.start, print.color);
		print.start++;
	}
	while (print.end < vars->y_res && x < vars->x_res)
	{
		my_mlx_pixel_put(vars, x, print.end, vars->floor_col);
		print.end++;
	}
}
