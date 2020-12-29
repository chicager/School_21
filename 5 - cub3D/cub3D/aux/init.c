/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:18:59 by curreg            #+#    #+#             */
/*   Updated: 2020/10/20 18:46:35 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_arr(double *arr)
{
	int i;

	i = -1;
	while (arr[++i])
		arr[i] = 0.0;
}

static void	init_aux(t_vars *vars)
{
	vars->map_array = NULL;
	vars->ray_end = 0.0;
	vars->ray_dir = 0.0;
	vars->img = NULL;
	vars->addr = NULL;
	vars->bits_per_pixel = 0;
	vars->line_length = 0;
	vars->endian = 0;
	vars->mlx = NULL;
	vars->mlx_win = NULL;
	vars->img_text = NULL;
	vars->textb_per_pixel = 0;
	vars->text_line_length = 0;
	vars->text_endian = 0;
	vars->floor_col = 0;
	vars->ceil_col = 0;
	vars->text_x = 0.0;
	vars->img_text_addr = NULL;
	vars->img_text_addr_w = NULL;
	vars->img_text_addr_n = NULL;
	vars->img_text_addr_s = NULL;
	vars->img_text_addr_e = NULL;
	vars->img_text_addr_sp = NULL;
	init_arr(vars->mas_ray);
}

void		init(t_vars *vars)
{
	int count;

	count = 0;
	vars->map_array = NULL;
	vars->p_y = 0;
	vars->p_x = 0;
	vars->length_ray = 0;
	vars->player_pos = 0;
	vars->ray_start = 0;
	vars->img_height = 0;
	vars->img_width = 0;
	vars->ray_initial = 0;
	vars->sprites_count = 0;
	vars->is_player_set = 0;
	vars->player_placed = 0;
	vars->x_res = 1280;
	vars->y_res = 720;
	init_aux(vars);
	while (count < 5)
	{
		vars->paths[count] = NULL;
		count++;
	}
}
