/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:42:03 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/30 12:53:48 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_signals(int signal)
{
	signal = 0;
	write(1, "\b\b  \b\b", 6);
	write(1, "\n", 1);
	ft_putstr_fd("minishell>", 1);
}

void			ft_signal(int signal)
{
	signal = 0;
	write(1, "\b\b  \b\b", 6);
}

static void		init_vars(t_vars *vars)
{
	vars->count_call_pipe = 0;
	vars->flag_redirect = 0;
	errno = 0;
	g_error = 0;
	g_signal = 0;
	vars->count_pipe = 0;
	vars->count_redirect = 0;
	vars->err_flag = 0;
	vars->err_flag_export = 0;
	vars->cd_flag = 0;
	vars->arr_flags = NULL;
	vars->save_std_in = dup(0);
	vars->save_std_out = dup(1);
}

static void		main_res(t_vars *vars)
{
	int			i;
	char		*line;

	line = NULL;
	i = 0;
	while ((i = get_next_line(0, &line)) > 0)
	{
		if (ft_strlen(line) == 0)
			ft_putstr_fd("minishell>", 1);
		ft_parse_argument(line, vars);
		if (ft_strlen(line) != 0)
		{
			if (g_signal == 0)
				ft_putstr_fd("minishell>", 1);
			else
				g_signal = 0;
		}
		ptr_free(&line);
		line = NULL;
		vars->count_call_pipe = 0;
	}
}

int				main(int argc, char **argv, char **envp)
{
	t_vars		vars;
	char		*old_pwd[2];

	argc = 0;
	argv = NULL;
	init_vars(&vars);
	old_pwd[0] = "OLDPWD";
	old_pwd[1] = NULL;
	envp_copy(envp, &vars);
	ft_unset(&vars, old_pwd);
	ft_putstr_fd("minishell>", 1);
	signal(SIGINT, &ft_signals);
	signal(SIGQUIT, &ft_signal);
	main_res(&vars);
	return (0);
}
