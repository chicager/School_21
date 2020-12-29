/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:27:11 by curreg            #+#    #+#             */
/*   Updated: 2020/10/16 17:39:34 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				close_on_x(void)
{
	exit(0);
}

void			print_frame(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars->x_res, vars->y_res);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
									&vars->line_length, &vars->endian);
	print_rays(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
}

static void		press_handler(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	if (keycode == 13 || keycode == 126)
		keycode_13(vars);
	if (keycode == 0)
		keycode_0(vars);
	if (keycode == 1 || keycode == 125)
		keycode_1(vars);
	if (keycode == 2)
		keycode_2(vars);
	if (keycode == 124)
		keycode_124(vars);
	if (keycode == 123)
		keycode_123(vars);
}

int				key_press(int keycode, t_vars *vars)
{
	int i;

	i = vars->sprites_count * 2;
	sort_sprites_arr(vars);
	press_handler(keycode, vars);
	while (i > 0)
	{
		print_sprite(vars->sprites_arr[i - 2], vars->sprites_arr[i - 1], vars);
		i -= 2;
	}
	return (0);
}
