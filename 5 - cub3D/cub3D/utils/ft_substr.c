/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:15:18 by curreg            #+#    #+#             */
/*   Updated: 2020/10/20 21:29:47 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

char	*ft_substr(char const *s, int start, size_t len)
{
	char	*sub_str;
	size_t	sub_len;

	if (!s || s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	sub_len = ft_strlen(s + start);
	if (sub_len < len)
		len = sub_len;
	if (!(sub_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
