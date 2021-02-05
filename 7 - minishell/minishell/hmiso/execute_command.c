/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:10:28 by hmiso             #+#    #+#             */
/*   Updated: 2021/02/05 23:24:37 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		init_execute(t_execute *execute)
{
	execute->command_line = NULL;
	execute->command_path = NULL;
	execute->ptr_fre = NULL;
}

static void		execute_command_res(t_execute *execute, t_vars *vars)
{
	if (!(checking_recoded_functions(execute->command_line, vars)))
	{
		execute->command_path = check_system_func(vars,
										execute->command_line[0]);
		if (execute->command_path == NULL)
			execute->command_path = ft_strdup(execute->command_line[0]);
		else
		{
			execute->ptr_fre = execute->command_path;
			execute->command_path = ft_strjoin(execute->command_path, "/");
			ptr_free(&execute->ptr_fre);
			execute->ptr_fre = execute->command_path;
			execute->command_path = ft_strjoin(execute->command_path,
			execute->command_line[0]);
			ptr_free(&execute->ptr_fre);
		}
		system_func(execute->command_path, execute->command_line, vars);
	}
}

static void		execute_command_res_2(t_execute *execute,
t_vars *vars, char *line)
{
	if (execute->command_line != NULL)
		free_two_dimensional_array(execute->command_line);
	if (execute->command_path != NULL)
		ptr_free(&execute->command_path);
	ptr_free(&line);
	free(vars->arr_flags);
	vars->arr_flags = NULL;
}

void			execute_command(char *line, t_vars *vars)
{
	t_execute execute;

	init_execute(&execute);
	line = check_space(line);
	execute.command_line = ft_parse(line, vars);
	if (execute.command_line[0] != NULL)
	{
		if ((execute.command_line = verification_of_tokens(execute.command_line,
		vars)) != NULL)
		{
			execute.command_line = move_arguments(execute.command_line, vars);
			check_pipe(execute.command_line, vars);
			check_redirect(execute.command_line, vars);
			if (vars->count_pipe == 0 && vars->count_redirect == 0)
				execute_command_res(&execute, vars);
			else
			{
				ft_conveyor(execute.command_line, vars);
				dup2(vars->save_std_in, 0);
				dup2(vars->save_std_out, 1);
			}
		}
	}
	execute_command_res_2(&execute, vars, line);
}
