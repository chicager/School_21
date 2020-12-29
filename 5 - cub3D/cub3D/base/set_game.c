/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:45:22 by curreg            #+#    #+#             */
/*   Updated: 2020/10/20 21:41:53 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_game(t_vars *vars, char **argv)
{
	int i;

	i = 0;
	ft_memset(vars, 0, sizeof(t_vars));
	init(vars);
	read_map(argv, vars);
	get_sprites_count(vars, SCALE);
	init_sprite_arr(vars);
	fill_sprites_arr(vars, SCALE);
	sort_sprites_arr(vars);
	set_window(vars);
	parse_texture(vars);
	print_map(vars, 0, 0, SCALE);
	print_rays(vars);
	i = vars->sprites_count * 2;
	while (i > 0)
	{
		print_sprite(vars->sprites_arr[i - 2], vars->sprites_arr[i - 1], vars);
		i -= 2;
	}
}
