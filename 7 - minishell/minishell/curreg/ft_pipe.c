/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:53:09 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/28 21:18:54 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_exit(char *path, char **command, t_vars *vars, int *status)
{
	if (checking_recoded_functions(command, vars))
		return (0);
	else if ((*status = execve(path, command, vars->envp_copy)) == -1)
		return (WEXITSTATUS(*status));
	return (0);
}

void		ft_pipe(char *path, char **command, t_vars *vars)
{
	pid_t	pid;
	int		arr[2];
	int		status;
	int		i;

	i = 0;
	status = 0;
	pipe(arr);
	pid = fork();
	if (pid == 0)
	{
		close(arr[0]);
		dup2(arr[1], 1);
		close(arr[1]);
		exit(get_exit(path, command, vars, &status));
	}
	else if (pid < 0)
		ft_putendl_fd("error", 2);
	else
	{
		close(arr[1]);
		dup2(arr[0], 0);
		close(arr[0]);
		waitpid(pid, &status, WUNTRACED);
	}
}
