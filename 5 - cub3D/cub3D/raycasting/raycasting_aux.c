/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:28:19 by curreg            #+#    #+#             */
/*   Updated: 2020/10/20 18:17:17 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ray_dist_init(t_vars *vars, int scale)
{
	vars->ray.xa = 0;
	vars->ray.ya = 0;
	vars->ray.px = vars->p_x;
	vars->ray.py = vars->p_y;
	vars->ray.ay = 0;
	vars->ray.ax = 0;
	vars->ray.bx = 0;
	vars->ray.by = 0;
	vars->ray.len_hor = 0;
	vars->ray.len_ver = 0;
	vars->ray.i = 0;
	vars->ray.j = 0;
	vars->ray.i1 = 0;
	vars->ray.j1 = 0;
	vars->ray.end_mas_y = 0;
	vars->ray.size = scale;
}

void		ray_dist_aux(t_vars *vars, double pow)
{
	while (vars->map_array[vars->ray.end_mas_y] != NULL)
		vars->ray.end_mas_y++;
	if (pow > 0 && pow < M_PI)
	{
		vars->ray.ay = (int)(vars->ray.py / vars->ray.size) *
						vars->ray.size + vars->ray.size;
		vars->ray.ya = vars->ray.size;
		vars->ray.ax = vars->ray.px + (vars->ray.py - vars->ray.ay) /
						tan((M_PI * 2 - pow));
		vars->ray.xa = vars->ray.size / tan(pow);
	}
	else if (pow == M_PI || pow == 0)
	{
		vars->ray.ay = (int)vars->ray.py;
		vars->ray.ya = vars->ray.size;
	}
	else
	{
		vars->ray.ay = (int)(vars->ray.py / vars->ray.size) *
						vars->ray.size - 0.000000001;
		vars->ray.ya = -vars->ray.size;
		vars->ray.ax = vars->ray.px + (vars->ray.py - vars->ray.ay) /
						tan((M_PI * 2 - pow));
		vars->ray.xa = vars->ray.size / tan(M_PI * 2 - pow);
	}
}

void		ray_dist_aux2(t_vars *vars, double pow)
{
	if ((pow < 2 * M_PI && pow > 3 * M_PI / 2 && pow != M_PI_2) ||
						(pow > 0 && pow < M_PI_2))
	{
		vars->ray.bx = (int)(vars->ray.px / vars->ray.size) * vars->ray.size +
						vars->ray.size;
		vars->ray.xa = vars->ray.size;
		vars->ray.by = vars->ray.py + (vars->ray.px - vars->ray.bx) *
						tan(M_PI * 2 - pow);
		vars->ray.ya = vars->ray.size * tan(pow);
	}
	else if (pow == M_PI_2 || pow == 3 * M_PI / 2)
	{
		vars->ray.bx = (int)vars->ray.px;
		vars->ray.xa = vars->ray.size;
	}
	else
	{
		vars->ray.bx = (int)(vars->ray.px / vars->ray.size) *
						vars->ray.size - 0.000000001;
		vars->ray.xa = -vars->ray.size;
		vars->ray.by = vars->ray.py + (vars->ray.px - vars->ray.bx) *
						tan(M_PI * 2 - pow);
		vars->ray.ya = vars->ray.size * tan(M_PI * 2 - pow);
	}
}
