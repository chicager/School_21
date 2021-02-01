/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchcount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:07:50 by curreg            #+#    #+#             */
/*   Updated: 2020/08/04 15:15:14 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_findchcount(char *str, char c)
{
	size_t count;
	size_t length;

	count = 0;
	length = ft_strlen(str);
	while (length--)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}
