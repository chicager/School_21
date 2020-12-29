/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 21:05:55 by curreg            #+#    #+#             */
/*   Updated: 2020/10/21 18:09:20 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		check_commas(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == ',')
			count++;
		str++;
	}
	if (count != 2)
		put_error("Error\nColor error\n");
}

void			ft_get_resolution(t_vars *vars, char *str)
{
	char			**tmp;
	t_check			screen;

	tmp = ft_split(str, ' ');
	if (!tmp[1] || tmp[2] || !ft_is_only_digit(tmp[0])
		|| !ft_is_only_digit(tmp[1]))
		put_error("Error\nResolution error\n");
	vars->x_res = ft_atoi(tmp[0]);
	vars->y_res = ft_atoi(tmp[1]);
	if (vars->x_res == 0 || vars->y_res == 0)
		put_error("Error\nResolution error\n");
	mlx_get_screen_size(vars->mlx, &screen.pos_x, &screen.pos_y);
	if (vars->x_res > screen.pos_x || vars->x_res < 1)
		vars->x_res = screen.pos_x;
	if (vars->y_res > screen.pos_y || vars->y_res < 1)
		vars->y_res = screen.pos_y;
	ft_clear_arr(tmp);
	free(tmp);
}

void			ft_parse_ints(t_vars *vars, char *str)
{
	if (*str == 'C')
	{
		check_commas(str + 1);
		vars->ceil_col = ft_get_color(str + 1);
		check_int_val(vars, *str);
	}
	else if (*str == 'F')
	{
		check_commas(str + 1);
		vars->floor_col = ft_get_color(str + 1);
		check_int_val(vars, *str);
	}
	else
	{
		ft_get_resolution(vars, str + 1);
		check_int_val(vars, *str);
	}
}
