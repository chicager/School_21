/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:45:30 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/28 19:08:50 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void			ft_env(t_vars *vars)
{
	int		i;
	char	**argv;

	i = 0;
	argv = NULL;
	while (vars->envp_copy[i] != NULL)
	{
		argv = ft_split(vars->envp_copy[i], '=');
		if (argv[1] != NULL)
		{
			ft_putstr_fd(argv[0], 1);
			ft_putchar_fd('=', 1);
			ft_putendl_fd(argv[1], 1);
		}
		i++;
		free_two_dimensional_array(argv);
	}
}
