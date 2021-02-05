/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:14:43 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/30 12:08:23 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	init_upd(t_upd *upd, char **str)
{
	upd->i = 0;
	upd->j = 0;
	upd->new_envp = NULL;
	upd->ar_1 = NULL;
	upd->ar_2 = NULL;
	upd->count = 0;
	upd->flag = 0;
	upd->ptr = NULL;
	upd->new_str = str;
}

static void	part_update_envp(t_upd *upd, t_vars *vars)
{
	while (vars->envp_copy[upd->count] != NULL)
	{
		upd->ar_1 = ft_split(vars->envp_copy[upd->count], '=');
		if (ft_strlen(upd->ar_1[0]) == ft_strlen(upd->ar_2[0]))
		{
			if (ft_strncmp(upd->ar_1[0], upd->ar_2[0],
							ft_strlen(upd->ar_1[0])) == 0)
			{
				if (upd->ar_2[1] != NULL)
				{
					free(vars->envp_copy[upd->count]);
					vars->envp_copy[upd->count] =
						ft_strjoin(upd->ar_2[0], "=");
					upd->ptr = vars->envp_copy[upd->count];
					vars->envp_copy[upd->count] =
						ft_strjoin(vars->envp_copy[upd->count], upd->ar_2[1]);
					free(upd->ptr);
				}
				free(upd->new_str[upd->j]);
				upd->new_str[upd->j] = NULL;
			}
		}
		free_two_dimensional_array(upd->ar_1);
		upd->count++;
	}
}

static void	part2_update_envp(t_upd *upd, t_vars *vars)
{
	while (upd->flag < upd->count)
	{
		if (upd->new_str[upd->flag] != NULL)
			upd->i++;
		upd->flag++;
	}
	upd->j = 0;
	while (vars->envp_copy[upd->j] != NULL)
		upd->j++;
	upd->new_envp = malloc(sizeof(char *) * (upd->j + upd->i + 1));
	upd->j = 0;
	upd->i = 0;
	while (vars->envp_copy[upd->i] != NULL)
	{
		upd->new_envp[upd->i] = vars->envp_copy[upd->i];
		upd->i++;
	}
}

static void	part3_update_envp(t_upd *upd)
{
	while (upd->j < upd->count)
	{
		if (upd->new_str[upd->j] != NULL)
		{
			upd->new_envp[upd->i] = upd->new_str[upd->j];
			upd->i++;
		}
		upd->j++;
	}
}

void		update_envp(char **str, t_vars *vars)
{
	t_upd	upd;

	init_upd(&upd, str);
	update_envp_res(&upd);
	while (upd.new_str[upd.i] != NULL)
		upd.i++;
	while (upd.j < upd.i)
	{
		upd.ar_2 = ft_split(upd.new_str[upd.j], '=');
		part_update_envp(&upd, vars);
		free_two_dimensional_array(upd.ar_2);
		upd.count = 0;
		upd.j++;
	}
	upd.count = upd.i;
	upd.i = 0;
	part2_update_envp(&upd, vars);
	part3_update_envp(&upd);
	upd.new_envp[upd.i] = NULL;
	free(vars->envp_copy);
	envp_copy(upd.new_envp, vars);
	free_two_dimensional_array(upd.new_envp);
	free(upd.new_str);
}
