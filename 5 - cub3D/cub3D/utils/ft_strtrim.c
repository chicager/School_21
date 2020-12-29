/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 03:24:30 by curreg            #+#    #+#             */
/*   Updated: 2020/10/16 19:40:45 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i >= 0 && ft_strchr(set, s1[i]))
		i--;
	dest = ft_substr(s1, 0, i + 1);
	return (dest);
}
