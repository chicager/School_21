/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 13:46:56 by hmiso             #+#    #+#             */
/*   Updated: 2020/11/29 19:57:52 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;
	unsigned char	sym;

	sym = (unsigned char)c;
	ptr = (unsigned char *)b;
	i = 0;
	while (len > i)
	{
		ptr[i] = sym;
		i++;
	}
	return (ptr);
}
