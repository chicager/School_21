/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:28:38 by curreg            #+#    #+#             */
/*   Updated: 2020/10/16 19:43:43 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

int	ft_lstsize(t_list *lst)
{
	int		sum;
	t_list	*list;

	list = lst;
	sum = 0;
	if (lst != NULL)
	{
		while (list)
		{
			list = list->next;
			sum++;
		}
	}
	return (sum);
}
