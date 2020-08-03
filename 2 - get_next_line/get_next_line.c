/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:10:54 by curreg            #+#    #+#             */
/*   Updated: 2020/07/23 21:34:45 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	int			i;
	int			len;
	char		*str;

	len = 0;
	while (src[len])
		len++;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i <= len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*find_remnant(char **remnant, char **line)
{
	char	*ptr_n;

	ptr_n = NULL;
	if (*remnant)
	{
		if ((ptr_n = ft_strchr(*remnant, '\n')))
		{
			*ptr_n = '\0';
			*line = ft_strdup(*remnant);
			ft_strcpy(*remnant, ++ptr_n);
		}
		else
		{
			*line = *remnant;
			*remnant = NULL;
		}
	}
	else
		*line = ft_strnew(1);
	return (ptr_n);
}

void	search_n(char **ptr_n, char **remnant, char *buf)
{
	char	*tmp;

	if ((*ptr_n = ft_strchr(buf, '\n')))
	{
		*(*ptr_n) = '\0';
		(*ptr_n)++;
		tmp = *remnant;
		*remnant = ft_strdup(*ptr_n);
		free(tmp);
	}
}

int		get_next_line(int fd, char **line)
{
	static char *remnant;
	char		buf[BUFFER_SIZE + 1];
	int			byte_read;
	char		*ptr_n;
	char		*tmp;

	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	ptr_n = find_remnant(&remnant, line);
	while (!ptr_n && (byte_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (byte_read == -1)
		{
			free(*line);
			*line = NULL;
			return (-1);
		}
		buf[byte_read] = '\0';
		search_n(&ptr_n, &remnant, buf);
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free(tmp);
	}
	return (ptr_n ? 1 : 0);
}
