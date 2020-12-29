/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:26:47 by curreg            #+#    #+#             */
/*   Updated: 2020/10/18 19:59:08 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_img_text(t_vars *vars)
{
	if (vars->img_text == NULL)
		put_error("Error\nTexture or sprite error\n");
}

void		parse_texture(t_vars *vars)
{
	vars->img_text = mlx_xpm_file_to_image(vars->mlx, vars->paths[WE],
									&vars->img_width, &vars->img_height);
	check_img_text(vars);
	vars->img_text_addr_w = mlx_get_data_addr(vars->img_text,
	&vars->textb_per_pixel, &vars->text_line_length, &vars->text_endian);
	vars->img_text = mlx_xpm_file_to_image(vars->mlx, vars->paths[NO],
									&vars->img_width, &vars->img_height);
	check_img_text(vars);
	vars->img_text_addr_n = mlx_get_data_addr(vars->img_text,
	&vars->textb_per_pixel, &vars->text_line_length, &vars->text_endian);
	vars->img_text = mlx_xpm_file_to_image(vars->mlx, vars->paths[SO],
									&vars->img_width, &vars->img_height);
	check_img_text(vars);
	vars->img_text_addr_s = mlx_get_data_addr(vars->img_text,
	&vars->textb_per_pixel, &vars->text_line_length, &vars->text_endian);
	vars->img_text = mlx_xpm_file_to_image(vars->mlx, vars->paths[EA],
									&vars->img_width, &vars->img_height);
	check_img_text(vars);
	vars->img_text_addr_e = mlx_get_data_addr(vars->img_text,
	&vars->textb_per_pixel, &vars->text_line_length, &vars->text_endian);
	vars->img_text = mlx_xpm_file_to_image(vars->mlx, vars->paths[S],
									&vars->img_width, &vars->img_height);
	check_img_text(vars);
	vars->img_text_addr_sp = mlx_get_data_addr(vars->img_text,
	&vars->textb_per_pixel, &vars->text_line_length, &vars->text_endian);
}
