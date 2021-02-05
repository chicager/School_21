/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_patch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:33:34 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/30 16:25:55 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*init_path(t_vars *vars, char *arg)
{
	char	**ptr;
	char	*value;
	int		i;
	int		len_arg;

	i = 0;
	len_arg = ft_strlen(arg);
	value = ft_strdup("");
	while (vars->envp_copy[i] != NULL)
	{
		ptr = ft_split(vars->envp_copy[i], '=');
		if (ft_strncmp(ptr[0], arg, (len_arg + 1)) == 0)
		{
			free(value);
			if (ptr[1] != NULL)
				value = ft_strdup(ptr[1]);
			else
				value = ft_strdup("");
		}
		free_two_dimensional_array(ptr);
		ptr = NULL;
		i++;
	}
	return (value);
}
