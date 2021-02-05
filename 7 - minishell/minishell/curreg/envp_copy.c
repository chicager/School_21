/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:41:52 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/28 17:24:04 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		envp_copy(char **envp, t_vars *vars)
{
	int i;

	i = 0;
	while (envp[i] != NULL)
	{
		i++;
	}
	vars->envp_copy = malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (envp[i] != NULL)
	{
		vars->envp_copy[i] = ft_strdup(envp[i]);
		i++;
	}
	vars->envp_copy[i] = NULL;
}
