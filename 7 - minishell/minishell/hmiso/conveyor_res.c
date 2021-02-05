/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conveyor_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:57:13 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/27 21:02:52 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_conveyor(t_conveyor *conveyor)
{
	conveyor->j = 1;
	conveyor->i = 0;
	conveyor->k = 0;
	conveyor->flag = 0;
	conveyor->flag_pipe = 0;
	conveyor->command_path = NULL;
	conveyor->com_with_flags = NULL;
	conveyor->arr_redirection = NULL;
	conveyor->arr_redirection2 = NULL;
}

void	conveyor_res(char **command_line, t_vars *vars, t_conveyor *conveyor)
{
	ft_pipe_eof();
	create_file(&command_line[conveyor->i], &vars->arr_flags[conveyor->i]);
	vars->flag_redirect = 0;
	conveyor->flag_pipe = 1;
	conveyor->i++;
}

void	conveyor_res_2(char **command_line, t_vars *vars, t_conveyor *conveyor)
{
	create_file(&command_line[conveyor->i], &vars->arr_flags[conveyor->i]);
	conveyor->com_with_flags = make_command_arr_start(command_line,
	conveyor->i, (conveyor->j - 1));
	conveyor->command_path = ft_join_path(vars, conveyor->com_with_flags);
	ft_pipe(conveyor->command_path, conveyor->com_with_flags, vars);
	conveyor->j = 0;
	vars->flag_redirect = 0;
	conveyor->flag_pipe = 1;
	free_two_dimensional_array(conveyor->com_with_flags);
	free(conveyor->command_path);
}

void	conveyor_res_3(char **command_line, t_vars *vars, t_conveyor *conveyor)
{
	conveyor->command_path = ft_join_path(vars, conveyor->com_with_flags);
	while (command_line[conveyor->i + 1] != NULL)
	{
		if (ft_strncmp(command_line[conveyor->i], "|", 2) == 0
		&& vars->arr_flags[conveyor->i] == 0)
		{
			break ;
		}
		conveyor->i++;
		conveyor->k++;
	}
	conveyor->arr_redirection = make_list_redirection(command_line,
	conveyor->i, conveyor->k, vars);
	ft_redirects(conveyor->command_path, conveyor->com_with_flags,
	conveyor->arr_redirection, vars);
	conveyor->j = 0;
	conveyor->k = 0;
	vars->flag_redirect = 1;
	conveyor->flag_pipe = 0;
	if (conveyor->arr_redirection[0] != NULL)
		conveyor->i--;
	free_two_dimensional_array(conveyor->com_with_flags);
	ptr_free(&conveyor->command_path);
	free_two_dimensional_array(conveyor->arr_redirection);
}

void	conveyor_res_4(char **command_line, t_vars *vars, t_conveyor *conveyor)
{
	while (command_line[conveyor->i + 1] != NULL)
	{
		if (ft_strncmp(command_line[conveyor->i], "|", 2) == 0
		&& vars->arr_flags[conveyor->i] == 0)
		{
			break ;
		}
		conveyor->i++;
		conveyor->k++;
	}
	conveyor->k = 0;
	vars->flag_redirect = 1;
	conveyor->flag_pipe = 0;
	conveyor->i--;
}
