/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:21:33 by curreg            #+#    #+#             */
/*   Updated: 2020/11/01 13:04:31 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm_bonus.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		list_size(t_list *lst)
{
	int		count;
	t_list	*tmp;

	tmp = lst;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

t_list	*list_new(void *data)
{
	t_list		*lst;

	if (!(lst = malloc(sizeof(t_list))))
		return (NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

void	list_add_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!alst || !new)
		return ;
	if (*alst)
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*alst = new;
}

int		list_size_test(int lst_num)
{
	t_list	*list;

	list = NULL;
	while (lst_num--)
		list_add_back(&list, list_new(&lst_num));
	if (list_size(list) == ft_list_size(list))
		printf("OK\n");
	else
		printf("KO\n");
	return (1);
}

int		list_push_front_test(void *new)
{
	t_list	*list;

	list = NULL;
	list_add_back(&list, list_new("new one"));
	list_add_back(&list, list_new("one more"));
	ft_list_push_front(&list, new);
	if (!new && !list->data)
	{
		printf("OK\n");
		return (0);
	}
	if (!strcmp(list->data, (char*)new))
		printf("OK\n");
	else
		printf("KO\n");
	return (1);
}

int		main(void)
{
	printf("\n================================\n");
	printf("========= FT_LIST_SIZE =========\n");
	printf("================================\n\n");
	printf("ft_list_size : ");
	list_size_test(0);
	printf("ft_list_size : ");
	list_size_test(8);
	printf("ft_list_size : ");
	list_size_test(1);
	printf("ft_list_size : ");
	list_size_test(16);

	printf("\n================================\n");
	printf("====== FT_LIST_PUSH_FRONT ======\n");
	printf("================================\n\n");
	printf("ft_push_front : ");
	list_push_front_test(strdup("test"));
	printf("ft_push_front : ");
	list_push_front_test(strdup(""));
	printf("ft_push_front : ");
	list_push_front_test(strdup("one more string"));
	printf("ft_push_front : ");
	list_push_front_test(NULL);
}