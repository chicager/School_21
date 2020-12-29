/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:28:30 by curreg            #+#    #+#             */
/*   Updated: 2020/10/16 19:43:49 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*list;

	list = *lst;
	if (lst != NULL)
	{
		while (list)
		{
			tmp = list->next;
			(*del)(list->content);
			free(list);
			list = tmp;
		}
	}
	*lst = NULL;
}
