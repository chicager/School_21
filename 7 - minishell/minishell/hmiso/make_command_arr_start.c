/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command_arr_start.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 23:22:28 by curreg            #+#    #+#             */
/*   Updated: 2021/02/05 23:22:33 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**make_command_arr_start(char **command_line, int i, int j)
{
	int		k;
	int		count;
	char	**command_with_flags;

	k = i - j;
	count = 0;
	command_with_flags = malloc(sizeof(char *) * (j + 1));
	while (k < i)
	{
		command_with_flags[count] = ft_strdup(command_line[k]);
		k++;
		count++;
	}
	command_with_flags[count] = NULL;
	return (command_with_flags);
}
