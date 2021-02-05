/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space_res.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:12:26 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/27 13:19:44 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_space_res_4(t_space *space)
{
	if ((space->line[space->i] == '\'' || space->line[space->i] == '"')
	&& space->flag == 0 && space->line[space->i + 1] != '\0')
	{
		space->flag = 1;
		space->i++;
	}
	if ((space->line[space->i] == '\'' || space->line[space->i] == '"')
	&& space->flag == 1 && space->line[space->i + 1] != '\0')
	{
		space->flag = 0;
		space->i++;
	}
}
