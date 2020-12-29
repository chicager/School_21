/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:35:32 by curreg            #+#    #+#             */
/*   Updated: 2020/10/18 16:18:23 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		keycode_13(t_vars *vars)
{
	if (check_straight_wall(vars))
	{
		vars->p_x -= 0;
		vars->p_y -= 0;
	}
	else
	{
		vars->p_x += 10.0 * cosf(vars->ray_dir);
		vars->p_y += 10.0 * sinf(vars->ray_dir);
	}
	print_frame(vars);
}

void		keycode_0(t_vars *vars)
{
	if (check_left_wall(vars))
	{
		vars->p_x += 0;
		vars->p_y += 0;
	}
	else
	{
		vars->p_x -= 10 * cosf(vars->ray_dir + M_PI_2);
		vars->p_y -= 10 * sinf(vars->ray_dir + M_PI_2);
	}
	print_frame(vars);
}

void		keycode_1(t_vars *vars)
{
	if (check_back_wall(vars))
	{
		vars->p_x += 0;
		vars->p_y += 0;
	}
	else
	{
		vars->p_x -= 10 * cosf(vars->ray_dir);
		vars->p_y -= 10 * sinf(vars->ray_dir);
	}
	print_frame(vars);
}

void		keycode_2(t_vars *vars)
{
	if (check_right_wall(vars))
	{
		vars->p_x += 0;
		vars->p_y += 0;
	}
	else
	{
		vars->p_x += 10 * cosf(vars->ray_dir + M_PI_2);
		vars->p_y += 10 * sinf(vars->ray_dir + M_PI_2);
	}
	print_frame(vars);
}
