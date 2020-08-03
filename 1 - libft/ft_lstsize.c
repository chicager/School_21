/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 06:09:38 by curreg            #+#    #+#             */
/*   Updated: 2020/05/25 19:56:40 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*head;
	int		size;

	size = 0;
	head = lst;
	if (!head)
		return (0);
	else
	{
		while (head)
		{
			size++;
			head = head->next;
		}
		return (size);
	}
}
