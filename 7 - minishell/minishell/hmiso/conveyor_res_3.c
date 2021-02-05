/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conveyor_res_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:08:38 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/30 12:19:12 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	conveyor_res_10(char **command_line, t_vars *vars, t_conveyor *conveyor)
{
	if (conveyor->flag == 0)
		conveyor->flag_pipe = 1;
	if (conveyor->flag == 1)
		conveyor->flag_pipe = 1;
	if (conveyor->flag == 2)
	{
		conveyor->j = 0;
		conveyor->k = 0;
		while (command_line[conveyor->i + 1] != NULL)
		{
			if (ft_strncmp(command_line[conveyor->i], "|", 2) == 0
			&& vars->arr_flags[conveyor->i] == 0)
				break ;
			conveyor->i++;
			conveyor->k++;
		}
		conveyor->arr_redirection2 =
		make_list_redirection(command_line, conveyor->i, conveyor->j, vars);
		conveyor->flag_pipe = 0;
		free_two_dimensional_array(conveyor->arr_redirection2);
	}
}

void	conveyor_res_11(char **command_line, t_vars *vars, t_conveyor *conveyor)
{
	if (conveyor->flag == 0)
		conveyor->flag_pipe = 1;
	if (conveyor->flag == 1)
		conveyor->flag_pipe = 1;
	if (conveyor->flag == 2)
	{
		conveyor->j = 0;
		conveyor->k = 0;
		while (command_line[conveyor->i + 1] != NULL)
		{
			if (ft_strncmp(command_line[conveyor->i], "|", 2) == 0
			&& vars->arr_flags[conveyor->i] == 0)
				break ;
			conveyor->i++;
			conveyor->k++;
		}
		conveyor->arr_redirection2 = make_list_redirection(command_line,
		conveyor->i, conveyor->j, vars);
		conveyor->flag_pipe = 0;
		free_two_dimensional_array(conveyor->arr_redirection2);
	}
}

void	conveyor_res_12(char **command_line, t_vars *vars, t_conveyor *conveyor)
{
	conveyor->com_with_flags =
	make_command_arr_start(command_line, conveyor->i + 1, conveyor->j);
	conveyor->command_path = ft_join_path(vars, conveyor->com_with_flags);
	system_func(conveyor->command_path, conveyor->com_with_flags, vars);
	conveyor->j = 0;
	vars->flag_redirect = 0;
	free_two_dimensional_array(conveyor->com_with_flags);
	ptr_free(&conveyor->command_path);
}

void	conveyor_res_13(t_vars *vars)
{
	vars->count_pipe = 0;
	vars->count_redirect = 0;
	vars->flag_redirect = 0;
	dup2(vars->save_std_in, 0);
	dup2(vars->save_std_out, 1);
}
