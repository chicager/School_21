/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirects_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:49:25 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/30 12:24:13 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	redirects_pipe(char **arr_redirection, int *fd)
{
	int count_redirects;

	count_redirects = 0;
	while (arr_redirection[count_redirects + 1] != NULL)
	{
		*fd = open(arr_redirection[count_redirects], O_RDONLY);
		if (*fd < 0)
		{
			ft_putstr_fd(arr_redirection[count_redirects], 2);
			ft_putstr_fd(": Permission denied\n", 2);
			break ;
		}
		count_redirects++;
		close(*fd);
	}
	*fd = open(arr_redirection[count_redirects], O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr_fd(arr_redirection[count_redirects], 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
}

static void	redirects_pipe_res(int *arr, int status, pid_t pid, int fd)
{
	close(arr[1]);
	dup2(fd, 0);
	dup2(arr[0], 0);
	close(arr[0]);
	waitpid(pid, &status, WUNTRACED);
	close(fd);
}

static void	redirects_pipe_res_2(int *arr, int fd, char **command, t_vars *vars)
{
	close(arr[0]);
	dup2(fd, 0);
	dup2(arr[1], 1);
	close(arr[1]);
	if (checking_recoded_functions(command, vars))
		exit(0);
}

void		ft_redirects_pipe(char *path, char **command,
char **arr_redirection, t_vars *vars)
{
	pid_t	pid;
	int		arr[2];
	int		status;
	int		fd;

	status = 0;
	redirects_pipe(arr_redirection, &fd);
	if (fd > 0)
	{
		pipe(arr);
		pid = fork();
		if (pid == 0)
		{
			redirects_pipe_res_2(arr, fd, command, vars);
			if ((status = execve(path, command, vars->envp_copy)) == -1)
				exit(WEXITSTATUS(status));
		}
		else if (pid < 0)
			ft_putendl_fd("error", 2);
		else
			redirects_pipe_res(arr, status, pid, fd);
	}
	else
		ft_pipe_eof();
}
