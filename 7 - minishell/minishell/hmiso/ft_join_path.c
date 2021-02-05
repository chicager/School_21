/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:22:30 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/28 18:56:19 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_join_path(t_vars *vars, char **com_with_flags)
{
	char *command_path;
	char *fre_ptr;
	char *ptr;

	ptr = ft_strdup(com_with_flags[0]);
	command_path = check_system_func(vars, ptr);
	if (command_path == NULL)
	{
		command_path = ft_strdup(com_with_flags[0]);
	}
	else
	{
		fre_ptr = command_path;
		command_path = ft_strjoin(command_path, "/");
		ptr_free(&fre_ptr);
		fre_ptr = command_path;
		command_path = ft_strjoin(command_path, com_with_flags[0]);
		ptr_free(&fre_ptr);
	}
	ptr_free(&ptr);
	return (command_path);
}
