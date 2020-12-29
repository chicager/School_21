/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:27:03 by curreg            #+#    #+#             */
/*   Updated: 2020/10/12 18:03:06 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_initial_rays(t_vars *vars, char dir)
{
	if (dir == 'N')
	{
		vars->ray_dir = 3 * (M_PI / 2);
	}
	else if (dir == 'E')
	{
		vars->ray_dir = 0;
	}
	else if (dir == 'S')
	{
		vars->ray_dir = M_PI / 2;
	}
	else if (dir == 'W')
	{
		vars->ray_dir = M_PI;
	}
	set_rays(vars);
}

void	set_rays(t_vars *vars)
{
	vars->ray_start = vars->ray_dir - M_PI / 6;
	vars->ray_end = vars->ray_dir + M_PI / 6;
}
