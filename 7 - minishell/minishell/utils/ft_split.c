/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 11:10:02 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/29 20:01:48 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t	count_array(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	count_del;

	i = 0;
	count = 0;
	count_del = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count_del = 0;
		else if (count_del == 0)
		{
			count_del = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char		**free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char		**greyt_str(char const *s, char c, char **arr, size_t count)
{
	size_t	i;
	size_t	count_arr;
	size_t	count_str;

	i = 0;
	count_arr = 0;
	count_str = 0;
	while (s[i] != '\0' && count_arr < count)
	{
		while (s[i] == c)
			i++;
		while (s[i + count_str] != c && s[i + count_str] != '\0')
			count_str++;
		arr[count_arr] = (char*)malloc(sizeof(char) * (count_str + 1));
		if (!arr[count_arr])
			return (free_arr(arr));
		ft_strlcpy(arr[count_arr], &s[i], count_str + 1);
		i = i + count_str;
		count_arr++;
		count_str = 0;
	}
	return (arr);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	j;
	char	**arr;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	count = count_array(s, c);
	arr = (char**)malloc(sizeof(char*) * (count + 1));
	if (!arr)
		return (NULL);
	arr[count] = NULL;
	arr = greyt_str(s, c, arr, count);
	return (arr);
}
