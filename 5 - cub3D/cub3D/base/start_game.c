/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:29:17 by curreg            #+#    #+#             */
/*   Updated: 2020/10/20 20:20:59 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "map.cub") == 0)
		{
			set_game(&vars, argv);
			mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, 0, 0);
			mlx_hook(vars.mlx_win, 2, 1L, key_press, &vars);
			mlx_hook(vars.mlx_win, 17, 0, close_on_x, &vars);
			mlx_loop(vars.mlx);
		}
	}
	else if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 6) == 0)
		{
			set_game(&vars, argv);
			take_screenshot(&vars);
			exit(0);
		}
	}
	put_error("Error\nWrong arguments\n");
	return (0);
}
