/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conveyor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:27:08 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/30 12:20:09 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		conveyor_res_14(char **command_line, t_vars *vars,
t_conveyor *conveyor)
{
	conveyor->com_with_flags =
	make_command_arr_start(command_line, conveyor->i, (conveyor->j - 1));
	if (conveyor->com_with_flags[0] != NULL)
	{
		conveyor_res_5(command_line, vars, conveyor);
		conveyor_res_6(vars, conveyor);
		conveyor_res_7(command_line, vars, conveyor);
		conveyor_res_8(conveyor);
	}
	else
	{
		conveyor_res_9(command_line, vars, conveyor);
		conveyor_res_10(command_line, vars, conveyor);
		conveyor_res_11(command_line, vars, conveyor);
	}
}

static void		conveyor_res_15(char **command_line, t_vars *vars,
t_conveyor *conveyor)
{
	if (((ft_strncmp(command_line[conveyor->i], ">", 2) == 0)
	|| (ft_strncmp(command_line[conveyor->i], ">>", 3) == 0))
	&& vars->arr_flags[conveyor->i] != 1)
	{
		conveyor->com_with_flags =
		make_command_arr_start(command_line, conveyor->i, (conveyor->j - 1));
		if (conveyor->com_with_flags[0] != NULL)
			conveyor_res_3(command_line, vars, conveyor);
		else
			conveyor_res_4(command_line, vars, conveyor);
	}
	else if ((ft_strncmp(command_line[conveyor->i], "<", 2) == 0)
	&& vars->arr_flags[conveyor->i] != 1)
	{
		conveyor_res_14(command_line, vars, conveyor);
	}
	else if (command_line[conveyor->i + 1] == NULL && conveyor->flag_pipe == 1)
		conveyor_res_12(command_line, vars, conveyor);
}

void			ft_conveyor(char **command_line, t_vars *vars)
{
	t_conveyor conveyor;

	init_conveyor(&conveyor);
	create_file(command_line, vars->arr_flags);
	while (command_line[conveyor.i] != NULL)
	{
		if (conveyor.i != 0 &&
		((ft_strncmp(command_line[conveyor.i], "|", 2) == 0)
		&& vars->flag_redirect == 1) && vars->arr_flags[conveyor.i] != 1)
		{
			conveyor_res(command_line, vars, &conveyor);
		}
		if ((ft_strncmp(command_line[conveyor.i], "|", 2) == 0)
		&& vars->flag_redirect == 0 && vars->arr_flags[conveyor.i] != 1)
		{
			conveyor_res_2(command_line, vars, &conveyor);
		}
		else
			conveyor_res_15(command_line, vars, &conveyor);
		conveyor.j++;
		conveyor.i++;
	}
	conveyor_res_13(vars);
}
