/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:17:57 by curreg            #+#    #+#             */
/*   Updated: 2020/11/28 22:04:45 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_pwd(char *var, t_vars *vars)
{
	char	*pwd[2];
	char	*ptr;

	if (!ft_strcmp("OLDPWD", var))
		pwd[0] = "OLDPWD=";
	else if (!ft_strcmp("PWD", var))
		pwd[0] = "PWD=";
	ptr = getcwd(NULL, 0);
	pwd[0] = ft_strjoin(pwd[0], ptr);
	pwd[1] = NULL;
	free(ptr);
	update_envp(pwd, vars);
	free(pwd[0]);
}
