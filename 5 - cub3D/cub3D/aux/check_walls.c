/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:26:54 by curreg            #+#    #+#             */
/*   Updated: 2020/10/21 18:02:44 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		init_check(t_check *check)
{
	check->pos_x = 0;
	check->pos_y = 0;
	check->pos_x_rs = 0;
	check->pos_y_rs = 0;
	check->pos_x_re = 0;
	check->pos_y_re = 0;
}

int				check_straight_wall(t_vars *vars)
{
	t_check check;

	init_check(&check);
	check.pos_x = ((vars->p_x + 20 * cos(vars->ray_dir)) / SCALE);
	check.pos_y = ((vars->p_y + 20 * sin(vars->ray_dir)) / SCALE);
	check.pos_x_rs = ((vars->p_x + 20 * cos(vars->ray_start)) / SCALE);
	check.pos_y_rs = ((vars->p_y + 20 * sin(vars->ray_start)) / SCALE);
	check.pos_x_re = ((vars->p_x + 20 * cos(vars->ray_end)) / SCALE);
	check.pos_y_re = ((vars->p_y + 20 * sin(vars->ray_end)) / SCALE);
	if (vars->map_array[check.pos_y][check.pos_x] == '1' ||
		vars->map_array[check.pos_y_rs][check.pos_x_rs] == '1'
		|| vars->map_array[check.pos_y_re][check.pos_x_re] == '1')
		return (1);
	else
		return (0);
}

int				check_left_wall(t_vars *vars)
{
	t_check check;

	init_check(&check);
	check.pos_x = ((vars->p_x - 20 * cos(vars->ray_dir + M_PI_2)) / SCALE);
	check.pos_y = ((vars->p_y - 20 * sin(vars->ray_dir + M_PI_2)) / SCALE);
	check.pos_x_rs = ((vars->p_x - 20 * cos(vars->ray_start + M_PI_2)) / SCALE);
	check.pos_y_rs = ((vars->p_y - 20 * sin(vars->ray_start + M_PI_2)) / SCALE);
	check.pos_x_re = ((vars->p_x - 20 * cos(vars->ray_end + M_PI_2)) / SCALE);
	check.pos_y_re = ((vars->p_y - 20 * sin(vars->ray_end + M_PI_2)) / SCALE);
	if (vars->map_array[check.pos_y][check.pos_x] == '1' ||
		vars->map_array[check.pos_y_rs][check.pos_x_rs] == '1'
		|| vars->map_array[check.pos_y_re][check.pos_x_re] == '1')
		return (1);
	else
		return (0);
}

int				check_right_wall(t_vars *vars)
{
	t_check check;

	init_check(&check);
	check.pos_x = ((vars->p_x + 20 * cos(vars->ray_dir + M_PI_2)) / SCALE);
	check.pos_y = ((vars->p_y + 20 * sin(vars->ray_dir + M_PI_2)) / SCALE);
	check.pos_x_rs = ((vars->p_x + 20 * cos(vars->ray_start + M_PI_2)) / SCALE);
	check.pos_y_rs = ((vars->p_y + 20 * sin(vars->ray_start + M_PI_2)) / SCALE);
	check.pos_x_re = ((vars->p_x + 20 * cos(vars->ray_end + M_PI_2)) / SCALE);
	check.pos_y_re = ((vars->p_y + 20 * sin(vars->ray_end + M_PI_2)) / SCALE);
	if (vars->map_array[check.pos_y][check.pos_x] == '1' ||
		vars->map_array[check.pos_y_rs][check.pos_x_rs] == '1'
		|| vars->map_array[check.pos_y_re][check.pos_x_re] == '1')
		return (1);
	else
		return (0);
}

int				check_back_wall(t_vars *vars)
{
	t_check check;

	init_check(&check);
	check.pos_x = ((vars->p_x - 20 * cos(vars->ray_dir)) / SCALE);
	check.pos_y = ((vars->p_y - 20 * sin(vars->ray_dir)) / SCALE);
	check.pos_x_rs = ((vars->p_x - 20 * cos(vars->ray_start)) / SCALE);
	check.pos_y_rs = ((vars->p_y - 20 * sin(vars->ray_start)) / SCALE);
	check.pos_x_re = ((vars->p_x - 20 * cos(vars->ray_end)) / SCALE);
	check.pos_y_re = ((vars->p_y - 20 * sin(vars->ray_end)) / SCALE);
	if (vars->map_array[check.pos_y][check.pos_x] == '1' ||
		vars->map_array[check.pos_y_rs][check.pos_x_rs] == '1'
		|| vars->map_array[check.pos_y_re][check.pos_x_re] == '1')
		return (1);
	else
		return (0);
}
