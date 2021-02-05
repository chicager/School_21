/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:30:00 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/29 17:06:42 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		init_list(t_list_red *list_red)
{
	list_red->count = 0;
	list_red->k = 0;
	list_red->arr = NULL;
}

static void		list_red_res(t_list_red *list_red, char **command_line,
int i, t_vars *vars)
{
	while (list_red->k <= i && ((ft_strncmp(command_line[list_red->k],
	"|", 2) != 0) || vars->arr_flags[list_red->k] == 1))
	{
		if (((ft_strncmp(command_line[list_red->k], ">", 2) == 0)
		&& vars->arr_flags[list_red->k] == 0) ||
		((ft_strncmp(command_line[list_red->k],
		">>", 3) == 0) && vars->arr_flags[list_red->k] == 0))
		{
			if (((ft_strncmp(command_line[list_red->k - 1], ">", 2) != 0
			&& vars->arr_flags[list_red->k - 1] == 0)) ||
			(ft_strncmp(command_line[list_red->k - 1], ">>", 3) != 0
			&& vars->arr_flags[list_red->k - 1] == 0))
			{
				list_red->k++;
				continue;
			}
		}
		list_red->k++;
		list_red->count++;
	}
}

static void		list_red_res_2(t_list_red *list_red, char **command_line,
int i, t_vars *vars)
{
	while (list_red->k <= i && (ft_strncmp(command_line[list_red->k],
	"|", 2) != 0 || vars->arr_flags[list_red->k] == 1))
	{
		if (((ft_strncmp(command_line[list_red->k], ">", 2) == 0)
		&& vars->arr_flags[list_red->k] == 0) ||
		((ft_strncmp(command_line[list_red->k], ">>", 3) == 0)
		&& vars->arr_flags[list_red->k] == 0))
		{
			if (((ft_strncmp(command_line[list_red->k - 1], ">", 2)
			!= 0 && vars->arr_flags[list_red->k - 1] == 0)) ||
			(ft_strncmp(command_line[list_red->k - 1], ">>", 3) != 0
			&& vars->arr_flags[list_red->k - 1] == 0))
			{
				list_red->k++;
				continue;
			}
		}
		list_red->arr[list_red->count] = ft_strdup(command_line[list_red->k]);
		list_red->k++;
		list_red->count++;
	}
}

char			**make_list_redirection(char **command_line, int i, int j,
t_vars *vars)
{
	t_list_red list_red;

	init_list(&list_red);
	list_red.k = i - j;
	list_red_res(&list_red, command_line, i, vars);
	list_red.arr = malloc(sizeof(char *) * (list_red.count + 1));
	list_red.k = i - j;
	list_red.count = 0;
	list_red_res_2(&list_red, command_line, i, vars);
	list_red.arr[list_red.count] = NULL;
	return (list_red.arr);
}
