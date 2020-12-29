/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:30:32 by curreg            #+#    #+#             */
/*   Updated: 2020/10/20 20:55:13 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_sprites_arr(t_sort_spr *sort_spr)
{
	sort_spr->i = 0;
	sort_spr->j = 0;
	sort_spr->sprite_dist = 0;
	sort_spr->temp_sprites_arr1 = 0.0;
	sort_spr->temp_sprites_arr2 = 0.0;
	sort_spr->min_position = 0;
	sort_spr->tmp = 0;
}

static void	sort_sp_arr_aux(t_sort_spr *sort_spr, double *sp, t_vars *vars)
{
	while (sort_spr->i < vars->sprites_count)
	{
		sort_spr->sprite_dist = sqrt((powf((vars->sprites_arr[sort_spr->j] -
					vars->p_x), 2) + powf((vars->sprites_arr[sort_spr->j + 1] -
					vars->p_y), 2)));
		sp[sort_spr->i] = sort_spr->sprite_dist;
		sort_spr->i++;
		sort_spr->j += 2;
	}
}

static void	sort_sp_arr_aux2(t_sort_spr *sort_spr, double *sp, t_vars *vars)
{
	sort_spr->tmp = sp[sort_spr->min_position];
	sort_spr->temp_sprites_arr1 =
						vars->sprites_arr[sort_spr->min_position * 2];
	sort_spr->temp_sprites_arr2 =
						vars->sprites_arr[(sort_spr->min_position * 2) + 1];
	sp[sort_spr->min_position] =
						sp[sort_spr->i];
	vars->sprites_arr[sort_spr->min_position * 2] =
						vars->sprites_arr[sort_spr->i * 2];
	vars->sprites_arr[(sort_spr->min_position * 2) + 1] =
									vars->sprites_arr[(sort_spr->i * 2) + 1];
	sp[sort_spr->i] = sort_spr->tmp;
	vars->sprites_arr[sort_spr->i * 2] = sort_spr->temp_sprites_arr1;
	vars->sprites_arr[(sort_spr->i * 2) + 1] = sort_spr->temp_sprites_arr2;
	sort_spr->i++;
}

void		sort_sprites_arr(t_vars *vars)
{
	t_sort_spr	sort_spr;
	double		sprite_dist_arr[vars->sprites_count];

	init_sprites_arr(&sort_spr);
	sort_sp_arr_aux(&sort_spr, sprite_dist_arr, vars);
	sort_spr.i = 0;
	while (sort_spr.i < vars->sprites_count)
	{
		sort_spr.min_position = sort_spr.i;
		sort_spr.j = sort_spr.i + 1;
		while (sort_spr.j < vars->sprites_count)
		{
			if (sprite_dist_arr[sort_spr.min_position] >
				sprite_dist_arr[sort_spr.j])
				sort_spr.min_position = sort_spr.j;
			sort_spr.j++;
		}
		sort_sp_arr_aux2(&sort_spr, sprite_dist_arr, vars);
	}
}
