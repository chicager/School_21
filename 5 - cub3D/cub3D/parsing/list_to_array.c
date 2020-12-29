/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:27:27 by curreg            #+#    #+#             */
/*   Updated: 2020/10/18 20:04:22 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char			**list_to_array(int size, t_list **tmp)
{
	int		i;
	char	**map;
	t_list	*list;

	if (!(map = ft_calloc(size + 1, sizeof(char *))))
		put_error("Error\nMalloc error occured!\n");
	i = 0;
	list = *tmp;
	while (list)
	{
		map[i] = ft_strdup(list->content);
		if (map[i] == NULL)
			put_error("Error\nMalloc error occured!\n");
		list = list->next;
		i++;
	}
	map[i] = NULL;
	i = 0;
	ft_lstclear(tmp, free);
	return (map);
}
