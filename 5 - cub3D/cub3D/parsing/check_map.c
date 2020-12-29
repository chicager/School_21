/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 20:55:24 by curreg            #+#    #+#             */
/*   Updated: 2020/10/18 20:03:14 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void			check_map_aux(t_vars *vars, int i, int j)
{
	if (vars->map_array[i][j] == '0' || vars->map_array[i][j] == '2' ||
					ft_strchr("NSWE", vars->map_array[i][j]))
	{
		if (j == 0)
			put_error("Error\nMap error\n");
		if (vars->map_array[i][j + 1] == ' '
		|| vars->map_array[i][j - 1] == ' '
		|| vars->map_array[i + 1][j] == ' '
		|| vars->map_array[i - 1][j] == ' '
		|| vars->map_array[i][j + 1] == '\0'
		|| vars->map_array[i][j - 1] == '\0'
		|| vars->map_array[i + 1][j] == '\0'
		|| vars->map_array[i - 1][j] == '\0'
		|| (int)ft_strlen(vars->map_array[i - 1]) < j
		|| (vars->map_array[i + 1] != NULL
		&& (int)ft_strlen(vars->map_array[i + 1]) < j))
			put_error("Error\nMap error\n");
	}
}

int					check_map(t_vars *vars, int i, int j)
{
	while (vars->map_array[i] != NULL)
	{
		while (vars->map_array[i][j] != '\0')
		{
			if (vars->map_array[i][j] == '1' || vars->map_array[i][j] == '0'
			|| vars->map_array[i][j] == '2'
			|| ft_strchr("NSWE", vars->map_array[i][j])
			|| vars->map_array[i][j] == ' ')
				check_map_aux(vars, i, j);
			else
				put_error("Error\nMap error\n");
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static void			check_map_array_aux(t_vars *vars, int i, int j)
{
	while (vars->map_array[0][j])
	{
		if (vars->map_array[0][j] != '1' && vars->map_array[0][j] != ' ')
			put_error("Error\nMap error\n");
		j++;
	}
	j = -1;
	while (vars->map_array[i - 1][++j])
	{
		if (vars->map_array[i - 1][j] != '1'
		&& vars->map_array[i - 1][j] != ' ')
			put_error("Error\nMap error\n");
	}
}

void				check_map_array(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (vars->map_array[i])
		i++;
	check_map_array_aux(vars, i, j);
	check_map(vars, 0, 0);
}
