/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:36:32 by curreg            #+#    #+#             */
/*   Updated: 2020/11/28 17:21:36 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	check_only_name(char *str, int *i, int *not_only_name)
{
	*i = 1;
	while (str[*i] != '\0')
	{
		if (str[*i] == '=')
		{
			*not_only_name = 1;
			break ;
		}
		*i = *i + 1;
	}
	*i = 0;
}

static int	is_correct_chars(char *str, int *i)
{
	if (*i == 0)
	{
		if (!(str[*i] == '_' ||
			(str[*i] >= 'a' && str[*i] <= 'z') ||
			(str[*i] >= 'A' && str[*i] <= 'Z')))
			return (0);
		*i = *i + 1;
	}
	else
	{
		if (!(str[*i] == '_' || str[*i] == '=' || str[*i] == '"' ||
			(str[*i] >= 'a' && str[*i] <= 'z') ||
			(str[*i] >= 'A' && str[*i] <= 'Z') ||
			(str[*i] >= '0' && str[*i] <= '9')))
			return (0);
		*i = *i + 1;
	}
	return (1);
}

int			check_valid_id(char *str)
{
	int i;
	int not_only_name;

	not_only_name = 0;
	if (str[0] == '=')
		return (0);
	check_only_name(str, &i, &not_only_name);
	if (not_only_name)
	{
		while (str[i] != '=')
		{
			if (!is_correct_chars(str, &i))
				return (0);
		}
	}
	else
	{
		while (str[i] != '\0')
		{
			if (!is_correct_chars(str, &i))
				return (0);
		}
	}
	return (1);
}
