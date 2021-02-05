/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:59:20 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/28 16:59:05 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	aux_check_dup(char **argv, int *i, int *j, int *count)
{
	if (argv[*i] != NULL && argv[*j] != NULL &&
		ft_strlen(argv[*i]) == ft_strlen(argv[*j]))
	{
		if (ft_strncmp(argv[*i], argv[*j], ft_strlen(argv[*i])) == 0)
			*count = *count + 1;
	}
}

static void	aux_check_dup2(char **argv, int *i, int *count, int *count_2)
{
	if (*count > 1)
	{
		free(argv[*i]);
		argv[*i] = NULL;
		*count_2 = *count_2 + 1;
	}
	*count = 0;
}

static char	**get_new_argv(char **argv, int i, int count_2)
{
	char	**new_argv;
	int		count;
	int		j;

	count = 0;
	j = 0;
	new_argv = malloc(sizeof(char *) * (i - count_2 + 1));
	while (count < i)
	{
		if (argv[count] != NULL)
		{
			new_argv[j] = ft_strdup(argv[count]);
			j++;
		}
		count++;
	}
	new_argv[j] = NULL;
	return (new_argv);
}

char		**check_duplicate(char **argv)
{
	int		i;
	int		j;
	int		count;
	int		count_2;
	int		count_3;

	i = 0;
	j = 0;
	count = 0;
	count_2 = 0;
	count_3 = 0;
	while (argv[count_3] != NULL)
		count_3++;
	while (argv[i] != NULL)
	{
		while (j < count_3)
		{
			aux_check_dup(argv, &i, &j, &count);
			j++;
		}
		aux_check_dup2(argv, &i, &count, &count_2);
		j = 0;
		i++;
	}
	return (get_new_argv(argv, i, count_2));
}
