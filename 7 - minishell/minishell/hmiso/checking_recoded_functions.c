/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_recoded_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:31:40 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/30 12:16:08 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	checking_recoded_functions_res(char **command_line, t_vars *vars)
{
	if (ft_strncmp(command_line[0], "cd", 3) == 0)
	{
		ft_cd(command_line, vars);
		set_pwd("PWD", vars);
		vars->err_flag = 0;
		g_error = 1;
		return (1);
	}
	else if (ft_strncmp(command_line[0], "pwd", 4) == 0)
	{
		ft_pwd();
		vars->err_flag = 0;
		g_error = 0;
		return (1);
	}
	else if ((ft_strncmp(command_line[0], "echo", 5) == 0)
	&& (command_line[1] != NULL)
	&& (ft_strncmp(command_line[1], "-n", 3)) == 0)
	{
		ft_echo_n(&command_line[0]);
		vars->err_flag = 0;
		g_error = 0;
		return (1);
	}
	return (0);
}

static int	checking_recoded_functions_res_2(char **command_line, t_vars *vars)
{
	if (ft_strncmp(command_line[0], "echo", 5) == 0)
	{
		ft_echo(&command_line[0]);
		vars->err_flag = 0;
		g_error = 0;
		return (1);
	}
	else
		return (0);
}

static int	checking_recoded_functions_res_3(char **command_line, t_vars *vars)
{
	if (ft_strncmp(command_line[0], "env", 4) == 0)
	{
		if (command_line[1] != NULL)
		{
			ft_putstr_fd("minishell>env: ", 1);
			ft_putstr_fd(command_line[1], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			g_error = 127;
		}
		else
		{
			ft_env(vars);
			vars->err_flag = 0;
			g_error = 0;
		}
		return (1);
	}
	else
		return (0);
}

static int	checking_recoded_functions_res_4(char **command_line, t_vars *vars)
{
	if (ft_strncmp(command_line[0], "export", 7) == 0)
	{
		export_out(vars, &command_line[0]);
		vars->err_flag = 0;
		if (!vars->err_flag_export)
			g_error = 0;
		vars->err_flag_export = 0;
		return (1);
	}
	else if (ft_strncmp(command_line[0], "exit", 6) == 0)
	{
		ft_putstr_fd("exit\n", 1);
		ft_exit(command_line);
		vars->err_flag = 0;
		g_error = 0;
		return (1);
	}
	else
		return (0);
}

int			checking_recoded_functions(char **command_line, t_vars *vars)
{
	if (checking_recoded_functions_res(command_line, vars) == 1)
		return (1);
	else if (checking_recoded_functions_res_2(command_line, vars) == 1)
		return (1);
	else if (checking_recoded_functions_res_3(command_line, vars) == 1)
		return (1);
	else if (checking_recoded_functions_res_4(command_line, vars) == 1)
		return (1);
	else if (ft_strncmp(command_line[0], "unset", 6) == 0)
	{
		ft_unset(vars, &command_line[1]);
		vars->err_flag = 0;
		g_error = 0;
		return (1);
	}
	return (0);
}
