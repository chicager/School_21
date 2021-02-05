/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conveyor_res_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:03:48 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/30 12:18:35 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	conveyor_res_5(char **command_line, t_vars *vars, t_conveyor *conveyor)
{
	conveyor->command_path = ft_join_path(vars, conveyor->com_with_flags);
	while (command_line[conveyor->i + 1] != NULL)
	{
		if ((ft_strncmp(command_line[conveyor->i], "|", 2) == 0
		|| ft_strncmp(command_line[conveyor->i], ">", 2) == 0
		|| ft_strncmp(command_line[conveyor->i], ">>", 3) == 0)
		&& vars->arr_flags[conveyor->i] != 1)
		{
			if ((ft_strncmp(command_line[conveyor->i], ">", 2) == 0
			|| ft_strncmp(command_line[conveyor->i], ">>", 3) == 0)
			&& vars->arr_flags[conveyor->i] == 0)
			{
				conveyor->flag = 2;
			}
			else
				conveyor->flag = 1;
			break ;
		}
		conveyor->i++;
		conveyor->k++;
	}
	conveyor->arr_redirection = make_list_redirection_revers(command_line,
	conveyor->i, conveyor->k, vars);
}

void	conveyor_res_6(t_vars *vars, t_conveyor *conveyor)
{
	if (conveyor->flag == 0)
	{
		ft_redirects_revers(conveyor, vars);
		conveyor->flag_pipe = 1;
	}
	if (conveyor->flag == 1)
	{
		ft_redirects_pipe(conveyor->command_path,
		conveyor->com_with_flags, conveyor->arr_redirection, vars);
		conveyor->flag_pipe = 1;
	}
}

void	conveyor_res_7(char **command_line, t_vars *vars, t_conveyor *conveyor)
{
	if (conveyor->flag == 2)
	{
		conveyor->j = 0;
		conveyor->k = 0;
		while (command_line[conveyor->i + 1] != NULL)
		{
			if (ft_strncmp(command_line[conveyor->i], "|", 2)
			== 0 && vars->arr_flags[conveyor->i] == 0)
			{
				break ;
			}
			conveyor->i++;
			conveyor->k++;
		}
		conveyor->arr_redirection2 = make_list_redirection(command_line,
		conveyor->i, conveyor->j, vars);
		ft_redirects_redirect(conveyor, vars);
		conveyor->flag_pipe = 0;
		free_two_dimensional_array(conveyor->arr_redirection2);
	}
}

void	conveyor_res_8(t_conveyor *conveyor)
{
	conveyor->j = 0;
	conveyor->k = 0;
	conveyor->flag = 0;
	free_two_dimensional_array(conveyor->com_with_flags);
	ptr_free(&conveyor->command_path);
	free_two_dimensional_array(conveyor->arr_redirection);
}

void	conveyor_res_9(char **command_line, t_vars *vars, t_conveyor *conveyor)
{
	while (command_line[conveyor->i + 1] != NULL)
	{
		if ((ft_strncmp(command_line[conveyor->i], "|", 2) == 0
		|| ft_strncmp(command_line[conveyor->i], ">", 2) == 0
		|| ft_strncmp(command_line[conveyor->i], ">>", 3) == 0)
		&& vars->arr_flags[conveyor->i] != 1)
		{
			if ((ft_strncmp(command_line[conveyor->i], ">", 2) == 0
			|| ft_strncmp(command_line[conveyor->i], ">>", 3) == 0)
			&& vars->arr_flags[conveyor->i] == 0)
			{
				conveyor->flag = 2;
			}
			else
				conveyor->flag = 1;
			break ;
		}
		conveyor->i++;
		conveyor->k++;
	}
	conveyor->arr_redirection =
	make_list_redirection_revers(command_line,
	conveyor->i, conveyor->k, vars);
}
