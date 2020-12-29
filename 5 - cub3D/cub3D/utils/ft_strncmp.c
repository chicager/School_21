/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 19:57:54 by curreg            #+#    #+#             */
/*   Updated: 2020/10/16 19:40:43 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i] && --n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
