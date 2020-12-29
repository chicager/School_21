/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_and_tex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 20:58:49 by curreg            #+#    #+#             */
/*   Updated: 2020/10/21 17:16:49 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void			ft_parse_textures_aux(t_vars *vars, char *str)
{
	if (str[0] == 'S' && str[1] != 'O')
	{
		vars->paths[S] = ft_strdup(ft_skip_spaces(str + 1));
		if (vars->mapflag.tex[S] == 1)
			put_error("Error\nMap Error\n");
		else
			vars->mapflag.tex[S] += 1;
	}
}

void				ft_parse_textures(t_vars *vars, char *str)
{
	const char	*type[5] = { "NO", "EA", "WE", "SO", NULL };
	int			i;
	char		*tmp;

	i = -1;
	tmp = NULL;
	while (type[++i])
	{
		if (!ft_strncmp(type[i], str, 2))
		{
			tmp = ft_strdup(ft_skip_spaces(str + 2));
			vars->paths[i] = ft_strtrim(tmp, " ");
			free(tmp);
			tmp = NULL;
			if (vars->mapflag.tex[i] == 1)
				put_error("Error\nMap Error\n");
			else
				vars->mapflag.tex[i] += 1;
		}
	}
	ft_parse_textures_aux(vars, str);
}

static void			ft_get_color_aux(int i, char **rgb)
{
	if (i != 3)
		put_error("Error\nMap Error\n");
	free(rgb);
}

static void			ft_get_color_aux2(int col, char *tmp)
{
	if (col > 255 || !ft_is_only_digit(tmp) || !*tmp)
		put_error("Error\nMap Error\n");
}

uint32_t			ft_get_color(char *str)
{
	int				i;
	char			**rgb;
	char			*tmp;
	int				col;
	uint32_t		color;

	color = 0;
	rgb = ft_split(str, ',');
	i = -1;
	while (rgb[++i])
	{
		tmp = ft_strtrim(rgb[i], " ");
		free(rgb[i]);
		rgb[i] = NULL;
		col = ft_atoi(tmp);
		ft_get_color_aux2(col, tmp);
		free(tmp);
		tmp = NULL;
		color |= col << ((2 - i) * 8);
	}
	ft_get_color_aux(i, rgb);
	return (color);
}
