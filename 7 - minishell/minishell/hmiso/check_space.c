/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:35:13 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/30 12:15:51 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	check_space_res(t_space *space)
{
	space->ptr = ft_substr(space->line, 0, space->i);
	space->ptr_for_free = space->ptr;
	space->ptr = ft_strjoin(space->ptr, " ");
	ptr_free(&space->ptr_for_free);
	space->ptr_for_free = space->ptr;
	space->ptr = ft_strjoin(space->ptr, &space->line[space->i]);
	ptr_free(&space->ptr_for_free);
	ptr_free(&space->line);
	space->line = ft_strdup(space->ptr);
	ptr_free(&space->ptr);
}

static void	check_space_res_2(t_space *space)
{
	space->ptr = ft_substr(space->line, 0, space->i + 1);
	space->ptr_for_free = space->ptr;
	space->ptr = ft_strjoin(space->ptr, " ");
	ptr_free(&space->ptr_for_free);
	space->ptr_for_free = space->ptr;
	space->ptr = ft_strjoin(space->ptr, &space->line[space->i + 1]);
	ptr_free(&space->ptr_for_free);
	ptr_free(&space->line);
	space->line = ft_strdup(space->ptr);
	ptr_free(&space->ptr);
}

static void	check_space_res_3(t_space *space)
{
	space->ptr = ft_substr(space->line, 0, space->i + 2);
	space->ptr_for_free = space->ptr;
	space->ptr = ft_strjoin(space->ptr, " ");
	ptr_free(&space->ptr_for_free);
	space->ptr_for_free = space->ptr;
	space->ptr = ft_strjoin(space->ptr, &space->line[space->i + 2]);
	ptr_free(&space->ptr_for_free);
	ptr_free(&space->line);
	space->line = ft_strdup(space->ptr);
	ptr_free(&space->ptr);
	space->i++;
}

static void	init_space(char *line_old, t_space *space)
{
	space->ptr = NULL;
	space->i = 0;
	space->flag = 0;
	space->line = ft_strdup(line_old);
	space->ptr_for_free = NULL;
}

char		*check_space(char *line_old)
{
	t_space space;

	init_space(line_old, &space);
	while (space.line[space.i] != '\0')
	{
		check_space_res_4(&space);
		if (ft_strlen(space.line) > 1 && (space.line[space.i] == '>'
		|| space.line[space.i] == '|' || space.line[space.i] == '<')
		&& space.flag == 0)
		{
			if (space.i != 0 && space.line[space.i - 1] != ' '
			&& space.i != 0 && space.line[space.i - 1] != '>')
				check_space_res(&space);
			else if ((int)ft_strlen(space.line) >= space.i + 1
			&& space.line[space.i + 1] != ' ' && space.line[space.i + 1] != '\0'
			&& space.line[space.i + 1] != '>')
				check_space_res_2(&space);
			else if ((int)ft_strlen(space.line) >= space.i + 2
			&& space.line[space.i + 2] != ' ' && space.line[space.i + 2] != '\0'
			&& space.line[space.i + 1] == '>')
				check_space_res_3(&space);
		}
		space.i++;
	}
	return (space.line);
}
