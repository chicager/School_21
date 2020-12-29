/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:27:42 by curreg            #+#    #+#             */
/*   Updated: 2020/10/18 19:51:12 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char			**ft_create_map(char **addr)
{
	int		len;
	int		i;
	char	**map;

	map = NULL;
	len = 0;
	i = -1;
	while (addr[len])
		len++;
	map = ft_calloc(len + 1, sizeof(char *));
	while (++i < len)
		map[i] = ft_strdup(addr[i]);
	return (map);
}

static int			ft_check_map_flags(t_mapflag mapflag)
{
	int all;
	int i;

	i = 0;
	all = 0;
	while (i < 5)
	{
		all += (mapflag.tex[i] == 1);
		i++;
	}
	all += (mapflag.floor == 1) + (mapflag.ceil == 1) + (mapflag.res == 1);
	return (all);
}

static char			**ft_parse(t_vars *vars, char **tmp)
{
	int				j;
	int				all;
	char			*str;

	j = -1;
	while (tmp[++j])
	{
		str = ft_skip_spaces(tmp[j]);
		all = ft_check_map_flags(vars->mapflag);
		if (all < 8 && *str)
		{
			if (ft_strchr("NEWS", *str))
				ft_parse_textures(vars, str);
			else if (ft_strchr("FCR", *str))
				ft_parse_ints(vars, str);
			else
				put_error("Error\nMap Error\n");
		}
		else if (all == 8 && *str)
			return (ft_create_map(&tmp[j]));
	}
	put_error("Error\nToo low arguments\n");
	return (NULL);
}

static void			check_mapflags(t_vars *vars)
{
	int i;

	i = -1;
	if (!vars->mapflag.res)
		put_error("Error\nResolution error\n");
	if (!vars->mapflag.floor || !vars->mapflag.ceil)
		put_error("Error\nColor error\n");
	while (++i < 5)
	{
		if (!vars->mapflag.tex[i])
			put_error("Error\nTexture or sprite error\n");
	}
}

void				read_map(char **argv, t_vars *vars)
{
	int			fd;
	char		*line;
	t_list		*tmp;
	char		**full_map;

	line = NULL;
	tmp = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		put_error("Error\nTexture or sprite error\n");
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(&tmp, ft_lstnew(line));
	ft_lstadd_back(&tmp, ft_lstnew(line));
	full_map = list_to_array(ft_lstsize(tmp), &tmp);
	vars->map_array = ft_parse(vars, full_map);
	check_player_placed(vars);
	ft_clear_arr(full_map);
	free(full_map);
	close(fd);
	check_mapflags(vars);
	check_map_array(vars);
}
