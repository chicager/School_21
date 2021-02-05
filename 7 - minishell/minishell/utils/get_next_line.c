/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 22:00:24 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/29 20:03:33 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		func_for_free_dup(char **ptr, char *ptr2)
{
	char	*ptr_for_free;

	ptr_for_free = *ptr;
	*ptr = ft_strdup(ptr2);
	free(ptr_for_free);
	if (!ptr)
		return (-1);
	return (0);
}

static int		func_for_free_join(char **ptr, char *ptr2)
{
	char	*ptr_for_free;

	ptr_for_free = *ptr;
	*ptr = ft_strjoin(*ptr, ptr2);
	free(ptr_for_free);
	if (!ptr)
		return (-1);
	return (0);
}

static int		gnl_static(char **ptr_static, char **line, char **ptr)
{
	if ((*ptr = (ft_strchr(*ptr_static, '\n'))))
	{
		**ptr = '\0';
		if (func_for_free_join(&*line, *ptr_static) == -1)
			return (-1);
		(*ptr)++;
		if (func_for_free_dup(&*ptr_static, *ptr) == -1)
			return (-1);
	}
	else
	{
		if (func_for_free_join(&*line, *ptr_static) == -1)
			return (-1);
		func_for_free_dup(&*ptr_static, "\0");
	}
	return (0);
}

static int		gnl_read(int fd, char **ptr_static, char **line, char **ptr)
{
	char	*buf;
	int		i;

	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!*ptr && ((i = read(fd, buf, BUFFER_SIZE)) >= 0))
	{
		if (ft_check_line(i, *line))
			exit(g_error);
		buf[i] = '\0';
		if ((*ptr = ft_strchr(buf, '\n')))
		{
			**ptr = '\0';
			(*ptr)++;
			if (func_for_free_dup(&*ptr_static, *ptr) == -1)
				return (-1);
		}
		if (func_for_free_join(&*line, buf) == -1)
			return (-1);
	}
	free(buf);
	if (i > 1 || *ptr != NULL)
		return (0);
	return (i == 0 ? 1 : -1);
}

int				get_next_line(int fd, char **line)
{
	char		*ptr;
	static char	*ptr_static;
	int			flag;

	ptr = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	*line = ft_strdup("");
	if (ptr_static)
		if ((flag = gnl_static(&ptr_static, &*line, &ptr)) == -1)
			return (-1);
	if (!ptr)
		if ((flag = gnl_read(fd, &ptr_static, &*line, &ptr)) == -1)
			return (-1);
	if (ptr != NULL || flag == 0)
		return (1);
	else
	{
		if (ptr_static)
		{
			free(ptr_static);
			ptr_static = NULL;
		}
		return (0);
	}
}
