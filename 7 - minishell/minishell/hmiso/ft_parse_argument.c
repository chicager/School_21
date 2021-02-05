/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 23:21:56 by curreg            #+#    #+#             */
/*   Updated: 2021/02/05 23:21:58 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_parse_argument(char *line, t_vars *vars)
{
	int		i;
	char	**argv;

	i = 0;
	if (line[0] == ';')
	{
		syntax_error(line);
		return ;
	}
	argv = semicolon(line);
	while (argv[i] != NULL)
	{
		if (ft_strlen(argv[i]) != 0)
			execute_command(argv[i], vars);
		i++;
	}
	free_two_dimensional_array(argv);
}
