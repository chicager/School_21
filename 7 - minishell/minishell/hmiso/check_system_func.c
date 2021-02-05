/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_system_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:41:45 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/27 14:08:13 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		init_sys_func(t_sys_func *sys_func, t_vars *vars, char *str)
{
	sys_func->path = NULL;
	sys_func->ptr = NULL;
	sys_func->i = 0;
	sys_func->flag = 0;
	sys_func->ptr = init_path(vars, "PATH");
	sys_func->path = ft_split(sys_func->ptr, ':');
	free(sys_func->ptr);
	while (str[sys_func->i] != '\0')
	{
		str[sys_func->i] = ft_tolower(str[sys_func->i]);
		sys_func->i++;
	}
	sys_func->i = 0;
}

char			*check_system_func(t_vars *vars, char *str)
{
	t_sys_func sys_func;

	init_sys_func(&sys_func, vars, str);
	while (sys_func.path[sys_func.i] != NULL)
	{
		if ((sys_func.dir = opendir(sys_func.path[sys_func.i])) == NULL)
		{
			sys_func.i++;
			continue;
		}
		while ((sys_func.st = readdir(sys_func.dir)) != NULL)
			if (ft_strlen(sys_func.st->d_name) == ft_strlen(str))
				if ((ft_strncmp(sys_func.st->d_name, str, ft_strlen(str))) == 0)
				{
					sys_func.ptr = ft_strdup(sys_func.path[sys_func.i]);
					free_two_dimensional_array(sys_func.path);
					closedir(sys_func.dir);
					return (sys_func.ptr);
				}
		closedir(sys_func.dir);
		sys_func.i++;
	}
	free_two_dimensional_array(sys_func.path);
	return (NULL);
}
