/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes_arrows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:37:13 by curreg            #+#    #+#             */
/*   Updated: 2020/10/16 17:38:45 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		keycode_124(t_vars *vars)
{
	vars->ray_dir += 0.0872665;
	if (vars->ray_dir >= 2 * M_PI)
		vars->ray_dir -= 2 * M_PI;
	set_rays(vars);
	print_frame(vars);
}

void		keycode_123(t_vars *vars)
{
	vars->ray_dir -= 0.0872665;
	if (vars->ray_dir <= 0)
		vars->ray_dir += 2 * M_PI;
	set_rays(vars);
	print_frame(vars);
}
