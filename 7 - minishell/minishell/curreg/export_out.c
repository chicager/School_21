/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:52:35 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/30 12:04:27 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	check_line_value(char **line)
{
	int		i;
	int		length;
	char	*temp;

	i = 0;
	temp = NULL;
	length = ft_strlen(*line);
	if (length > 1 && (*line)[length - 1] == '=')
	{
		temp = *line;
		*line = ft_strjoin(*line, "\"\"");
		free(temp);
		temp = NULL;
	}
}

static void	output_export_item(char **argv, t_vars *vars, int *i)
{
	ft_putstr_fd("declare -x ", 1);
	argv = ft_split(vars->envp_copy[*i], '=');
	ft_putstr_fd(argv[0], 1);
	if (argv[1] != NULL)
	{
		if (!ft_strcmp(argv[1], "\"\""))
		{
			ft_putchar_fd('=', 1);
			ft_putstr_fd(argv[1], 1);
		}
		else
		{
			ft_putchar_fd('=', 1);
			ft_putchar_fd('"', 1);
			ft_putstr_fd(argv[1], 1);
			ft_putchar_fd('"', 1);
		}
	}
	ft_putchar_fd('\n', 1);
	free_two_dimensional_array(argv);
}

static void	output_export(char **argv, t_vars *vars, int *i)
{
	while (vars->envp_copy[*i] != NULL)
	{
		output_export_item(argv, vars, i);
		*i = *i + 1;
	}
}

void		export_out(t_vars *vars, char **line)
{
	int		i;
	int		count;
	char	**argv;

	i = 1;
	count = 0;
	argv = NULL;
	ft_sort_str_arr(vars->envp_copy);
	if (line[i] != NULL && ft_strcmp(line[i], ""))
	{
		check_line_value(&line[i]);
		argv = &line[i];
		if (!check_valid_id(line[i]))
		{
			id_error(line[i]);
			vars->err_flag_export = 1;
			return ;
		}
		argv = check_duplicate(argv);
		update_envp(argv, vars);
		free_two_dimensional_array(argv);
	}
	else
		output_export(argv, vars, &i);
}
