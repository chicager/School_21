/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:05:33 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/26 16:07:03 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_redirect(char **command_arr, t_vars *vars)
{
	int i;

	i = 0;
	while (command_arr[i] != NULL)
	{
		if ((ft_strncmp(command_arr[i], ">", 2) == 0 ||
		ft_strncmp(command_arr[i], "<", 2) == 0 ||
		ft_strncmp(command_arr[i], ">>", 3) == 0)
		&& vars->arr_flags[i] == 0)
		{
			vars->count_redirect++;
		}
		i++;
	}
}
