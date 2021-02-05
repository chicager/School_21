/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_envp_res.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:01:10 by curreg            #+#    #+#             */
/*   Updated: 2020/11/29 17:01:52 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_envp_res(t_upd *upd)
{
	int		i;
	int		m;
	char	**new_str;

	i = 0;
	m = 0;
	while (upd->new_str[i] != NULL)
	{
		if (ft_strncmp(upd->new_str[i], "=", 2) != 0)
			m++;
		else
		{
			g_error = 1;
			ft_putstr_fd("export: `=': not a valid identifier\n", 2);
		}
		i++;
	}
	new_str = malloc(sizeof(char*) * (m + 1));
	i = 0;
	m = 0;
	fill_new_env(upd, new_str, &i, &m);
	new_str[m] = NULL;
	upd->new_str = new_str;
}
