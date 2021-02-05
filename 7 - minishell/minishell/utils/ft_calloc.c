/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 08:17:17 by student           #+#    #+#             */
/*   Updated: 2020/11/29 19:49:48 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_calloc(size_t nam, size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(size * nam);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size * nam);
	return (ptr);
}
