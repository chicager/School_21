/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:06:46 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/29 19:15:22 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		init_move(t_move *move)
{
	move->ptr = NULL;
	move->ptr2 = NULL;
	move->flag2 = 0;
	move->count = 0;
	move->flag = 0;
	move->i = 0;
	move->poz = 0;
}

static void		move_res(char **command_line, t_move *move, t_vars *vars)
{
	if ((ft_strncmp(command_line[move->i], ">", 2) == 0
	|| ft_strncmp(command_line[move->i], ">>", 3) == 0 ||
	ft_strncmp(command_line[move->i], "<", 2) == 0)
	&& vars->arr_flags[move->i + move->count] != 1)
	{
		if ((command_line[move->i + 2] != NULL)
		&& (ft_strncmp(command_line[move->i + 2], "|", 2) != 0))
		{
			if ((ft_strncmp(command_line[move->i + 2], ">", 2) != 0
			&& ft_strncmp(command_line[move->i + 2], ">>", 3) != 0 &&
			ft_strncmp(command_line[move->i + 2], "<", 2) != 0))
			{
				move->ptr = command_line[move->i];
				move->flag = vars->arr_flags[move->i + move->count];
				command_line[move->i] = command_line[move->i + 2];
				vars->arr_flags[move->i + move->count] =
				vars->arr_flags[move->i + 2];
				command_line[move->i + 2] = command_line[move->i + 1];
				vars->arr_flags[move->i + 2] = vars->arr_flags[move->i + 1];
				command_line[move->i + 1] = move->ptr;
				vars->arr_flags[move->i + 1] = move->flag;
			}
		}
	}
	move->i++;
}

static void		move_res_2(char **command_line, t_move *move, t_vars *vars)
{
	move->ptr = command_line[move->i];
	move->flag = vars->arr_flags[move->i + move->count];
	move->ptr2 = command_line[move->i + 1];
	move->flag2 = vars->arr_flags[move->i + 1];
	command_line[move->i] = command_line[move->i + 2];
	vars->arr_flags[move->i + move->count] = vars->arr_flags[move->i + 2];
	command_line[move->i + 1] = command_line[move->i + 3];
	vars->arr_flags[move->i + 1] = vars->arr_flags[move->i + 3];
	command_line[move->i + 2] = move->ptr;
	vars->arr_flags[move->i + 2] = move->flag;
	command_line[move->i + 3] = move->ptr2;
	vars->arr_flags[move->i + 3] = move->flag2;
}

static void		move_res_3(char **command_line, t_move *move, t_vars *vars)
{
	while (command_line[move->poz] != NULL)
	{
		while (command_line[move->i] != NULL)
		{
			if ((ft_strncmp(command_line[move->i], ">", 2) == 0
			|| ft_strncmp(command_line[move->i], ">>", 3) == 0)
			&& vars->arr_flags[move->i + move->count] != 1)
			{
				if ((command_line[move->i + 2] != NULL)
				&& ((ft_strncmp(command_line[move->i + 2], "|", 2) != 0)
				&& vars->arr_flags[move->i + 2] != 1))
				{
					if ((ft_strncmp(command_line[move->i + 2], "<", 2) == 0)
					&& vars->arr_flags[move->i + move->count] != 1)
						move_res_2(command_line, move, vars);
				}
			}
			move->i++;
		}
		move->i = 0;
		move->poz++;
	}
}

char			**move_arguments(char **command_line, t_vars *vars)
{
	t_move move;

	init_move(&move);
	while (command_line[move.i] != NULL)
		move.i++;
	while (vars->arr_flags[move.count] != 2)
		move.count++;
	move.count = move.count - move.i;
	while (command_line[move.poz] != NULL)
	{
		while (command_line[move.i] != NULL)
			move_res(command_line, &move, vars);
		move.i = 0;
		move.poz++;
	}
	move.i = 0;
	move.poz = 0;
	move_res_3(command_line, &move, vars);
	return (command_line);
}
