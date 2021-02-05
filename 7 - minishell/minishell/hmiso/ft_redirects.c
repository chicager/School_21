/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:34:44 by hmiso             #+#    #+#             */
/*   Updated: 2021/02/05 23:22:59 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	init_redir(t_redir *redir)
{
	redir->status = 0;
	redir->fd = 0;
	redir->count_redirects = 0;
}

static void	redir_res(t_redir *redir)
{
	waitpid(redir->pid, &redir->status, WUNTRACED);
	if (redir->status == 2)
	{
		g_signal = 1;
		g_error = 130;
	}
	if (redir->status == 3)
	{
		ft_putstr_fd("^\\Quit: 3\n", 1);
		g_error = 131;
	}
}

static void	redir_res_2(t_redir *redir, t_vars *vars, char **command)
{
	if (WIFEXITED(redir->status))
	{
		if (WEXITSTATUS(redir->status))
		{
			if (redir->status == 256 || errno == 13 || errno == 2)
			{
				vars->err_flag = 1;
				g_error = 1;
				errno = 0;
			}
			if (redir->status != 256 && redir->status != 16384)
				command_error(command[0], vars);
		}
		else
		{
			vars->err_flag = 0;
			vars->cd_flag = 0;
			g_error = 0;
		}
	}
}

static void	redir_res_3(t_redir *redir, t_vars *vars,
							char **command, char *path)
{
	dup2(redir->fd, 1);
	if (checking_recoded_functions(command, vars))
		exit(0);
	if ((redir->status = execve(path, command, vars->envp_copy)) == -1)
		exit(WEXITSTATUS(redir->status));
}

void		ft_redirects(char *path, char **command,
char **arr_redirection, t_vars *vars)
{
	t_redir redir;

	init_redir(&redir);
	while (arr_redirection[redir.count_redirects] != NULL)
		redir.count_redirects++;
	redir.fd = open(arr_redirection[redir.count_redirects - 1],
	O_WRONLY | O_APPEND, 0666);
	if (redir.fd > 0)
	{
		redir.pid = fork();
		if (redir.pid == 0)
			redir_res_3(&redir, vars, command, path);
		else if (redir.pid < 0)
			ft_putendl_fd("error", 2);
		else
		{
			waitpid(redir.pid, &redir.status, WUNTRACED);
			redir_res(&redir);
			redir_res_2(&redir, vars, command);
			close(redir.fd);
		}
	}
}
