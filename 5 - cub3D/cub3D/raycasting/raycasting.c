/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:28:13 by curreg            #+#    #+#             */
/*   Updated: 2020/10/20 21:27:11 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ray_dist_aux3(t_vars *vars)
{
	vars->ray.i1 = vars->ray.bx / vars->ray.size;
	vars->ray.j1 = vars->ray.by / vars->ray.size;
	while (vars->ray.j1 < vars->ray.end_mas_y && vars->ray.i1 >= 0 &&
		vars->ray.j1 >= 0 && vars->ray.i1 <=
		ft_strlen(vars->map_array[vars->ray.j1]) &&
		vars->map_array[vars->ray.j1][vars->ray.i1] != '1')
	{
		vars->ray.bx = vars->ray.bx + vars->ray.xa;
		vars->ray.by = vars->ray.by + vars->ray.ya;
		vars->ray.i1 = vars->ray.bx / vars->ray.size;
		vars->ray.j1 = vars->ray.by / vars->ray.size;
	}
	vars->ray.len_hor = sqrt((powf((vars->ray.px - vars->ray.ax), 2) +
						powf((vars->ray.py - vars->ray.ay), 2)));
	vars->ray.len_ver = sqrt((powf((vars->ray.px - vars->ray.bx), 2) +
						powf((vars->ray.py - vars->ray.by), 2)));
}

static void		ray_dist_aux4(t_vars *vars, double pow)
{
	ray_dist_aux(vars, pow);
	vars->ray.i = vars->ray.ax / vars->ray.size;
	vars->ray.j = vars->ray.ay / vars->ray.size;
	while (vars->ray.j < vars->ray.end_mas_y && vars->ray.i >= 0 && vars->ray.j
			>= 0 && vars->ray.i <= ft_strlen(vars->map_array[vars->ray.j]) &&
			vars->map_array[vars->ray.j][vars->ray.i] != '1')
	{
		vars->ray.ax = vars->ray.ax + vars->ray.xa;
		vars->ray.ay = vars->ray.ay + vars->ray.ya;
		vars->ray.i = vars->ray.ax / vars->ray.size;
		vars->ray.j = vars->ray.ay / vars->ray.size;
	}
	ray_dist_aux2(vars, pow);
	ray_dist_aux3(vars);
}

static void		ray_dist_aux5(t_vars *vars, double pow)
{
	if (pow > M_PI)
	{
		vars->text_x = (int)vars->ray.ax % SCALE +
					(vars->ray.ax - (int)vars->ray.ax);
		vars->img_text_addr = vars->img_text_addr_n;
	}
	else
	{
		vars->text_x = -(int)vars->ray.ax % SCALE + 63 +
					(vars->ray.ax - (int)vars->ray.ax);
		vars->img_text_addr = vars->img_text_addr_s;
	}
}

static void		ray_dist_aux6(t_vars *vars, double pow)
{
	if ((pow < 2 * M_PI && pow > 3 * M_PI / 2 && pow != M_PI_2) ||
			(pow > 0 && pow < M_PI_2))
	{
		vars->img_text_addr = vars->img_text_addr_w;
		vars->text_x = (int)vars->ray.by % SCALE +
					(vars->ray.by - (int)vars->ray.by);
	}
	else
	{
		vars->img_text_addr = vars->img_text_addr_e;
		vars->text_x = -(int)vars->ray.by % SCALE + 63 +
					(vars->ray.by - (int)vars->ray.by);
	}
}

double			ray_dist(t_vars *vars, double pow, int s)
{
	ray_dist_init(vars, s);
	if (pow < 0)
		pow += 2 * M_PI;
	if (pow > 2 * M_PI)
		pow -= 2 * M_PI;
	ray_dist_aux4(vars, pow);
	if (vars->ray.len_hor <= vars->ray.len_ver)
	{
		ray_dist_aux5(vars, pow);
		return (vars->ray.len_hor);
	}
	else
	{
		ray_dist_aux6(vars, pow);
		return (vars->ray.len_ver);
	}
}
