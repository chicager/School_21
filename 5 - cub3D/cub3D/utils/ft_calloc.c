/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:28:21 by curreg            #+#    #+#             */
/*   Updated: 2020/10/16 19:43:35 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

void	*ft_calloc(size_t nam, size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(size * nam);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size * nam);
	return (ptr);
}
