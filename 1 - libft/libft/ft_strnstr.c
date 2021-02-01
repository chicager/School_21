/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 01:19:48 by curreg            #+#    #+#             */
/*   Updated: 2020/05/25 19:58:02 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	if (!*s2)
		return ((char *)s1);
	while (*s1 && len > 0)
	{
		if (*s1 == *s2)
			if (ft_memcmp(s1, s2, ft_strlen(s2)) == 0 && len >= ft_strlen(s2))
				return ((char *)s1);
		s1++;
		len--;
	}
	return (NULL);
}
