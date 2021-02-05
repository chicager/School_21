/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:36:43 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/28 16:36:46 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		init_quotes(t_quotes *quotes)
{
	quotes->i = 0;
	quotes->flag = 0;
	quotes->count = 0;
}

static int		quotes_res(t_quotes *quotes, char *line)
{
	if (line[quotes->i] == '"' && quotes->flag == 0)
	{
		line[quotes->i] = 10;
		quotes->flag = 1;
		return (1);
	}
	else if (line[quotes->i] == '\'' && quotes->flag == 0)
	{
		line[quotes->i] = 10;
		quotes->flag = 2;
		return (1);
	}
	else if (line[quotes->i] == '\'' && quotes->flag == 2)
	{
		line[quotes->i] = 10;
		quotes->flag = 0;
		return (1);
	}
	return (0);
}

static int		quotes_res_2(t_quotes *quotes, char *line)
{
	if (line[quotes->i] == ' ' && quotes->flag == 0)
	{
		line[quotes->i] = 12;
		return (1);
	}
	else if (line[quotes->i] == '"' && quotes->flag == 1)
	{
		line[quotes->i] = 10;
		quotes->flag = 0;
		return (1);
	}
	return (0);
}

static void		quotes_res_3(t_quotes *quotes, char *line)
{
	if ((line[quotes->i] == '\''
	|| line[quotes->i] == '"') && quotes->flag == 0)
	{
		quotes->flag = 1;
		quotes_res_4(quotes, line);
	}
	else if ((line[quotes->i] == '\''
	|| line[quotes->i] == '"') && quotes->flag == 1)
	{
		quotes->flag = 0;
		quotes_res_4(quotes, line);
	}
	else
	{
		if (quotes->flag != 1 || line[quotes->i] != 12)
			if (line[quotes->i] != 10)
			{
				quotes->line_dubl[quotes->count] = line[quotes->i];
				quotes->count++;
			}
		quotes->i++;
	}
}

char			*delete_quotes(char *line)
{
	t_quotes	quotes;

	init_quotes(&quotes);
	while (line[quotes.i] != '\0')
	{
		if (quotes_res(&quotes, line))
			quotes.i++;
		else if (quotes_res_2(&quotes, line))
			quotes.i++;
		else
			quotes.i++;
	}
	quotes.line_dubl = ft_calloc((quotes.i + 1), sizeof(char));
	init_quotes(&quotes);
	while (line[quotes.i] != '\0')
		quotes_res_3(&quotes, line);
	return (quotes.line_dubl);
}
