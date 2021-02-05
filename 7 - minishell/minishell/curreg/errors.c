/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:51:37 by curreg            #+#    #+#             */
/*   Updated: 2020/11/30 12:01:59 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	id_error(char *cmd)
{
	ft_putstr_fd("minishell>export: `", 1);
	ft_putstr_fd(cmd, 1);
	ft_putstr_fd("': not a valid identifier\n", 1);
	g_error = 1;
}

void	command_error(char *cmd, t_vars *vars)
{
	ft_putstr_fd("minishell>", 1);
	if (ft_strcmp("$?", cmd) == 0)
	{
		if (vars->cd_flag == 1 && vars->err_flag == 0)
		{
			ft_putstr_fd(ft_itoa(g_error), 1);
			vars->err_flag = 1;
		}
		else if (vars->err_flag == 0)
		{
			ft_putstr_fd(ft_itoa(g_error), 1);
			vars->err_flag = 1;
		}
		else
			ft_putstr_fd(ft_itoa(g_error), 1);
	}
	else
	{
		vars->err_flag = 1;
		ft_putstr_fd(cmd, 1);
	}
	ft_putstr_fd(": command not found\n", 1);
	g_error = 127;
}

void	syntax_error(char *cmd)
{
	ft_putstr_fd("minishell>syntax error near unexpected token `", 2);
	if (cmd[1] == ';')
	{
		ft_putchar_fd(cmd[0], 2);
		ft_putchar_fd(cmd[0], 2);
	}
	else if (cmd[0] == ';')
		ft_putchar_fd(cmd[0], 2);
	else
		ft_putstr_fd(cmd, 2);
	ft_putstr_fd("'\n", 2);
	g_error = 258;
}

void	cd_error(char *cmd, char *arg, char *err)
{
	ft_putstr_fd("minishell>", 1);
	ft_putstr_fd(cmd, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(arg, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(err, 1);
	ft_putstr_fd("\n", 1);
	g_error = 1;
}
