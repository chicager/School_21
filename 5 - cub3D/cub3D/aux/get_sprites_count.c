/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:21:16 by curreg            #+#    #+#             */
/*   Updated: 2020/10/18 20:42:34 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		init_sprite_arr(t_vars *vars)
{
	vars->sprites_arr = (double*)malloc(sizeof(double) *
						(vars->sprites_count * 2));
}

void		init_fill_sp(t_fill_sp *fill_sp)
{
	fill_sp->x_start = 0;
	fill_sp->y_start = 0;
	fill_sp->i = 0;
	fill_sp->j = 0;
	fill_sp->m = 0;
}

static void	get_sp_count_aux(t_vars *vars, t_fill_sp *fill_sp, int size)
{
	if (vars->map_array[fill_sp->i][fill_sp->j] == '1')
		fill_sp->x_start += size;
	else if (vars->map_array[fill_sp->i][fill_sp->j] == '2')
		vars->sprites_count++;
	else if (vars->map_array[fill_sp->i][fill_sp->j] == '0')
		fill_sp->x_start += size;
	else if (vars->map_array[fill_sp->i][fill_sp->j] == ' ')
		fill_sp->x_start += size;
	else if (vars->map_array[fill_sp->i][fill_sp->j] == 'N' ||
			vars->map_array[fill_sp->i][fill_sp->j] == 'S' ||
			vars->map_array[fill_sp->i][fill_sp->j] == 'W' ||
			vars->map_array[fill_sp->i][fill_sp->j] == 'E')
		fill_sp->x_start += size;
	else
		fill_sp->x_start += size;
	fill_sp->j++;
}

void		get_sprites_count(t_vars *vars, int size)
{
	t_fill_sp fill_sp;

	init_fill_sp(&fill_sp);
	while (vars->map_array[fill_sp.i] != NULL)
	{
		fill_sp.j = 0;
		while (vars->map_array[fill_sp.i][fill_sp.j])
			get_sp_count_aux(vars, &fill_sp, size);
		fill_sp.y_start += size;
		fill_sp.x_start = 0;
		fill_sp.i++;
	}
}
