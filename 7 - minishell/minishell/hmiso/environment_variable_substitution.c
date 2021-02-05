/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_variable_substitution.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:49:39 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/30 12:49:53 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		init_envir(t_envir *envir)
{
	envir->ptr = NULL;
	envir->env_var = NULL;
	envir->ptr2 = NULL;
	envir->ptr_for_free = NULL;
	envir->ptr_for_free2 = NULL;
	envir->i = 0;
	envir->j = 0;
	envir->flag = 0;
	envir->k = 0;
}

void			env_var_res_6(char **command_line, t_vars *vars, t_envir *envir)
{
	envir->i = 0;
	while (command_line[envir->i] != NULL)
		envir->i++;
	if (vars->arr_flags == NULL)
	{
		vars->arr_flags = malloc(sizeof(int) * (envir->i + 1));
		envir->i = 0;
		while (command_line[envir->i] != NULL)
		{
			if (command_line[envir->i][0] == '"'
			|| command_line[envir->i][0] == '\'')
				vars->arr_flags[envir->i] = 1;
			else
				vars->arr_flags[envir->i] = 0;
			envir->ptr_for_free2 = command_line[envir->i];
			command_line[envir->i] = delete_quotes(command_line[envir->i]);
			ptr_free(&envir->ptr_for_free2);
			envir->i++;
		}
		vars->arr_flags[envir->i] = 2;
	}
}

void			env_var_res_7(char **command_line, t_vars *vars, t_envir *envir)
{
	while (command_line[envir->i][envir->j] != '\0')
	{
		env_var_res(command_line, envir);
		if (command_line[envir->i][envir->j] == '$' && envir->flag != 1)
		{
			env_var_res_2(command_line, envir);
			if (envir->j - envir->k >= 1)
			{
				env_var_res_3(command_line, envir);
				env_var_res_4(vars, envir);
				env_var_res_5(command_line, envir);
			}
			else if (command_line[envir->i][envir->j] != '\0')
				envir->j++;
		}
		else
			envir->j++;
	}
}

char			**environment_variable_substitution(char **command_line,
t_vars *vars)
{
	t_envir	envir;

	init_envir(&envir);
	while (command_line[envir.i] != NULL)
	{
		env_var_res_7(command_line, vars, &envir);
		envir.i++;
		envir.j = 0;
	}
	env_var_res_6(command_line, vars, &envir);
	return (command_line);
}
