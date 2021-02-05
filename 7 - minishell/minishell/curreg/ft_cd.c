/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:07:05 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/30 12:05:45 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_cd(char **command_line, t_vars *vars)
{
	char	*path;

	path = NULL;
	errno = 0;
	if (command_line[0 + 1] != NULL)
	{
		set_pwd("OLDPWD", vars);
		path = command_line[1];
		if (chdir(path) == -1)
		{
			set_g_error(errno);
			vars->cd_flag = 1;
			vars->err_flag = 0;
			cd_error(command_line[0], command_line[1], strerror(errno));
		}
		path = NULL;
	}
	else
	{
		path = init_path(vars, "HOME");
		chdir(path);
		free(path);
		path = NULL;
	}
}
