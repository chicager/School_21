/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_of_tokens.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:08:39 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/29 18:40:49 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	part_vt(t_vt_vars *vt, t_vars *vars, char **command_line)
{
	while (command_line[vt->i + 1] != NULL &&
			ft_strncmp(command_line[vt->i], "|", 2) != 0 &&
			vars->arr_flags[vt->i] == 0)
		vt->i++;
	if ((vt->i == 0 && ft_strncmp(command_line[vt->i], "|", 2) == 0) &&
			vars->arr_flags[vt->i] == 0)
	{
		syntax_error("|");
		free_two_dimensional_array(command_line);
		return (1);
	}
	if (command_line[vt->i + 1] != NULL && ((vt->i >= 1 &&
		ft_strncmp(command_line[vt->i], "|", 2) == 0) &&
		ft_strncmp(command_line[vt->i + 1], "|", 2) == 0 &&
		vars->arr_flags[vt->i + 1] == 0 && vars->arr_flags[vt->i] == 0))
	{
		syntax_error("|");
		free_two_dimensional_array(command_line);
		return (1);
	}
	return (0);
}

static int	part2_vt(t_vt_vars *vt, t_vars *vars, char **command_line)
{
	while (command_line[vt->i + 1] != NULL)
	{
		if (ft_strncmp(command_line[vt->i], ">", 2) == 0)
			break ;
		if (ft_strncmp(command_line[vt->i], ">>", 3) == 0)
			break ;
		if (ft_strncmp(command_line[vt->i], "<", 2) == 0)
			break ;
		vt->i++;
	}
	if (command_line[vt->i + 1] != NULL && vt->i >= 1 &&
		(ft_strncmp(command_line[vt->i + 1], ">", 2) == 0 ||
		ft_strncmp(command_line[vt->i + 1], "<", 2) == 0 ||
		ft_strncmp(command_line[vt->i + 1], ">>", 2) == 0) &&
		vars->arr_flags[vt->i + 1] == 0 && vars->arr_flags[vt->i] == 0)
	{
		syntax_error(">");
		free_two_dimensional_array(command_line);
		return (1);
	}
	return (0);
}

static int	part3_vt(t_vt_vars *vt, t_vars *vars, char **command_line)
{
	if (ft_strncmp(command_line[0], "<", 2) == 0 && vars->arr_flags[0] == 0)
	{
		vt->fd = open(command_line[1], O_RDONLY);
		if (vt->fd > 0)
		{
			free_two_dimensional_array(command_line);
			return (1);
		}
		else
		{
			ft_putstr_fd("minishell> ", 2);
			ft_putstr_fd(command_line[1], 2);
			ft_putstr_fd(" No such file or directory\n", 2);
			free_two_dimensional_array(command_line);
			return (1);
		}
	}
	if (ft_strncmp("|", command_line[vt->i], 2) == 0
					&& vars->arr_flags[vt->i] == 0)
	{
		free_two_dimensional_array(command_line);
		syntax_error("newline");
		return (1);
	}
	return (0);
}

char		**verification_of_tokens(char **command_line, t_vars *vars)
{
	t_vt_vars vt;

	ft_memset(&vt, 0, sizeof(t_vt_vars));
	if (part_vt(&vt, vars, command_line))
		return (NULL);
	vt.i = 0;
	if (part2_vt(&vt, vars, command_line))
		return (NULL);
	vt.i = 0;
	while (command_line[vt.i + 1] != NULL)
		vt.i++;
	if ((ft_strncmp(">", command_line[vt.i], 2) == 0 ||
					ft_strncmp(">>", command_line[vt.i], 3) == 0 ||
					ft_strncmp("<", command_line[vt.i], 3) == 0) &&
					vars->arr_flags[vt.i] == 0)
	{
		syntax_error("newline");
		free_two_dimensional_array(command_line);
		return (NULL);
	}
	if (part3_vt(&vt, vars, command_line))
		return (NULL);
	return (command_line);
}
