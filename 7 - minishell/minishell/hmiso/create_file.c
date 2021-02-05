/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:19:31 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/28 19:27:03 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		create_file_res(char **command_line, int *arr_flags,
int fd, int i)
{
	if (ft_strncmp(command_line[i], ">", 2) == 0
	&& command_line[i + 1] != NULL && arr_flags[i] == 0)
	{
		fd = open(command_line[i + 1], O_WRONLY | O_TRUNC | O_CREAT, 0666);
		if (fd == -1)
		{
			ft_putstr_fd(command_line[i + 1], 2);
			ft_putstr_fd(": Permission denied\n", 2);
			return (1);
		}
		close(fd);
	}
	return (0);
}

static int		create_file_res_2(char **command_line, int *arr_flags,
int fd, int i)
{
	if (ft_strncmp(command_line[i], "<", 2) == 0
	&& command_line[i + 1] != NULL && arr_flags[i] == 0)
	{
		fd = open(command_line[i + 1], O_RDONLY);
		if (fd == -1)
		{
			return (1);
		}
		close(fd);
	}
	return (0);
}

void			create_file(char **command_line, int *arr_flags)
{
	int		i;
	int		fd;

	fd = 0;
	i = 0;
	while (command_line[i] != NULL)
	{
		if (create_file_res(command_line, arr_flags, fd, i) == 1)
			break ;
		if (create_file_res_2(command_line, arr_flags, fd, i) == 1)
			break ;
		if (ft_strncmp(command_line[i], ">>", 3) == 0
		&& command_line[i + 1] != NULL && arr_flags[i] == 0)
		{
			fd = open(command_line[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
			if (fd == -1)
			{
				ft_putstr_fd(command_line[i + 1], 2);
				ft_putstr_fd(": Permission denied\n", 2);
				break ;
			}
			close(fd);
		}
		i++;
	}
}
