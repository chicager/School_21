/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quotes_res.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:32:25 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/28 16:37:51 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	quotes_res_4(t_quotes *quotes, char *line)
{
	quotes->line_dubl[quotes->count] = line[quotes->i];
	quotes->count++;
	quotes->i++;
}
