/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:01:51 by curreg            #+#    #+#             */
/*   Updated: 2020/10/18 19:53:53 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		check_player_placed(t_vars *vars)
{
	int		i;

	i = -1;
	while (vars->map_array[++i])
	{
		if (ft_strchr(vars->map_array[i], 'N') ||
			ft_strchr(vars->map_array[i], 'E') ||
			ft_strchr(vars->map_array[i], 'W') ||
			ft_strchr(vars->map_array[i], 'S'))
		{
			vars->player_placed = 1;
			return ;
		}
	}
	put_error("Error\nNo player has been set\n");
}
