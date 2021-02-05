/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:03:47 by hmiso             #+#    #+#             */
/*   Updated: 2021/02/05 23:24:02 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		count_commands_res(char *line, int *count, int *flag, int *i)
{
	if (line[*i] != ' ')
	{
		*count = *count + 1;
		while ((line[*i] != ' ' || *flag == 1 || *flag == 2)
		&& line[*i] != '\0')
		{
			if (line[*i] == '"' || line[*i] == '\'')
			{
				if (*flag == 0 && line[*i] == '"')
					*flag = 1;
				else if (*flag == 1 && line[*i] == '"')
					*flag = 0;
				else if (*flag == 0 && line[*i] == '\'')
					*flag = 2;
				else if (*flag == 2 && line[*i] == '\'')
					*flag = 0;
			}
			*i = *i + 1;
		}
	}
	else
		*i = *i + 1;
}

char			**count_commands(char *line)
{
	int		i;
	int		count;
	char	**command_line;
	int		flag;

	command_line = NULL;
	count = 0;
	flag = 0;
	i = 0;
	while (line[i] != '\0')
	{
		count_commands_res(line, &count, &flag, &i);
	}
	command_line = malloc(sizeof(char *) * (count + 1));
	return (command_line);
}
