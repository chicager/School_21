/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:02:21 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/30 12:07:07 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	aux_ft_unset(t_vars *vars, char **str, t_unset_vars *uv)
{
	while (uv->count < uv->count_env)
	{
		uv->argv = ft_split(vars->envp_copy[uv->count], '=');
		if (uv->argv != NULL &&
			(ft_strlen(uv->argv[0]) == ft_strlen(str[uv->m])))
		{
			if (ft_strncmp(uv->argv[0], str[uv->m],
							ft_strlen(uv->argv[0])) == 0)
			{
				free(vars->envp_copy[uv->count]);
				vars->envp_copy[uv->count] = NULL;
				uv->flag++;
				free_two_dimensional_array(uv->argv);
				uv->count = 0;
				break ;
			}
		}
		free_two_dimensional_array(uv->argv);
		uv->count++;
	}
	uv->m++;
	uv->count = 0;
}

static void	aux_ft_unset2(t_vars *vars, t_unset_vars *uv)
{
	uv->env_new = malloc(sizeof(char**) * (uv->count_env));
	while (uv->i < uv->count_env)
	{
		if (vars->envp_copy[uv->i] != NULL)
		{
			uv->env_new[uv->j] = ft_strdup(vars->envp_copy[uv->i]);
			uv->j++;
		}
		uv->i++;
	}
	uv->env_new[uv->j] = NULL;
	uv->i = 0;
	while (uv->i < uv->count_env)
	{
		if (vars->envp_copy[uv->i] != NULL)
		{
			free(vars->envp_copy[uv->i]);
		}
		uv->i++;
	}
}

void		ft_unset(t_vars *vars, char **str)
{
	t_unset_vars uv;

	ft_memset(&uv, 0, sizeof(t_unset_vars));
	while (vars->envp_copy[uv.count_env] != NULL)
		uv.count_env++;
	while (str[uv.j] != NULL)
		uv.j++;
	while (uv.m < uv.j)
		aux_ft_unset(vars, str, &uv);
	uv.j = 0;
	uv.count = 0;
	uv.i = 0;
	if (uv.flag > 0)
	{
		aux_ft_unset2(vars, &uv);
		free(vars->envp_copy);
		envp_copy(uv.env_new, vars);
		free_two_dimensional_array(uv.env_new);
	}
}
