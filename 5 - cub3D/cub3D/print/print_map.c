/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:27:56 by curreg            #+#    #+#             */
/*   Updated: 2020/10/18 19:58:48 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		printmap_init(t_vars *vars, int y, int x, int s)
{
	vars->p.i = 0;
	vars->p.j = 0;
	vars->p.m = 0;
	vars->p.y_start = y;
	vars->p.x_start = x;
	vars->p.size = s;
}

static void		print_map_aux1(t_vars *vars, int i, int j)
{
	if (vars->is_player_set == 0)
		vars->is_player_set = 1;
	else
		put_error("Error\nToo many players\n");
	if (vars->ray_initial == 0)
	{
		set_initial_rays(vars, vars->map_array[i][j]);
		vars->ray_initial = 1;
	}
}

static void		print_map_aux2(t_vars *vars, int y_start, int x_start, int s)
{
	if (vars->player_pos == 0)
	{
		vars->p_x = x_start + s / 2;
		vars->p_y = y_start + s / 2;
		vars->player_pos = 1;
	}
}

static void		print_map_aux3(t_vars *vars)
{
	while (vars->map_array[vars->p.i][vars->p.j])
	{
		if (vars->map_array[vars->p.i][vars->p.j] == '1')
			vars->p.x_start += vars->p.size;
		else if (vars->map_array[vars->p.i][vars->p.j] == '2')
			vars->p.x_start += vars->p.size;
		else if (vars->map_array[vars->p.i][vars->p.j] == '0')
			vars->p.x_start += vars->p.size;
		else if (vars->map_array[vars->p.i][vars->p.j] == ' ')
			vars->p.x_start += vars->p.size;
		else if (vars->map_array[vars->p.i][vars->p.j] == 'N'
				|| vars->map_array[vars->p.i][vars->p.j] == 'S'
				|| vars->map_array[vars->p.i][vars->p.j] == 'W'
				|| vars->map_array[vars->p.i][vars->p.j] == 'E')
		{
			print_map_aux1(vars, vars->p.i, vars->p.j);
			print_map_aux2(vars, vars->p.y_start, vars->p.x_start,
							vars->p.size);
			vars->p.x_start += vars->p.size;
		}
		else
			vars->p.x_start += vars->p.size;
		vars->p.j++;
	}
}

void			print_map(t_vars *vars, int y_start, int x_start, int size)
{
	printmap_init(vars, y_start, x_start, size);
	while (vars->map_array[vars->p.i] != NULL)
	{
		vars->p.j = 0;
		print_map_aux3(vars);
		vars->p.y_start += vars->p.size;
		vars->p.x_start = 0;
		vars->p.i++;
	}
}
