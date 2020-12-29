/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:57:00 by curreg            #+#    #+#             */
/*   Updated: 2020/10/16 19:02:01 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_color(t_vars *vars, int x, int y)
{
	char	*dst;

	dst = vars->img_text_addr + (y * vars->text_line_length
								+ x * (vars->textb_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void	print_rays(t_vars *vars)
{
	double		current;
	int			x;
	int			j;

	x = 0;
	j = 0;
	current = vars->ray_start;
	while (current < vars->ray_end)
	{
		vars->length_ray = ray_dist(vars, current, SCALE);
		vars->mas_ray[j] = vars->length_ray;
		print_3d(vars->length_ray, vars, x, current);
		current += M_PI / (vars->x_res * 3.0);
		x++;
		j++;
	}
}
