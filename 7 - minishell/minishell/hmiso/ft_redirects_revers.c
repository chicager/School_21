/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirects_revers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:48:28 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/29 15:14:48 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	init_redir(t_redir *redir)
{
	redir->status = 0;
	redir->fd = 0;
	redir->count_redirects = 0;
}

static void	redirects_revers_res(t_conveyor *conveyor, t_redir *redir)
{
	while (conveyor->arr_redirection[redir->count_redirects] != NULL)
	{
		redir->fd = open(conveyor->arr_redirection[redir->count_redirects],
		O_RDONLY);
		if (redir->fd < 0)
		{
			ft_putstr_fd("minishell>", 2);
			ft_putstr_fd(conveyor->arr_redirection[redir->count_redirects], 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
			break ;
		}
		redir->count_redirects++;
	}
}

static void	redirects_revers_res_2(t_conveyor *conveyor,
t_redir *redir, t_vars *vars)
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
				command_error(conveyor->com_with_flags[0], vars);
		}
		else
		{
			vars->err_flag = 0;
			vars->cd_flag = 0;
			g_error = 0;
		}
	}
}

static void	redirects_revers_res_3(t_redir *redir)
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

void		ft_redirects_revers(t_conveyor *conveyor, t_vars *vars)
{
	t_redir redir;

	init_redir(&redir);
	redirects_revers_res(conveyor, &redir);
	if (redir.fd > 0)
	{
		redir.pid = fork();
		if (redir.pid == 0)
		{
			dup2(redir.fd, 0);
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
			redirects_revers_res_3(&redir);
			redirects_revers_res_2(conveyor, &redir, vars);
			close(redir.fd);
		}
	}
}
