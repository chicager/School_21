/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_new_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:59:30 by curreg            #+#    #+#             */
/*   Updated: 2020/11/29 17:00:15 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill_new_env(t_upd *upd, char **new_str, int *i, int *m)
{
	while (upd->new_str[*i] != NULL)
	{
		if (ft_strncmp(upd->new_str[*i], "=", 2) != 0)
		{
			new_str[*m] = ft_strdup(upd->new_str[*i]);
			*m = *m + 1;
		}
		*i = *i + 1;
	}
}
