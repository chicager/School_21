/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:32:57 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/29 20:28:29 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		init_semic(t_semic *semic)
{
	semic->i = 0;
	semic->flag = 0;
	semic->count = 0;
}

static void		semicolon_res(char *line, t_semic *semic)
{
	while (line[semic->i] != '\0')
	{
		if ((line[semic->i] == '\'' || line[semic->i] == '"')
		&& semic->flag == 0 && line[semic->i + 1] != '\0')
		{
			semic->flag = 1;
			semic->i++;
		}
		else if ((line[semic->i] == '\'' || line[semic->i] == '"')
		&& semic->flag == 1 && line[semic->i + 1] != '\0')
		{
			semic->flag = 0;
			semic->i++;
		}
		else if (semic->flag == 0 && line[semic->i] == ';')
		{
			semic->count++;
			semic->i++;
		}
		else
			semic->i++;
	}
}

static void		semicolon_res_2(char *line, t_semic *semic)
{
	while (line[semic->i] != '\0')
	{
		if ((line[semic->i] == '\'' || line[semic->i] == '"')
		&& semic->flag == 0)
			semic->flag = 1;
		else if ((line[semic->i] == '\'' || line[semic->i] == '"')
		&& semic->flag == 1)
			semic->flag = 0;
		if (semic->flag == 0 && line[semic->i] == ';')
		{
			semic->argv[semic->count] = ft_substr(line, 0, semic->i);
			line = &line[semic->i + 1];
			semic->count++;
			semic->i = 0;
			continue ;
		}
		if (line[semic->i] != '\0' && line[semic->i + 1] == '\0')
		{
			semic->argv[semic->count] = ft_substr(line, 0, semic->i + 1);
			semic->count++;
		}
		semic->i++;
	}
}

char			**semicolon(char *line)
{
	t_semic semic;

	init_semic(&semic);
	semicolon_res(line, &semic);
	semic.argv = malloc(sizeof(char*) * (semic.count + 2));
	semic.i = 0;
	semic.count = 0;
	semic.flag = 0;
	semicolon_res_2(line, &semic);
	semic.argv[semic.count] = NULL;
	semic.count = 0;
	return (semic.argv);
}
