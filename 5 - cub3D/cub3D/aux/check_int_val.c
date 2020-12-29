/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:03:55 by curreg            #+#    #+#             */
/*   Updated: 2020/10/21 18:05:32 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_res(t_vars *vars)
{
	if (vars->mapflag.res == 1)
		put_error("Error\nMap error\n");
	else
		vars->mapflag.res += 1;
}

static void	check_floor_col(t_vars *vars)
{
	if (vars->mapflag.floor == 1)
		put_error("Error\nMap error\n");
	else
		vars->mapflag.floor += 1;
}

static void	check_ceil_col(t_vars *vars)
{
	if (vars->mapflag.ceil == 1)
		put_error("Error\nMap error\n");
	else
		vars->mapflag.ceil += 1;
}

void		check_int_val(t_vars *vars, char c)
{
	if (c == 'R')
		check_res(vars);
	else if (c == 'F')
		check_floor_col(vars);
	else if (c == 'C')
		check_ceil_col(vars);
}
