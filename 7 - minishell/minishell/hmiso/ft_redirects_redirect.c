/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirects_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:52:17 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/29 20:33:17 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		init_redir(t_redir *redir)
{
	redir->count_redirects = 0;
}

static void		redir_redir_res(t_redir *redir, t_conveyor *conveyor)
{
	while (conveyor->arr_redirection[redir->count_redirects] != NULL)
	{
		redir->fd = open(conveyor->arr_redirection[redir->count_redirects],
		O_RDONLY);
		if (redir->fd < 0)
		{
			ft_putstr_fd(conveyor->arr_redirection[redir->count_redirects], 2);
			ft_putstr_fd(": Permission denied\n", 2);
			break ;
		}
		redir->count_redirects++;
	}
	redir->count_redirects = 0;
	while (conveyor->arr_redirection2[redir->count_redirects] != NULL)
		redir->count_redirects++;
	redir->fd2 = open(conveyor->arr_redirection2[redir->count_redirects - 1],
	O_WRONLY | O_APPEND, 0666);
}

static void		redir_redir_res_2(t_redir *redir, t_conveyor *conveyor)
{
	init_redir(redir);
	redir_redir_res(redir, conveyor);
}

void			ft_redirects_redirect(t_conveyor *conveyor, t_vars *vars)
{
	t_redir redir;

	redir_redir_res_2(&redir, conveyor);
	if (redir.fd > 0 && redir.fd2 > 0)
	{
		redir.pid = fork();
		if (redir.pid == 0)
		{
			dup2(redir.fd, 0);
			dup2(redir.fd2, 1);
			if (checking_recoded_functions(conveyor->com_with_flags, vars))
				exit(0);
			if ((redir.status = execve(conveyor->command_path,
			conveyor->com_with_flags, vars->envp_copy)) == -1)
				exit(WEXITSTATUS(redir.status));
		}
		else if (redir.pid < 0)
			ft_putendl_fd("error", 2);
		else
		{
			waitpid(redir.pid, &redir.status, WUNTRACED);
			close(redir.fd);
			close(redir.fd2);
		}
	}
}
