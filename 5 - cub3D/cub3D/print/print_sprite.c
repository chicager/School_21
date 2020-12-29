/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:28:08 by curreg            #+#    #+#             */
/*   Updated: 2020/10/16 17:43:34 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					sp_get_color(t_vars *vars, int x, int y)
{
	char	*dst;

	dst = vars->img_text_addr_sp + (y * vars->text_line_length
								+ x * (vars->textb_per_pixel / 8));
	return (*(unsigned int*)dst);
}

static void			init_struct(t_sprite *sprite, t_vars *vars,
								double spr_x, double spr_y)
{
	sprite->sprite_dir = atan2(spr_y - vars->p_y, spr_x - vars->p_x);
	while (sprite->sprite_dir - vars->ray_dir > M_PI)
		sprite->sprite_dir -= 2 * M_PI;
	while (sprite->sprite_dir - vars->ray_dir < -M_PI)
		sprite->sprite_dir += 2 * M_PI;
	sprite->sprite_dist = sqrt((powf((spr_x - vars->p_x), 2)
								+ powf((spr_y - vars->p_y), 2)));
	sprite->sprite_screen_size = vars->y_res * SCALE / sprite->sprite_dist;
	sprite->h_offset = (sprite->sprite_dir - vars->ray_dir) * (vars->x_res)
			/ (M_PI / 3) + (vars->x_res) / 2 - sprite->sprite_screen_size / 2;
	sprite->v_offset = vars->y_res / 2 - sprite->sprite_screen_size / 2;
	sprite->i = 0;
	sprite->j = 0;
	sprite->step = M_PI / (vars->x_res * 3.0);
	sprite->color = 0;
}

static void			print_sprite_res(t_sprite *sprite, t_vars *vars)
{
	while (sprite->j < sprite->sprite_screen_size)
	{
		if (sprite->v_offset + (int)(sprite->j) < 0
			|| sprite->v_offset + sprite->j >= (int)vars->y_res)
		{
			sprite->j++;
			continue;
		}
		sprite->color = sp_get_color(vars, sprite->i * SCALE /
		sprite->sprite_screen_size, sprite->j * SCALE /
		sprite->sprite_screen_size);
		if (sprite->color != 0X980088)
			my_mlx_pixel_put(vars, sprite->h_offset +
					sprite->i, sprite->v_offset + sprite->j, sprite->color);
		sprite->j++;
	}
	sprite->step += M_PI / (vars->x_res * 3.0);
	sprite->j = 0;
	sprite->i++;
	sprite->count++;
}

void				print_sprite(double spr_x, double spr_y, t_vars *vars)
{
	t_sprite	sprite;

	init_struct(&sprite, vars, spr_x, spr_y);
	if (sprite.sprite_screen_size > 4000)
		sprite.sprite_screen_size = 0;
	while (sprite.i < sprite.sprite_screen_size)
	{
		if (sprite.h_offset + (int)(sprite.i) < 0 ||
			sprite.h_offset + sprite.i >= (int)vars->x_res)
		{
			sprite.i++;
			continue;
		}
		if (vars->mas_ray[(int)sprite.h_offset + sprite.i] < sprite.sprite_dist)
		{
			sprite.i++;
			continue;
		}
		print_sprite_res(&sprite, vars);
	}
}
