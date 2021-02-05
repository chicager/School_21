/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 23:24:29 by curreg            #+#    #+#             */
/*   Updated: 2020/11/29 20:00:16 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_get_arr_length(char **arr)
{
	int i;
	int length;

	i = 0;
	length = 0;
	while (arr[i] != NULL)
	{
		length++;
		i++;
	}
	return (length);
}

void		ft_sort_str_arr(char **arr)
{
	int		i;
	int		j;
	int		length;
	char	*temp;

	i = 0;
	j = 0;
	temp = NULL;
	length = ft_get_arr_length(arr);
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (ft_strcmp(arr[i], arr[j]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}
