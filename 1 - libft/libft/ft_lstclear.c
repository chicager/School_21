/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 06:27:11 by curreg            #+#    #+#             */
/*   Updated: 2020/05/25 19:55:39 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*latest;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	latest = *lst;
	while (latest)
	{
		next = latest->next;
		ft_lstdelone(latest, del);
		latest = next;
	}
	*lst = NULL;
}
