/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sprites_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:35:05 by curreg            #+#    #+#             */
/*   Updated: 2020/10/18 20:39:56 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	fill_sp_arr_aux(t_vars *vars, t_fill_sp *fill_sp, int size)
{
	vars->sprites_arr[fill_sp->m] = fill_sp->x_start + size / 2;
	fill_sp->m++;
	vars->sprites_arr[fill_sp->m] = fill_sp->y_start + size / 2;
	fill_sp->m++;
	fill_sp->x_start += size;
}

static void	fill_sp_arr_aux2(t_vars *vars, t_fill_sp *fill_sp, int size)
{
	if (vars->map_array[fill_sp->i][fill_sp->j] == '1')
		fill_sp->x_start += size;
	else if (vars->map_array[fill_sp->i][fill_sp->j] == '2')
		fill_sp_arr_aux(vars, fill_sp, size);
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

void		fill_sprites_arr(t_vars *vars, int size)
{
	t_fill_sp fill_sp;

	init_fill_sp(&fill_sp);
	while (vars->map_array[fill_sp.i] != NULL)
	{
		fill_sp.j = 0;
		while (vars->map_array[fill_sp.i][fill_sp.j])
			fill_sp_arr_aux2(vars, &fill_sp, size);
		fill_sp.y_start += size;
		fill_sp.x_start = 0;
		fill_sp.i++;
	}
}
