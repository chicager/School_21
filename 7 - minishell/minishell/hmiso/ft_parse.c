/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 23:24:57 by curreg            #+#    #+#             */
/*   Updated: 2021/02/05 23:25:02 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		init_parse(t_parse *parse, char *line)
{
	parse->count = 0;
	parse->i = 0;
	parse->j = 0;
	parse->flag = 0;
	parse->command_line = count_commands(line);
}

static void		ft_parse_res(char *line, t_parse *parse)
{
	if (line[parse->i] != ' ')
	{
		parse->j = parse->i;
		while ((line[parse->i] != ' ' || parse->flag == 1
		|| parse->flag == 2) && line[parse->i] != '\0')
		{
			if (line[parse->i] == '"' || line[parse->i] == '\'')
			{
				if (parse->flag == 0 && line[parse->i] == '"')
					parse->flag = 1;
				else if (parse->flag == 1 && line[parse->i] == '"')
					parse->flag = 0;
				else if (parse->flag == 0 && line[parse->i] == '\'')
					parse->flag = 2;
				else if (parse->flag == 2 && line[parse->i] == '\'')
					parse->flag = 0;
			}
			parse->i++;
		}
		parse->command_line[parse->count] = ft_substr(line,
		parse->j, parse->i - parse->j);
		parse->count++;
	}
	else
		parse->i++;
}

char			**ft_parse(char *line, t_vars *vars)
{
	t_parse	parse;

	init_parse(&parse, line);
	while (line[parse.i] != '\0')
	{
		ft_parse_res(line, &parse);
	}
	parse.command_line[parse.count] = NULL;
	environment_variable_substitution(parse.command_line, vars);
	return (parse.command_line);
}
